`ifndef MEMWB_IF_VH
`define MEMWB_IF_VH
// all types
`include "cpu_types_pkg.vh"

interface memwb_if;
  // import types
  import cpu_types_pkg::*;

  //inputs
  logic zeroMEM, jmpMEM, b_eqMEM, b_neMEM, haltMEM, dRENMEM, dWENMEM,reg_dstMEM, j_alMEM,rf_writeMEM, memtoregMEM;
  logic [31:0] pcMEM, instrMEM, immMEM, rdat2MEM, resultMEM;
  //outputs
  logic jmpWB, b_eqWB, b_neWB, haltWB,reg_dstWB, j_alWB,rf_writeWB, memtoregWB;
  logic dRENWB, dWENWB;
  logic [31:0] pcWB, instrWB, immWB, rdat2WB, resultWB;
  logic zeroWB;
  // register file ports
  modport mwbif (
      input zeroMEM, jmpMEM, b_eqMEM, b_neMEM, haltMEM, dRENMEM, dWENMEM, pcMEM, instrMEM, immMEM, reg_dstMEM, rdat2MEM, j_alMEM, resultMEM,rf_writeMEM, memtoregMEM,
      output jmpWB, b_eqWB, b_neWB, haltWB, dRENWB, dWENWB, pcWB, instrWB, zeroWB, immWB, reg_dstWB, rdat2WB, j_alWB, resultWB, rf_writeWB, memtoregWB
  );
  // register file tb
  modport mwbtb (   
      input jmpWB, b_eqWB, b_neWB, haltWB, dRENWB, dWENWB, pcWB, instrWB, zeroWB, immWB,reg_dstWB, rdat2WB, j_alWB, resultWB,rf_writeWB, memtoregWB,
      output zeroMEM, jmpMEM, b_eqMEM, b_neMEM, haltMEM, dRENMEM, dWENMEM, pcMEM, instrMEM, immMEM, reg_dstMEM, rdat2MEM, j_alMEM, resultMEM,rf_writeMEM, memtoregMEM
  );
endinterface

`endif //ALU_IF_VH