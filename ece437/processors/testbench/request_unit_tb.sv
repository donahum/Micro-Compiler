`timescale 1 ns / 1 ns

module request_unit_tb;
	parameter PERIOD = 10;
	import cpu_types_pkg::*;
	//inputs
	logic tb_CLK = 0;
	logic tb_nRST, tb_ihit, tb_dhit;
	logic [31:0] tb_imemload;
	logic tb_halt;
	//outputs
	logic tb_iREN, tb_dREN, tb_dWEN;

	// clock
	always #(PERIOD/2) tb_CLK++;
 	// test program
	test PROG (.tb_CLK(tb_CLK), .tb_nRST(tb_nRST), .tb_ihit(tb_ihit), .tb_dhit(tb_dhit), .tb_halt(tb_halt), .tb_imemload(tb_imemload));
	// DUT
	`ifndef MAPPED
		request_unit DUT(tb_CLK, tb_nRST, tb_ihit, tb_dhit, tb_halt, tb_imemload, tb_iREN, tb_dREN, tb_dWEN);
	`else
		request_unit DUT(
	    .CLK(tb_CLK),
	    .nRST(tb_nRST),
	    .ihit(tb_ihit),
	    .dhit(tb_dhit),
	    .halt(tb_halt),
	    .imemload(tb_imemload),
	    .iREN(tb_iREN),
	    .dREN(tb_dREN),
	    .dWEN(tb_dWEN)
	  );
	`endif

endmodule

program test(
  input logic tb_CLK, output logic tb_nRST, output logic [31:0] tb_imemload, output logic tb_ihit, output logic tb_dhit, output logic tb_halt
);
	import cpu_types_pkg::*;
	parameter PERIOD = 10;
  	string testcase = "begin";

	initial begin

	$display("Simulation Test - Control Unit");
	@(posedge tb_CLK);
	tb_nRST = 1;
	tb_imemload = '0;
	tb_ihit = 0;
	tb_dhit = 0;
	tb_halt = 0;

	@(posedge tb_CLK);
	$display("Performing nRST");
	testcase = "reset";
	tb_nRST = 0;

	@(posedge tb_CLK);
	$display("Initializing Default Parameters");
	testcase = "start";
	tb_nRST = 1;
	tb_imemload = '0;
	tb_ihit = 0;
	tb_dhit = 0;
	tb_halt = 0;

	@(posedge tb_CLK);
    testcase = "ihit, no op";
    $display("%s: Test 1: ", testcase);
    tb_imemload = '0;
    tb_ihit = 1;

    @(posedge tb_CLK);
    tb_ihit = 0;

    @(posedge tb_CLK);
    testcase = "ihit, lw op";
    $display("%s: Test 1: ", testcase);
    tb_imemload = {6'b100011, 26'b0};
    tb_ihit = 1;

    @(posedge tb_CLK);
    tb_ihit = 0;

    @(posedge tb_CLK);
    testcase = "dhit, lw op";
    $display("%s: Test 1: ", testcase);
    tb_imemload = {6'b100011, 26'b0};
    tb_dhit = 1;

    @(posedge tb_CLK);
    tb_dhit = 0;

    @(posedge tb_CLK);
    testcase = "ihit, sw op";
    $display("%s: Test 1: ", testcase);
    tb_imemload = {6'b101011, 26'b0};
    tb_ihit = 1;

    @(posedge tb_CLK);
    testcase = "halt";
    $display("%s: Test 1: ", testcase);
    tb_imemload = {6'b111111, 26'b0};
    tb_ihit = 1;
    tb_halt = 1;

    @(posedge tb_CLK);
	end // initial
endprogram