`ifndef IDEX_IF_VH
`define IDEX_IF_VH
// all types
`include "cpu_types_pkg.vh"

interface idex_if;
  // import types
  import cpu_types_pkg::*;

  logic jmpDEC, b_neDEC, b_eqDEC, alu_srcDEC, haltDEC, dRENDEC, dWENDEC, l_uiDEC, extend_signDEC, jmprDEC, rf_writeDEC, reg_dstDEC, j_alDEC, memtoregDEC;
  logic [31:0] pcDEC, instrDEC;
  logic [31:0] immDEC, rdat1DEC, rdat2DEC;
  aluop_t opEX, opDEC;
  logic [31:0] rdat1EX, rdat2EX;
  logic jmpEX, b_neEX, b_eqEX, alu_srcEX, haltEX, dRENEX, dWENEX, l_uiEX, extend_signEX, jmprEX, rf_writeEX, reg_dstEX, j_alEX, memtoregEX;
  logic [31:0] pcEX, immEX, instrEX;

  // register file ports
  modport exif (
      input jmpDEC, b_neDEC, b_eqDEC, alu_srcDEC, haltDEC, dRENDEC, dWENDEC, pcDEC, instrDEC, immDEC, rdat1DEC, rdat2DEC, l_uiDEC, extend_signDEC, jmprDEC, opDEC, rf_writeDEC, reg_dstDEC, j_alDEC, memtoregDEC,
      output opEX, rdat1EX, rdat2EX, jmpEX, b_neEX, b_eqEX, alu_srcEX, haltEX, dRENEX, dWENEX, pcEX, immEX, instrEX, l_uiEX, extend_signEX, jmprEX, rf_writeEX,reg_dstEX, j_alEX, memtoregEX
  );
  // register file tb
  modport extb (
      input opEX, rdat1EX, rdat2EX, jmpEX, b_neEX, b_eqEX, alu_srcEX, haltEX, dRENEX, dWENEX, pcEX, immEX, instrEX, l_uiEX, extend_signEX, jmprEX, rf_writeEX,reg_dstEX, j_alEX, memtoregEX,
      output jmpDEC, b_neDEC, b_eqDEC, alu_srcDEC, haltDEC, dRENDEC, dWENDEC, pcDEC, instrDEC, immDEC, rdat1DEC, rdat2DEC, l_uiDEC, extend_signDEC, jmprDEC, opDEC, rf_writeDEC, reg_dstDEC, j_alDEC, memtoregDEC
  );
endinterface

`endif 