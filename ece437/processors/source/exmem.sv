`include "exmem_if.vh"

module exmem (
	/*input logic CLK, nRST, ihit, jmp, b_ne, b_eq, alu_src, halt, dREN, dWEN,
	input logic [31:0] pc, instrDecode,
	input logic [31:0] imm, rdat1, rdat2,
	output aluop_t op,
	output logic [31:0] rdat1MEM, rdat2MEM,
	output logic jmpMEM, b_neMEM, b_eqMEM, alu_srcMEM, haltMEM, dRENMEM, dWENMEM,
	output logic [31:0]pcMEM2, immMEM, instrDecodeMEM*/
	input logic CLK, nRST, ihit, dhit,
	exmem_if.exmif exmemif
);
	

	always_ff @(posedge CLK, negedge nRST)
	begin
		if(!nRST) begin
			exmemif.pcMEM <= '0;
			exmemif.instrMEM <= '0;
			exmemif.jmpMEM<= '0;
			exmemif.b_neMEM<= '0;
			exmemif.b_eqMEM<= '0;
			exmemif.alu_srcMEM<= '0;
			exmemif.haltMEM<= '0;
			exmemif.dRENMEM<= '0;
			exmemif.dWENMEM<= '0;
			exmemif.immMEM<= '0;
			exmemif.rdat1MEM <= '0;
			exmemif.rdat2MEM <= '0;
			exmemif.reg_dstMEM <= '0;
			exmemif.jmprMEM <= '0;
			exmemif.resultMEM <= '0;
			exmemif.rf_writeMEM <= '0;
			exmemif.j_alMEM <= '0;
			exmemif.memtoregMEM <= '0;
			exmemif.zeroMEM <= 0;
		end else if(ihit) begin
			exmemif.resultMEM <= exmemif.resultEX;
			exmemif.reg_dstMEM <= exmemif.reg_dstEX;
			exmemif.pcMEM <= exmemif.pcEX;
			exmemif.instrMEM <= exmemif.instrEX;
			exmemif.jmpMEM<= exmemif.jmpEX;
			exmemif.b_neMEM<= exmemif.b_neEX;
			exmemif.b_eqMEM<= exmemif.b_eqEX;
			exmemif.alu_srcMEM<= exmemif.alu_srcEX;
			exmemif.haltMEM <= exmemif.haltEX;
			exmemif.dRENMEM<= exmemif.dRENEX;
			exmemif.dWENMEM<= exmemif.dWENEX;
			exmemif.immMEM<= exmemif.immEX;
			exmemif.rdat1MEM <= exmemif.rdat1EX;
			exmemif.rdat2MEM <= exmemif.rdat2EX;
			exmemif.jmprMEM <= exmemif.jmprEX;
			exmemif.rf_writeMEM <= exmemif.rf_writeEX;
			exmemif.j_alMEM <= exmemif.j_alEX;
			exmemif.memtoregMEM <= exmemif.memtoregEX;
			exmemif.zeroMEM <= exmemif.zeroEX;
		end else if (dhit) begin 
			exmemif.dRENMEM <= 0;
			exmemif.dWENMEM <= 0;
		end
	end
endmodule