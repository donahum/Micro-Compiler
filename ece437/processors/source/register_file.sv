`include "register_file_if.vh"

module register_file (
	input logic CLK, nRST, 
	register_file_if.rf rfif
);

logic [31:0][31:0] regs;

//not needed, just don't ever write to reg [0] - line 19
//assign regs [0] = '0;

always_ff @(negedge CLK, negedge nRST) begin
	//resetting
	if(!nRST) begin
		regs <= '0;
	end
	//writing
	else if (rfif.WEN) begin
		if(rfif.wsel != 'h0) begin
			regs [rfif.wsel] <= rfif.wdat;
		end
	end
end // always_ff @(posedge CLK)

//select read data from rsel value
assign rfif.rdat1 = regs [rfif.rsel1];
assign rfif.rdat2 = regs [rfif.rsel2];

endmodule