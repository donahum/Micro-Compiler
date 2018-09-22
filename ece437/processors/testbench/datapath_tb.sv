`include "datapath_cache_if.vh"
`include "register_file_if.vh"
`include "alu_if.vh"

`include "cpu_ram_if.vh"

`timescale 1 ns / 1 ns

module datapath_tb;
  parameter PERIOD = 10;
  import cpu_types_pkg::*;
  logic CLK = 0;
  logic nRST;

  //controller i/o
  logic [31:0] tb_imemload;
  logic tb_jmp, tb_jmpr, tb_j_al, tb_b_eq, tb_b_ne, tb_rf_write, tb_alu_src, tb_reg_dst;
  aluop_t tb_alu_op;
  logic tb_memtoreg, tb_hlt, tb_l_ui;
  //request unit i/o
  logic tb_ihit, tb_dhit, tb_iREN, tb_dREN, tb_dWEN; 
  //alu i/o
  logic tb_zero, tb_overflow, tb_negative;
  logic [31:0] tb_port_a, tb_port_b, tb_output_port;
  //pc i/o
  logic [31:0] tb_imm;
  logic [25:0] tb_jaddr;
  logic [31:0] tb_lr;
  logic [31:0] tb_pc;

  // clock
  always #(PERIOD/2) CLK++;

  datapath_cache_if tb_dpif();
  register_file_if tb_rfif();
  alu_if tb_aluif();

  // test program
  test PROG (.CLK, .nRST, .tb_imemload, .tb_ihit);
  // DUT
`ifndef MAPPED
  datapath dp1(CLK, nRST, tb_dpif);
`else
  datapath dp1(
    
    .\CLK(CLK),
    .\nRST(nRST),
    //dp ports
    .\dpif.ihit(tb_dpif.ihit),
    .\dpif.imemload(tb_dpif.imemload),
    .\dpif.dhit(tb_dpif.dhit),
    .\dpif.dmemload(tb_dpif.dmemload),
    .\dpif.halt(tb_dpif.halt),
    .\dpif.imemREN(tb_dpif.imemREN),
    .\dpif.imemaddr(tb_dpif.imemaddr),
    .\dpif.dmemREN(tb_dpif.dmemREN),
    .\dpif.dmemWEN(tb_dpif.dmemWEN),
    .\dpif.datomic(tb_dpif.datomic),
    .\dpif.dmemstore(tb_dpif.dmemstore),
    .\dpif.dmemaddr(tb_dpif.dmemaddr)
  );
`endif

`ifndef MAPPED
  control_unit cu1(CLK, nRST, tb_imemload, tb_jmp, tb_jmpr, tb_j_al, tb_b_eq, tb_b_ne, tb_rf_write, tb_alu_src, tb_reg_dst, tb_alu_op, tb_memtoreg, tb_hlt, tb_l_ui);
`else
  control_unit cu1(
    .\CLK(CLK),
    .\nRST(nRST),
    //cu ports
    .\imemload(tb_imemload),
    .\jmp(tb_jmp),
    .\jmpr(tb_jmpr),
    .\j_al(tb_jal),
    .\b_eq(tb_b_eq),
    .\b_ne(tb_b_ne),
    .\rf_write(tb_rf_write),
    .\alu_src(tb_alu_src),
    .\reg_dst(tb_reg_dst),
    .\alu_op(tb_alu_op),
    .\memtoreg(tb_memtoreg),
    .\hlt(tb_hlt),
    .\l_ui(tb_l_ui)
  );
`endif

`ifndef MAPPED
  register_file rf1(CLK, nRST, tb_rfif);
`else
  register_file rf1(
    .\CLK(CLK),
    .\nRST(nRST),
    //rf ports
    .\rfif.WEN(tb_rf_write),
    .\rfif.wsel(tb_rfif.wsel),
    .\rfif.rsel1(tb_rfif.rsel1),
    .\rfif.rsel2(tb_rfif.rsel2),
    .\rfif.wdat(tb_rfif.wdat),
    .\rfif.rdat1(tb_rfif.rdat1),
    .\rfif.rdat2(tb_rfif.rdat2)
  );
`endif

`ifndef MAPPED
  request_unit rq(CLK, nRST, tb_ihit, tb_dhit, tb_hlt, tb_imemload, tb_iREN, tb_dREN, tb_dWEN);
`else
  request_unit rq(
    .\CLK(CLK),
    .\nRST(nRST),
    //rq ports
    .\ihit(tb_ihit),
    .\dhit(tb_dhit),
    .\halt(tb_hlt),
    .\imemload(tb_imemload),
    .\iREN(tb_iREN),
    .\dREN(tb_dREN),
    .\dWEN(tb_dWEN)
  );
`endif

`ifndef MAPPED
  alu alu1(tb_aluif);
`else
  alu alu1(
    //alu ports
    .\aluop(tb_alu_op),
    .\port_a(tb_port_a),
    .\port_b(tb_port_b),
    .\output_port(tb_output_port),
    .\overflow(tb_overflow),
    .\zero(tb_zero),
    .\negative(tb_negative)
  );
`endif

`ifndef MAPPED
  pc pc1(CLK, nRST, tb_ihit, tb_hlt, tb_jmpr, tb_zero, tb_b_eq, tb_b_ne, tb_imm, tb_jmp, tb_jaddr, tb_lr, tb_pc);
`else
  pc pc1(
    .\CLK(CLK),
    .\nRST(nRST),
    //pc ports
    .\ihit(tb_ihit),
    .\halt(tb_hlt),
    .\jr(tb_jmpr),
    .\zero(tb_zero),
    .\b_eq(tb_b_eq),
    .\b_ne(tb_b_ne),
    .\imm(tb_imm),
    .\jmp(tb_jmp),
    .\jaddr(tb_jaddr),
    .\lr(tb_lr),
    .\pc(tb_pc)
  );
`endif

  

endmodule

program test(
  input logic CLK, output logic nRST, output logic [31:0] tb_imemload, output logic tb_ihit
);
	import cpu_types_pkg::*;
	parameter PERIOD = 10;
  string testcase = "initial";
	initial begin
	  $display("Simulation Test - Donahue");
	  #(PERIOD);

	  $display("Performing nRST");
	  nRST = 0;
	  #(PERIOD);
    nRST = 1;
    #(PERIOD);

    tb_imemload = 'h8c220000;
    tb_ihit = 1;
    #(PERIOD);
    #(PERIOD);
    
	  
	end // initial
endprogram