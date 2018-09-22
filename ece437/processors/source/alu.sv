`include "alu_if.vh"

module alu (alu_if.rf aluif);

	always_comb
	begin
		aluif.output_port = '0;
		casez(aluif.aluop)
			4'b0000 : begin 
				//may have to shift by shamt (instr [4:0])
				aluif.output_port = aluif.port_b << aluif.port_a [4:0];
				aluif.overflow = 0;
			end // 4'b0000 :
		    4'b0001 : begin
		     	aluif.output_port = aluif.port_b >> aluif.port_a [4:0];
		     	aluif.overflow = 0;
		 	end
		    4'b0010 : begin
		    	aluif.output_port = aluif.port_a + aluif.port_b;
		    	if ((aluif.port_a [31] == 0) & (aluif.port_b [31] == 0) & (aluif.output_port [31] == 1)) begin
		    		aluif.overflow = 1;
		    	end
		    	else if ((aluif.port_a [31] == 1) & (aluif.port_b [31] == 1) & (aluif.output_port [31] == 0)) begin
		    		aluif.overflow = 1;
		    	end
		    	else begin
		    		aluif.overflow = 0;
		    	end
		    end // 4'b0010 :
		    4'b0011 : begin
		    	aluif.output_port = aluif.port_a - aluif.port_b;
		    	if ((aluif.port_a [31] == 0) & (aluif.port_b [31] == 1) & (aluif.output_port [31] == 1)) begin
		    		aluif.overflow = 1;
		    	end
		    	else if ((aluif.port_a [31] == 1) & (aluif.port_b [31] == 0) & (aluif.output_port [31] == 0)) begin
		    		aluif.overflow = 1;
		    	end
		    	else begin
		    		aluif.overflow = 0;
		    	end
		    end
		    4'b0100 : begin
		    	aluif.output_port = aluif.port_a & aluif.port_b;
		    	aluif.overflow = 0;
		    end
		    4'b0101 : begin
		    	aluif.output_port = aluif.port_a | aluif.port_b;
		    	aluif.overflow = 0;
		    end
		    4'b0110 : begin 
		    	aluif.output_port = aluif.port_a ^ aluif.port_b;
		    	aluif.overflow = 0;
		    end
		    4'b0111 : begin 
		    	aluif.output_port = ~(aluif.port_a | aluif.port_b);
		    	aluif.overflow = 0;
		    end
		    4'b1010 : begin
		    	aluif.output_port = ($signed(aluif.port_a) < $signed(aluif.port_b)) ? 32'd1:32'd0;
		    	aluif.overflow = 0;
		    end
		    4'b1011 : begin
		    	aluif.output_port = (aluif.port_a < aluif.port_b) ? 32'd1:32'd0;
		    	aluif.overflow = 0;
		    end
		endcase // aluif.aluop
	end	

	//handle flags
	//assign aluif.negative = ($signed(aluif.output_port) < 32'b0) ? 1'b1:1'b0;	//just check MSB
	assign aluif.negative = aluif.output_port[31];
	assign aluif.zero     = (aluif.output_port == 32'b0) ? 1'b1:1'b0;
	// assign aluif.overflow = (($signed(aluif.port_a) > 0) & ($signed(aluif.port_b) > 0) & ($signed(aluif.output_port) < 0)) 
	// 						? 1: (($signed(aluif.port_a) < 0) & ($signed(aluif.port_b) < 0) & ($signed(aluif.output_port) > 0)) 
	// 						? 1:0;
	//use msb to determine here

endmodule