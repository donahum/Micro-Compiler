`include "cache_control_if.vh"
`include "cpu_ram_if.vh"

`timescale 1 ns / 1 ns

module memory_control_tb;
  parameter PERIOD = 10;
  import cpu_types_pkg::*;
  logic CLK = 0;
  logic nRST;

  // clock
  always #(PERIOD/2) CLK++;

  //cache instantiation
  caches_if tb_cif0 ();
  caches_if tb_cif1 ();
  // interface
  cache_control_if tb_ccif (tb_cif0, tb_cif1);
  cpu_ram_if tb_rif ();

  // test program
  test PROG (.CLK, .nRST);
  // DUT
`ifndef MAPPED
  memory_control DUT(CLK, nRST, tb_ccif);
`else
  memory_control DUT(
    /*.\CLK(CLK),
    .\nRST(nRST),
    //cache ports
    .\tb_ccif.iRen(ccif.iRen),
    .\tb_ccif.dRen(ccif.dRen),
    .\tb_ccif.dWen(ccif.dWen),
    .\tb_ccif.dstore(ccif.dstore),
    .\tb_ccif.iaddr(ccif.iaddr),
    .\tb_ccif.daddr(ccif.daddr),

    .\tb_ccif.ramload(ccif.ramload),
    .\tb_ccif.ramstate(ccif.ramstate),

    .\tb_ccif.ccwrite(ccif.ccwrite),
    .\tb_ccif.cctrans(ccif.cctrans),

    .\tb_ccif.iwait(ccif.iwait),
    .\tb_ccif.dwait(ccif.dwait),
    .\tb_ccif.iload(ccif.iload),
    .\tb_ccif.dload(ccif.dload),

    .\tb_ccif.ramstore(ccif.ramstore),
    .\tb_ccif.ramaddr(ccif.ramaddr),
    .\tb_ccif.ramWEN(ccif.ramWEN),
    .\tb_ccif.ramREN(ccif.ramREN),

    .\tb_ccif.ccwait(ccif.ccwait),
    .\tb_ccif.ccinv(ccif.ccinv),
    .\tb_ccif.ccsnoopaddr(ccif.ccsnoopaddr)//,
    //ram ports
    /*
    .\tb_rif.ramstate(rif.ramstate),
    .\tb_rif.ramload(rif.ramload),

    .\tb_rif.ramaddr(rif.ramaddr),
    .\tb_rif.ramstore(rif.ramstore),
    .\tb_rif.ramREN(rif.ramREN),
    .\tb_rif.ramWEN(rif.ramWEN)
    */
    .\CLK(CLK),
    .\nRST(nRST),
    //cache ports
    .\ccif.iREN(tb_cif0.iREN),
    .\ccif.dREN(tb_cif0.dREN),
    .\ccif.dWEN(tb_cif0.dWEN),
    .\ccif.dstore(tb_cif0.dstore),
    .\ccif.iaddr(tb_cif0.iaddr),
    .\ccif.daddr(tb_cif0.daddr),

    .\ccif.ramload(tb_cif0.ramload),
    .\ccif.ramstate(tb_cif0.ramstate),

    .\ccif.ccwrite(tb_cif0.ccwrite),
    .\ccif.cctrans(tb_cif0.cctrans),

    .\ccif.iwait(tb_cif0.iwait),
    .\ccif.dwait(tb_cif0.dwait),
    .\ccif.iload(tb_cif0.iload),
    .\ccif.dload(tb_cif0.dload),

    .\ccif.ramstore(tb_cif0.ramstore),
    .\ccif.ramaddr(tb_cif0.ramaddr),
    .\ccif.ramWEN(tb_cif0.ramWEN),
    .\ccif.ramREN(tb_cif0.ramREN),

    .\ccif.ccwait(tb_cif0.ccwait),
    .\ccif.ccinv(tb_cif0.ccinv),
    .\ccif.ccsnoopaddr(tb_cif0.ccsnoopaddr)

  );
`endif

