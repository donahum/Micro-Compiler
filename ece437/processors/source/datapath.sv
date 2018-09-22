/*
  Eric Villasenor
  evillase@gmail.com

  datapath contains register file, control, hazard,
  muxes, and glue logic for processor
*/

// data path interface
`include "datapath_cache_if.vh"

`include "ifid_if.vh"
`include "idex_if.vh"
`include "exmem_if.vh"
`include "memwb_if.vh"
// alu op, mips op, and instruction type
`include "cpu_types_pkg.vh"

module datapath (
  input logic CLK, nRST,
  datapath_cache_if.dp dpif
);
  // import types
  import cpu_types_pkg::*;

  // pc init
  parameter PC_INIT = 0;

    i_t itype;
    j_t jtype;
    r_t rtype;

    assign itype = dpif.imemload;
    assign jtype = dpif.imemload;
    assign rtype = dpif.imemload;

    //ifid variables
    logic ihit, dhit;
    assign ihit = dpif.ihit;
    assign dhit = dpif.dhit;
    logic [31:0] pc, pcIF, instrIF, instrEXMEM;
    logic [4:0] rsIF, rtIF, rdIF;
    logic [15:0] immIF;
    //ifid assigns
    assign ifidif.instr = dpif.imemload;
    assign ifidif.pc = pc;
    //instruction interface latch
    ifid_if ifidif();
    ifid ifidLatch(
      .CLK(CLK),.nRST(nRST),.ihit(ihit),
      .ifidif(ifidif)
    );

    //idex
    //idex variables
    logic jmp, b_eq, b_ne, alu_src, halt, dREN, dWEN, l_ui, extend_sign, jmpr, j_al, rf_write, reg_dst, memtoreg;
    logic [31:0] instrDEC, rdat1, rdat2;
    //initializations
    aluop_t op;

    control_unit controller(.CLK(CLK), .nRST(nRST), .imemload(ifidif.instr), .jmp(jmp), .jmpr(jmpr), .j_al(j_al), .b_eq(b_eq), .b_ne(b_ne), .rf_write(rf_write), .alu_src(alu_src), .reg_dst(reg_dst), .extend_sign(extend_sign), .memtoreg(memtoreg), .dREN(dREN), .dWEN(dWEN), .alu_op(op), .hlt(halt), .l_ui(l_ui));
    register_file_if rfif();

    //control_unit controller(.CLK(CLK), .nRST(nRST), .imemload(dpif.imemload), .jmp(jmp), .jmpr(jmpr), .j_al(j_al), .b_eq(b_eq), .b_ne(b_ne), .rf_write(rf_write), .alu_src(alu_src), .reg_dst(reg_dst), .extend_sign(extend_sign), .alu_op(op), .halt(halt), .l_ui(l_ui));

    //reg file assigns
    //wsel and enable in write back
    assign rfif.rsel1 = ifidif.rsIF; 
    assign rfif.rsel2 = ifidif.rtIF;
    assign rfif.wdat = memwbif.j_alWB ? (memwbif.pcWB + 32'h4) : (memwbif.memtoregWB ? memwbif.resultWB : memwbif.resultWB);  //aluif.output_port //dmemload choo choo
    register_file rf(.CLK(CLK), .nRST(nRST), .rfif(rfif));
    
    idex_if idexif();

    //idex assigns   
    assign idexif.jmpDEC = jmp;
    assign idexif.reg_dstDEC = reg_dst;
    assign idexif.j_alDEC = j_al;
    assign idexif.jmprDEC = jmpr;
    assign idexif.b_neDEC = b_ne;
    assign idexif.b_eqDEC = b_eq;
    assign idexif.alu_srcDEC = alu_src;
    assign idexif.haltDEC = halt;
    assign idexif.dRENDEC = dREN;             //watch out here, sketch
    assign idexif.dWENDEC = dWEN;
    assign idexif.pcDEC = ifidif.pcIF;
    assign idexif.instrDEC = ifidif.instrIF;
    assign idexif.rf_writeDEC = rf_write;
    assign idexif.immDEC = ifidif.immIF;
    assign idexif.rdat1DEC = rfif.rdat1;
    assign idexif.rdat2DEC = rfif.rdat2;
    assign idexif.extend_signDEC = extend_sign;
    assign idexif.l_uiDEC = l_ui;
    assign idexif.opDEC = op;
    
    idex idexLatch(
      .CLK(CLK),.nRST(nRST),.ihit(ihit),
      .idexif(idexif)
    );

    logic [31:0] zero_extend, sign_extend, ex_imm, shifted_ex_imm, upper_imm;

    assign zero_extend = {16'b0000000000000000, idexif.immEX};
    assign sign_extend = idexif.immEX [15] ? {16'b1111111111111111, idexif.immEX} : {16'b0000000000000000, idexif.immEX};
    assign ex_imm = idexif.extend_signEX ? sign_extend : zero_extend;

    assign shifted_ex_imm = ex_imm << 2;
    assign upper_imm = {idexif.immEX, 16'b0000000000000000};

    alu_if aluif();
    //alu assigns
    assign aluif.port_a = idexif.rdat1EX;
    assign aluif.port_b = idexif.alu_srcEX ? (idexif.l_uiEX ? upper_imm : ex_imm) : idexif.rdat2EX;
    assign aluif.aluop = idexif.opEX;

    alu dalu (aluif);


    exmem_if exmemif();

    assign exmemif.zeroEX = aluif.zero;
    assign exmemif.resultEX = aluif.output_port;
    assign exmemif.b_eqEX = idexif.b_eqEX;
    assign exmemif.b_neEX = idexif.b_neEX;
    assign exmemif.dRENEX = idexif.dRENEX;
    assign exmemif.dWENEX = idexif.dWENEX;
    assign exmemif.rf_writeEX = idexif.rf_writeEX;
    assign exmemif.pcEX = idexif.pcEX;
    assign exmemif.instrEX = idexif.instrEX;
    assign exmemif.immEX = idexif.immEX;
    assign exmemif.rdat2EX = idexif.rdat2EX;
    assign exmemif.reg_dstEX = idexif.reg_dstEX;
    assign exmemif.j_alEX = idexif.j_alEX;
    assign exmemif.alu_srcEX = idexif.alu_srcEX;
    assign exmemif.rdat1EX = idexif.rdat1EX;
    assign exmemif.haltEX = idexif.haltEX;
    assign exmemif.jmpEX = idexif.jmpEX;
    assign exmemif.jmprEX = idexif.jmprEX;


    exmem exMemLatch (
      .CLK(CLK), .nRST(nRST), .ihit(ihit), .exmemif(exmemif) ,.dhit(dhit)
    );

    logic [31:0] npc;
    logic [31:0] pc_plus4;
    logic [31:0] pc_plus4_plusimm;
    logic b;
    logic [27:0] shifted_jaddr;

    

    memwb_if memwbif();
    assign memwbif.pcMEM = npc;
    assign memwbif.haltMEM = exmemif.haltMEM;
    assign memwbif.dWENMEM = exmemif.dWENMEM;
    assign memwbif.dRENMEM = exmemif.dRENMEM;
    assign memwbif.resultMEM = exmemif.resultMEM; //rtype itype
    assign memwbif.zeroMEM = exmemif.zeroMEM;
    assign memwbif.jmpMEM = exmemif.jmpMEM;
    assign memwbif.b_eqMEM = exmemif.b_eqMEM;
    assign memwbif.b_neMEM = exmemif.b_neMEM;
    assign memwbif.reg_dstMEM = exmemif.reg_dstMEM;
    assign memwbif.j_alMEM = exmemif.j_alMEM;
    assign memwbif.rf_writeMEM = exmemif.rf_writeMEM;
    assign memwbif.instrMEM = exmemif.instrMEM;
    assign memwbif.immMEM = exmemif.immMEM;
    assign memwbif.rdat2MEM = exmemif.rdat2MEM;

    //conditional
    //assign memwbif.resultWB = exmemif.resultMEM;//(exmemif.instrMEM[31:26] == 6'b100011) ? exmemif.resultMEM : (exmemif.instrMEM[31:26] == 6'b101011) : '0;

    memwb memwbLatch (
      .CLK(CLK), .nRST(nRST), .ihit(ihit), .dhit(dhit), .memwbif(memwbif)
    );

    always_comb 
    begin
        if(memwbif.j_alWB) begin
          rfif.wsel = 5'b11111;
        end else if(memwbif.reg_dstWB) begin
          rfif.wsel = memwbif.instrWB [15:11];
        end else begin
          rfif.wsel = memwbif.instrWB [20:16];
        end
    end

    always_comb
    begin
      pc_plus4 = exmemif.pcMEM + 32'h4;
      pc_plus4_plusimm = pc_plus4 + exmemif.immMEM;
      shifted_jaddr = ({2'b0, exmemif.instrMEM [25:0]} << 2);
      b = (exmemif.b_eqMEM && exmemif.zeroMEM) ^ (exmemif.b_neMEM && !exmemif.zeroMEM);

      if(b && ihit) begin
        npc = pc_plus4_plusimm;
      end else if(exmemif.jmprMEM && ihit) begin
        npc = exmemif.rdat1MEM;
      end else if(exmemif.jmpMEM && ihit) begin
        npc = {pc_plus4 [31:28], shifted_jaddr};
      end else if(ihit & !dhit) begin
        npc = pc_plus4;
      end else begin
        npc = exmemif.pcMEM;
      end

      /*
      if(b) begin
        npc = pc_plus4_plusimm;
      end else if(exmemif.jmprMEM) begin
        npc = exmemif.rdat1MEM;
      end else if(exmemif.jmpMEM) begin
        npc = {pc_plus4 [31:28], shifted_jaddr};
      end else if(ihit) begin
        npc = pc_plus4;
      end else begin
        npc = exmemif.pcMEM;
      end*/

    end

    always_ff @(posedge CLK, negedge nRST)
    begin
      if(!nRST) begin
        pc <= '0;
      end else if(ihit) begin
        pc <= npc;
      end
    end
/*
    always_ff @(posedge CLK, negedge nRST) begin
      if(~nRST) begin
         <= 0;
      end else if(dhit & ((memwbif.instrWB[31:26] == 6'b101011) | (memwbif.instrWB[31:26] == 6'b100011))) begin
         <= ;
      end
    end


*/

    //logic next_d_ren, next_d_wen;


/*
    always_comb begin
        if(dhit == 1'b1) begin
          dpif.dmemREN = 0;
          dpif.dmemWEN = 0;
        end
        else if(ihit == 1'b1) begin
          //enums for LW + SW from cpu_types_pkg
          if(memwbif.instrWB [31:26] == 6'b100011) begin //6'b100011 = LW
            dpif.dmemREN = 1;
          end
          else if (memwbif.instrWB [31:26] == 6'b101011) begin //6'b101011 = SW
            dpif.dmemWEN = 1;
          end
        end
        else begin
          dpif.dmemREN = memwbif.dRENWB;
          dpif.dmemWEN = memwbif.dWENWB;
        end
    end
*/
    assign rfif.WEN = memwbif.rf_writeWB;//mux
    //assign rfif.wdat
    assign dpif.halt = memwbif.haltWB;
    assign dpif.dmemaddr = memwbif.rdat2WB;
    assign dpif.imemaddr = pc;
    assign dpif.dmemstore = memwbif.rdat2WB;
    assign dpif.imemREN = 1;
    assign dpif.dmemREN = exmemif.dRENMEM;
    assign dpif.dmemWEN = exmemif.dWENMEM;
  //  assign dpif.dmemREN = next_d_ren;//(memwbif.dRENWB & !(memwbif.instrWB[31:26] == 6'b100011));
  //  assign dpif.dmemWEN = next_d_wen;//(memwbif.dWENWB & !(memwbif.instrWB[31:26] == 6'b101011));
endmodule
