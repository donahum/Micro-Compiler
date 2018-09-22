`include "ifid_if.vh"

module ifid (
	/*input logic CLK, nRST, ihit,
	input logic [31:0] instr,
	input word_t pc,
	output word_t pcIF,
	output logic [31:0] instrIF,
	output logic [4:0] rs, rt, rd,
	output logic [15:0] imm
	*/input CLK,nRST,ihit,
	  ifid_if.ifif ifidif
);

	always_ff @(posedge CLK, negedge nRST)
	begin
		if(!nRST) begin
			ifidif.pcIF <= '0;
			ifidif.instrIF <= '0;
			ifidif.rsIF <= '0;
			ifidif.rtIF <= '0;
			ifidif.rdIF <= '0;
			ifidif.immIF <= '0;
		end else if(ihit) begin
			ifidif.pcIF <= ifidif.pc;
			ifidif.instrIF <= ifidif.instr;
			ifidif.rsIF <= ifidif.instr [25:21];
			ifidif.rtIF <= ifidif.instr [20:16];
			ifidif.rdIF <= ifidif.instr [15:11];
			ifidif.immIF <= ifidif.instr [15:0];
		end
	end

endmodule