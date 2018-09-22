// mapped needs this
`include "alu_if.vh"

// mapped timing needs this. 1ns is too fast
`timescale 1 ns / 1 ns

module alu_tb;
  parameter PERIOD = 10;
  import cpu_types_pkg::*;
  logic CLK = 0;

  // clock
  always #(PERIOD/2) CLK++;

  // interface
  alu_if aluif ();
  // test program
  test PROG (.CLK) ;
  // DUT
`ifndef MAPPED
  alu DUT(aluif);
`else
  alu DUT(
    .\aluif.port_a (aluif.port_a),
    .\aluif.port_b (aluif.port_b),
    .\aluif.aluop (aluif.aluop),
    .\aluif.output_port (aluif.output_port),
    .\aluif.negative (aluif.negative),
    .\aluif.zero (aluif.zero),
    .\aluif.overflow (aluif.overflow)
  );
`endif

endmodule

program test(
  input logic CLK
);
  import cpu_types_pkg::*;
  parameter PERIOD = 10;
  initial begin
    //initial values for inputs
    #(PERIOD);
    aluif.port_a = 32'd200;
    aluif.port_b = 32'd4;
    //sll
    aluif.aluop = ALU_SLL;
    #(PERIOD);
    aluif.port_a = 32'd200;
    aluif.port_b = 32'd4;
    //srl
    aluif.aluop = ALU_SRL;
    #(PERIOD);
    aluif.port_a = -2;
    aluif.port_b =  2;
    //add, test zero flag
    aluif.aluop = ALU_ADD;
    #(PERIOD);
    aluif.port_a = 32'b 01111111111111111111111111111111;
    aluif.port_b = 32'd1;
    //add, test 
    aluif.aluop = ALU_ADD;
    #(PERIOD);
    //sub
    aluif.aluop = ALU_SUB;
    #(PERIOD);
    //and
    aluif.aluop = ALU_AND;
    #(PERIOD);
    //or
    aluif.aluop = ALU_OR;
    #(PERIOD);
    //xor
    aluif.aluop = ALU_XOR;
    #(PERIOD);
    //nor
    aluif.aluop = ALU_NOR;
    #(PERIOD);
    //slt
    aluif.aluop = ALU_SLT;
    #(PERIOD);
    //sltu
    aluif.aluop = ALU_SLTU;
    #(PERIOD);
  end // initial
endprogram
