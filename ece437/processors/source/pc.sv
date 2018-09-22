module pc (
	input logic CLK, nRST, ihit, dhit, halt, jr, zero, b_eq, b_ne, //latency_wait,
	input logic [31:0] imm, 
	input logic jmp, 
	input logic [25:0] jaddr, 
	input logic [31:0] lr,
	input logic d_ren, d_wen,
  	output logic [31:0] pc
);

	/*logic [31:0] npc = '0;
	logic [31:0] npc1 = '0;
	logic [31:0] npc2 = '0;
	logic [31:0] npc3 = '0;
	*/
	logic [31:0] final_npc;
	logic [31:0] pc_plus4;
	logic [31:0] pc_plus4_plusimm;
	logic b;
	logic [27:0] shifted_jaddr;

	//logic latency_met = 0;

	//logic halt_latch;
	/*
	logic current_d_hit, current_i_hit;

  	logic next_d_hit, next_i_hit;
  	assign next_i_hit = ihit;
  	assign next_d_hit = dhit;
  	*/

	always_ff @(posedge CLK, negedge nRST)
	begin
		if(!nRST) begin
			pc <= '0;
		end else begin
			pc <= final_npc;
		end
	end	

/*
	always_ff @(posedge CLK, negedge nRST)
  	begin
    	if(!nRST) begin
      		current_d_hit <= '0;
      		current_i_hit <= '0;
    	end else begin
      		current_d_hit <= next_d_hit;
      		current_i_hit <= next_i_hit;
    	end
  	end 
  	*/

	always_comb
	begin
		pc_plus4 = pc + 32'h4;
		pc_plus4_plusimm = pc_plus4 + imm;
		shifted_jaddr = ({2'b0, jaddr} << 2);
		//final_npc = '0;
		b = (b_eq && zero) ^ (b_ne && !zero);

		
		/*if(halt) begin
			final_npc = pc;
		end else*/ 
		if(b && ihit) begin
			final_npc = pc_plus4_plusimm;
		end else if(jr && ihit) begin
			final_npc = lr;
		end else if(jmp && ihit) begin
			final_npc = {pc_plus4 [31:28], shifted_jaddr};
		end else if(d_ren) begin
			final_npc = pc;
		end else if(ihit & !dhit) begin
			final_npc = pc_plus4;
		end else begin
			final_npc = pc;
		end
	end

endmodule