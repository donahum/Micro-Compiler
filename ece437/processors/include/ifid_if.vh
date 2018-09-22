`ifndef IFID_IF_VH
`define IFID_IF_VH
// all types
`include "cpu_types_pkg.vh"

interface ifid_if;
  // import types
  import cpu_types_pkg::*;

  logic [31:0] instr, dmemload, dmemstore;
  word_t pc;
  word_t pcIF;
  logic [31:0] instrIF;
  logic [4:0] rsIF, rtIF, rdIF;
  logic [15:0] immIF;

  // register file ports
  modport ifif (
      input instr, pc,
      output pcIF, instrIF, rsIF, rtIF, rdIF, immIF
  );
  // register file tb
  modport iftb (
      input pcIF, instrIF, rsIF, rtIF, rdIF, immIF,
      output instr, pc
  );
endinterface

`endif //ALU_IF_VH