`timescale 1 ns / 1 ns

module control_unit_tb;
	parameter PERIOD = 10;
	import cpu_types_pkg::*;
	//inputs
	logic tb_CLK = 0;
	logic tb_nRST;
	logic [31:0] tb_imemload;
	//outputs
	logic tb_jmp, tb_jmpr, tb_j_al, tb_b_eq, tb_b_ne, tb_rf_write, tb_alu_src, tb_reg_dst;
	logic [3:0] tb_alu_op;
	logic tb_memtoreg, tb_hlt, tb_l_ui;

	// clock
	always #(PERIOD/2) tb_CLK++;
 	// test program
	test PROG (.tb_CLK(tb_CLK), .tb_nRST(tb_nRST), .tb_imemload(tb_imemload));
	// DUT
	`ifndef MAPPED
		control_unit DUT(tb_CLK, tb_nRST, tb_imemload, tb_jmp, tb_jmpr, tb_j_al, tb_b_eq, tb_b_ne, tb_rf_write, tb_alu_src, tb_reg_dst, tb_alu_op, tb_memtoreg, tb_hlt, tb_l_ui);
	`else
		control_unit DUT(
	    .CLK(tb_CLK),
	    .nRST(tb_nRST),
	    .imemload(tb_imemload),
	    .jmp(tb_jmp),
	    .jmpr(tb_jmpr),
	    .j_al(tb_j_al),
	    .b_eq(tb_b_eq),
	    .b_ne(tb_b_ne),
	    .rf_write(tb_rf_write),
	    .alu_src(tb_alu_src),
	    .reg_dst(tb_reg_dst),
	    .alu_op(tb_alu_op),
	    .memtoreg(tb_memtoreg),
	    .hlt(tb_hlt),
	    .l_ui(tb_l_ui)
	  );
	`endif

endmodule

program test(
  input logic tb_CLK, output logic tb_nRST, output logic [31:0] tb_imemload
);
	import cpu_types_pkg::*;
	parameter PERIOD = 10;
  	string testcase = "begin";

	initial begin

	$display("Simulation Test - Control Unit");
	@(posedge tb_CLK);
	tb_nRST = 1;
	tb_imemload = '0;

	@(posedge tb_CLK);
	$display("Performing nRST");
	testcase = "reset";
	tb_nRST = 0;

	@(posedge tb_CLK);
	$display("Initializing Default Parameters");
	testcase = "start";
	tb_nRST = 1;
	tb_imemload = '0;

	@(posedge tb_CLK);
    testcase = "r type";
    $display("%s: Test 1: ", testcase);
	tb_imemload = {RTYPE, 5'b00000, 5'b00000, 5'b00000, 5'b00000, SUB};

	@(posedge tb_CLK);
	testcase = "j type";
    $display("%s: Test 1: ", testcase);
	tb_imemload = {6'b000010, 26'b1};

	@(posedge tb_CLK);
	testcase = "jal type";
    $display("%s: Test 1: ", testcase);
	tb_imemload = {6'b000011, 26'b1};

	@(posedge tb_CLK);
	testcase = "beq type";
    $display("%s: Test 1: ", testcase);
	tb_imemload = {6'b000100, 5'b1, 5'b1, 16'b1};

	@(posedge tb_CLK);
	testcase = "j type";
    $display("%s: Test 1: ", testcase);
	tb_imemload = {6'b111111, 5'b1, 5'b1, 16'b1};
	@(posedge tb_CLK);
	end // initial
endprogram