`ifndef MAPPED
  ram ramDUT(CLK, nRST, tb_rif);
`else
  ram ramDUT(
      .\CLK(CLK),
      .\nRST(nRST),
      .\rif.ramaddr(tb_rif.ramaddr),
      .\rif.ramstore(tb_rif.ramstore),
      .\rif.ramREN(tb_rif.ramREN),
      .\rif.ramWEN(tb_rif.ramWEN),

      .\rif.ramstate(tb_rif.ramstate),
      .\rif.ramload(tb_rif.ramload)
);
`endif
  	
  	assign tb_rif.ramWEN = tb_ccif.ramWEN;
  	assign tb_rif.ramREN = tb_ccif.ramREN;
  	assign tb_rif.ramaddr = tb_ccif.ramaddr;

  	assign tb_rif.ramstore = tb_ccif.ramstore;
  	assign tb_ccif.ramload = tb_rif.ramload;
  	assign tb_ccif.ramstate = tb_rif.ramstate;

endmodule

program test(
  input logic CLK, output logic nRST
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
    
	  $display("Initializing Default Parameters");
    /*
    tb_cif0.iREN = 0;
	  tb_cif0.dREN = 0;
	  tb_cif0.dWEN = 0;
    tb_cif0.dstore = '0;
	  tb_cif0.iaddr = '0;
	  tb_cif0.daddr = '0;
    */
	  #(PERIOD);
    testcase = "Test 1";
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    $display("%s: Write Data", testcase);
    /*
    tb_cif0.dWEN = 1;
    tb_cif0.daddr = 32'h8;
    tb_cif0.dstore = 32'haabbccdd;
    @(negedge tb_cif0.dwait);
    #(PERIOD);
    testcase = "Test 2";
    /*
    $display("%s: Read Data", testcase);
    tb_cif0.dWEN = 0;     //deassert write
    tb_cif0.dstore = '0;  //clear num to store
    tb_cif0.dREN = 1;     
    tb_cif0.daddr = 32'hc;
    @(negedge tb_cif0.dwait);
    #(PERIOD);
    testcase = "Test 3";

    $display("%s: Read vs Write Data", testcase); 
    tb_cif0.dWEN = 1; 
    tb_cif0.daddr = 32'h10;
    tb_cif0.iaddr = 32'h14;
    @(negedge tb_cif0.dwait);
    #(PERIOD);
    testcase = "Test 4";

    $display("%s: Read Data vs Read Instruction", testcase);
    tb_cif0.dWEN = 0;
    #(PERIOD);
    tb_cif0.dREN = 1;
    tb_cif0.iREN = 1;
    tb_cif0.daddr = 32'h10;
    tb_cif0.iaddr = 32'h14;
    
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    #(PERIOD);
    testcase = "Test 5";

    $display("%s: Read Instruction", testcase);
    tb_cif0.dREN = 0;     
    tb_cif0.iREN = 1;
    tb_cif0.daddr = '0;
    tb_cif0.iaddr = 32'h14;
    @(negedge tb_cif0.iwait);
    #(PERIOD);
    */
    dump_memory();
	  
	end // initial

	task automatic dump_memory();
	    string filename = "memcpu.hex";
	    int memfd;

	    //tb_cif0.tbCTRL = 1;
	    tb_cif0.daddr = 0;
	    tb_cif0.dWEN = 0;
	    tb_cif0.dREN = 0;
      tb_cif0.iREN = 0;

	    memfd = $fopen(filename,"w");
	    if (memfd)
	      $display("Starting memory dump.");
	    else
	      begin $display("Failed to open %s.",filename); $finish; end

	    for (int unsigned i = 0; memfd && i < 16384; i++)
	    begin
	      int chksum = 0;
	      bit [7:0][7:0] values;
	      string ihex;

	      tb_cif0.daddr = i << 2;
	      tb_cif0.dREN = 1;
	      repeat (4) @(posedge CLK);
	      if (tb_cif0.dload === 0)
	        continue;
	      values = {8'h04,16'(i),8'h00,tb_cif0.dload};
	      foreach (values[j])
	        chksum += values[j];
	      chksum = 16'h100 - chksum;
	      ihex = $sformatf(":04%h00%h%h",16'(i),tb_cif0.dload,8'(chksum));
	      $fdisplay(memfd,"%s",ihex.toupper());
	    end //for
	    if (memfd)
	    begin
	      //tb_cif0.tbCTRL = 0;
	      tb_cif0.dREN = 0;
	      $fdisplay(memfd,":00000001FF");
	      $fclose(memfd);
	      $display("Finished memory dump.");
	    end
  	endtask
endprogram