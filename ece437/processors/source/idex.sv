`include "idex_if.vh"

module idex (
	input logic CLK, nRST, ihit,
	idex_if.exif idexif
);
	  import cpu_types_pkg::*;

	always_ff @(posedge CLK, negedge nRST)
	begin
		if(!nRST) begin
			idexif.pcEX <= '0;
			idexif.instrEX <= '0;
			idexif.jmpEX<= '0;
			idexif.b_neEX<= '0;
			idexif.b_eqEX<= '0;
			idexif.alu_srcEX<= '0;
			idexif.haltEX<= '0;
			idexif.dRENEX<= '0;
			idexif.dWENEX<= '0;
			idexif.immEX<= '0;
			idexif.rdat1EX <= '0;
			idexif.rdat2EX <= '0;
			idexif.l_uiEX <= '0;
			idexif.extend_signEX <= '0;
			idexif.jmprEX <= '0;
			idexif.reg_dstEX <= '0;
			idexif.rf_writeEX <= '0;
			idexif.j_alEX <= '0;
			idexif.opEX <= ALU_ADD;
			idexif.memtoregEX <= '0;
		end else if(ihit) begin
			idexif.pcEX <= idexif.pcDEC;
			idexif.opEX <= idexif.opDEC;
			idexif.reg_dstEX <= idexif.reg_dstDEC;
			idexif.instrEX <= idexif.instrDEC;
			idexif.jmpEX<= idexif.jmpDEC;
			idexif.b_neEX<= idexif.b_neDEC;
			idexif.alu_srcEX<= idexif.alu_srcDEC;
			idexif.haltEX<= idexif.haltDEC;
			idexif.dRENEX<= idexif.dRENDEC;
			idexif.dWENEX<= idexif.dWENDEC;
			idexif.immEX<= idexif.immDEC;
			idexif.rdat1EX <= idexif.rdat1DEC;
			idexif.rdat2EX <= idexif.rdat2DEC;
			idexif.l_uiEX <= idexif.l_uiDEC;
			idexif.extend_signEX <= idexif.extend_signDEC;
			idexif.jmprEX <= idexif.jmprDEC;
			idexif.rf_writeEX <= idexif.rf_writeDEC;
			idexif.j_alEX <= idexif.j_alDEC;
			idexif.memtoregEX <= idexif.memtoregDEC;
		end
	end

endmodule