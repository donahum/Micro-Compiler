`include "memwb_if.vh"

module memwb (
	/*input logic CLK, nRST, ihit, jmp, b_ne, b_eq, alu_src, halt, dREN, dWEN,
	input logic [31:0] pc, instrDecode,
	input logic [31:0] imm, rdat1, rdat2,
	output aluop_t op,
	output logic [31:0] rdat1MEM, rdat2MEM,
	output logic jmpMEM, b_neMEM, b_eqMEM, alu_srcMEM, haltMEM, dRENMEM, dWENMEM,
	output logic [31:0]pcMEM2, immMEM, instrDecodeMEM*/
	input logic CLK, nRST, ihit, dhit,
	memwb_if.mwbif memwbif
);
	

	always_ff @(posedge CLK, negedge nRST)
	begin
		if(!nRST) begin
			memwbif.jmpWB <= '0;
			memwbif.b_eqWB <= '0;
			memwbif.b_neWB <= '0;
			memwbif.haltWB <= '0;
			memwbif.dRENWB <= '0;
			memwbif.dWENWB <= '0;
			memwbif.pcWB <= '0;
			memwbif.reg_dstWB <= '0;
			memwbif.instrWB <= '0;
			memwbif.zeroWB <= '0;
			memwbif.immWB <= '0;
			memwbif.rdat2WB <= '0;
			memwbif.resultWB <= '0;
			memwbif.j_alWB <= '0;
			memwbif.rf_writeWB <= '0;
			memwbif.memtoregWB <= '0;
		end else if(ihit || dhit) begin
			memwbif.rf_writeWB <= memwbif.rf_writeMEM;
			memwbif.reg_dstWB <= memwbif.reg_dstMEM;
			memwbif.resultWB <= memwbif.resultMEM;
			memwbif.jmpWB <= memwbif.jmpMEM;
			memwbif.b_eqWB <= memwbif.b_eqMEM;
			memwbif.b_neWB <= memwbif.b_neMEM;
			memwbif.haltWB <= memwbif.haltMEM;
			memwbif.dRENWB <= memwbif.dRENMEM;
			memwbif.dWENWB <= memwbif.dWENMEM;
			memwbif.pcWB <= memwbif.pcMEM;
			memwbif.instrWB <= memwbif.instrMEM;
			memwbif.zeroWB <= memwbif.zeroMEM;
			memwbif.immWB <= memwbif.immMEM;
			memwbif.rdat2WB <= memwbif.rdat2MEM;
			memwbif.j_alWB <= memwbif.j_alMEM;
			memwbif.memtoregWB <= memwbif.memtoregMEM;
		end 
	end  

endmodule