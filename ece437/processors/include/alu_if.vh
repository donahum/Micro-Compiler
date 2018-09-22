`ifndef ALU_IF_VH
`define ALU_IF_VH
// all types
`include "cpu_types_pkg.vh"

interface alu_if;
  // import types
  import cpu_types_pkg::*;

  logic zero, overflow, negative;
  aluop_t aluop;
  word_t port_a, port_b, output_port;

  // register file ports
  modport rf (
    input aluop, port_a, port_b,
    output output_port, overflow, zero, negative
  );
  // register file tb
  modport tb (
    input output_port, overflow, zero, negative,
    output aluop, port_a, port_b
  );
endinterface

`endif //ALU_IF_VH