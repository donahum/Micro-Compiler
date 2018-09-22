`ifndef EXMEM_IF_VH
`define EXMEM_IF_VH
// all types
`include "cpu_types_pkg.vh"

interface exmem_if;
  // import types
  import cpu_types_pkg::*;

  //inputs
  logic zeroEX, jmpEX, b_eqEX, b_neEX, haltEX, dRENEX, dWENEX, jmprEX, rf_writeEX, reg_dstEX, j_alEX,alu_srcEX, memtoregEX,dhit;
  logic [31:0] pcEX, instrEX, immEX, rdat2EX, rdat1EX,resultEX;
  //outputs
  logic jmpMEM, b_eqMEM, b_neMEM, haltMEM, dRENMEM, dWENMEM, jmprMEM, rf_writeMEM, reg_dstMEM, j_alMEM, alu_srcMEM, memtoregMEM;
  logic [31:0] pcMEM, instrMEM, immMEM, rdat2MEM, rdat1MEM,resultMEM;
  logic zeroMEM;
  // register file ports
  modport exmif (
      input zeroEX, jmpEX, b_eqEX, b_neEX, haltEX, dRENEX, dWENEX, pcEX, instrEX, immEX, rdat2EX, jmprEX, rf_writeEX, reg_dstEX, j_alEX, resultEX,alu_srcEX,rdat1EX,memtoregEX,dhit,
      output jmpMEM, b_eqMEM, b_neMEM, haltMEM, dRENMEM, dWENMEM, pcMEM, instrMEM, zeroMEM, immMEM, rdat2MEM, jmprMEM, rf_writeMEM, reg_dstMEM, j_alMEM, resultMEM,alu_srcMEM,rdat1MEM, memtoregMEM
  );
  // register file tb
  modport exmemtb (   
      input jmpMEM, b_eqMEM, b_neMEM, haltMEM, dRENMEM, dWENMEM, pcMEM, instrMEM, zeroMEM, immMEM, rdat2MEM, jmprMEM, rf_writeMEM, reg_dstMEM, j_alMEM, resultMEM, alu_srcMEM,rdat1MEM, memtoregMEM,
      output zeroEX, jmpEX, b_eqEX, b_neEX, haltEX, dRENEX, dWENEX, pcEX, instrEX, immEX, rdat2EX, jmprEX, rf_writeEX,reg_dstEX, j_alEX, resultEX,alu_srcEX,rdat1EX, memtoregEX,dhit
  );
endinterface

`endif //ALU_IF_VH