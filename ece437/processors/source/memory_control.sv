/*
  Eric Villasenor
  evillase@gmail.com

  this block is the coherence protocol
  and artibtration for ram
*/

// interface include
`include "cache_control_if.vh"

// memory types
`include "cpu_types_pkg.vh"

module memory_control (
  input CLK, nRST,
  cache_control_if.cc ccif
);
  // type import
  import cpu_types_pkg::*;

  // number of cpus for cc
  parameter CPUS = 2;

  assign ccif.ramaddr = (ccif.dWEN | ccif.dREN) ? ccif.daddr : ccif.iREN ? ccif.iaddr : '0 ;
  assign ccif.dwait = ccif.ramstate == ACCESS ? (ccif.dWEN | ccif.dREN) ? 0 : 1 : 1;
  assign ccif.iwait = ccif.ramstate == ACCESS ? (ccif.iREN & !ccif.dWEN & !ccif.dREN) ? 0 : 1 : 1;
  assign ccif.ramREN = (!ccif.dWEN & (ccif.dREN | ccif.iREN)) ? 1 : 0;
  assign ccif.ramWEN = (ccif.dWEN) ? 1 : 0;
  assign ccif.ramstore = ccif.dstore;
  assign ccif.dload = ccif.ramload;
  assign ccif.iload = ccif.ramload;

endmodule
