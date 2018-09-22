`include "cpu_types_pkg.vh"
import cpu_types_pkg::*;

module control_unit (
  input logic CLK, nRST, 
  input logic [31:0] imemload,
  output logic jmp, jmpr, j_al, b_eq, b_ne, rf_write, alu_src, reg_dst, extend_sign, dREN, dWEN,
  output aluop_t alu_op,
  output logic memtoreg, hlt, l_ui
);
  // type import
//string operation = "";

  //logic [5:0] op  = '0;
  //logic [5:0] funct = '0;
  //logic [3:0] op = '0;

  always_comb
  begin
    jmp = 0;
    jmpr = 0;
    j_al = 0;
    b_eq = 0;
    b_ne = 0;
    rf_write = 0;
    alu_src = 0;
    reg_dst = 0;
    alu_op = ALU_ADD;
    memtoreg = 0;
    hlt = 0;
    l_ui = 0;
    extend_sign = 0;
    dREN = 0;
    dWEN = 0;
    
  	casez(imemload [31:26]) 
      RTYPE : begin
        reg_dst = 1;  //write to rd
        rf_write = 1; //write enable
        alu_src = 0;  //source ALU from reg or imm
        memtoreg = 0;
        extend_sign = 0;
        casez(imemload [5:0]) 
          ADD : begin
            alu_op = ALU_ADD;
          end
          ADDU : begin
            alu_op = ALU_ADD;
          end
          AND : begin
            alu_op = ALU_AND;
          end
          JR : begin
            alu_op = ALU_ADD;
            rf_write = 0;
            jmpr = 1;
          end
          NOR : begin
            alu_op = ALU_NOR;
          end
          OR : begin
            alu_op = ALU_OR;
          end
          SLLV : begin
            alu_op = ALU_SLL;
          end
          SRLV : begin
            alu_op = ALU_SRL;
          end
          SLT : begin
            alu_op = ALU_SLT;
          end
          SLTU : begin
            alu_op = ALU_SLTU;
          end
          SUB : begin
            alu_op = ALU_SUB;
          end
          SUBU : begin
            alu_op = ALU_SUB;
          end
          XOR : begin
            alu_op = ALU_XOR;
          end
        endcase
      end
      J : begin
        jmp = 1;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 0;
        alu_src = 0;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 1;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      JAL : begin
        jmp = 1;
        jmpr = 0;
        j_al = 1;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 0;
        reg_dst = 1;
        alu_op = ALU_ADD;
        memtoreg = 1;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      BEQ : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 1;
        b_ne = 0;
        rf_write = 0;
        alu_src = 0;
        reg_dst = 0;
        alu_op = ALU_SUB;
        memtoreg = 1;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      BNE : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 1;
        rf_write = 0;
        alu_src = 0;
        reg_dst = 0;
        alu_op = ALU_SUB;
        memtoreg = 1;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      ADDI : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      ADDIU : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0; 
        extend_sign = 1;
      end
      SLTI : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_SLT;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      SLTIU : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_SLTU;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;
        extend_sign = 1;
      end
      ANDI : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_AND;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;
        extend_sign = 0;
      end
      ORI : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_OR;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;
        extend_sign = 0;
      end
      XORI : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_XOR;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;
        extend_sign = 0;
      end
      LUI : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 0;
        hlt = 0;
        l_ui = 1;
        extend_sign = 1;
      end
      LW : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 1;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 1;
        hlt = 0;
        l_ui = 0;  
        extend_sign = 1;
        dREN = 1;
      end
      /*
      LBU : begin
        
      end
      LHU : begin
            
      end
      SB : begin
            
      end
      SH : begin
            
      end*/
      SW : begin
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 0;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 0;
        hlt = 0;
        l_ui = 0;  
        extend_sign = 1;
        dWEN = 1;
      end
      HALT : begin
        //operation = "HALT";
        jmp = 0;
        jmpr = 0;
        j_al = 0;
        b_eq = 0;
        b_ne = 0;
        rf_write = 0;
        alu_src = 1;
        reg_dst = 0;
        alu_op = ALU_ADD;
        memtoreg = 0;
        hlt = 1;
        l_ui = 0; 
        extend_sign = 1;
      end
    endcase
  end
endmodule