/*
  Eric Villasenor
  evillase@gmail.com

  register file test bench
*/

// mapped needs this
`include "register_file_if.vh"

// mapped timing needs this. 1ns is too fast
`timescale 1 ns / 1 ns

module register_file_tb;

  parameter PERIOD = 10;

  logic CLK = 0, nRST;

  // test vars
  logic [31:0] v1 = 1;
  logic [31:0] v2 = 4721;
  logic [31:0] v3 = 25119;

  // clock
  always #(PERIOD/2) CLK++;

  // interface
  register_file_if rfif ();
  // test program
  test PROG (.CLK, .nRST, .v1, .v2, .v3);
  // DUT
`ifndef MAPPED
  register_file DUT(CLK, nRST, rfif);
`else
  register_file DUT(
    .\rfif.rdat2 (rfif.rdat2),
    .\rfif.rdat1 (rfif.rdat1),
    .\rfif.wdat (rfif.wdat),
    .\rfif.rsel2 (rfif.rsel2),
    .\rfif.rsel1 (rfif.rsel1),
    .\rfif.wsel (rfif.wsel),
    .\rfif.WEN (rfif.WEN),
    .\nRST (nRST),
    .\CLK (CLK)
  );
`endif

endmodule

program test(
  input logic CLK, [31:0] v1, [31:0] v2, [31:0] v3,
  output logic nRST);
  parameter PERIOD = 10;
  initial begin
    //initial values for inputs
    nRST = 1;
    rfif.wdat = '0;
    rfif.rsel1 = '0;
    rfif.rsel2 = '0;
    rfif.WEN = 0;
    rfif.wsel = '0;

    #(PERIOD);
    //test async reset
    nRST = 0;
    #(PERIOD);

    //test write to reg 0
    #(PERIOD);
    nRST = 1;
    rfif.WEN = 1;
    rfif.wsel = '0;
    rfif.wdat = '1;
    #(PERIOD);
    
    //verify write and read to regs
    rfif.wsel = 'h13;
    rfif.wdat = 'h15;
    #(PERIOD);
    //check reg for change here
    rfif.wsel = 'h15;
    rfif.wdat = 'h27;
    #(PERIOD);
    #(PERIOD);
    //try to read from written-to registers
    rfif.WEN = 0;
    rfif.rsel1 = 'h13;
    rfif.rsel2 = 'h15;
    #(PERIOD);
  end // initial
endprogram
