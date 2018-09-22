`include "cpu_types_pkg.vh"

module request_unit (
  input logic CLK, nRST, ihit, dhit, halt, //dWEN, dREN,
  input logic [31:0] imemload,
  output reg iREN, dREN, dWEN
  //output reg imemREN, dmemREN, dmemWEN
);
  // type import
  import cpu_types_pkg::*;

  logic next_i_ren, next_d_ren, next_d_wen;
  //logic current_d_hit, current_i_hit;
  /*
  logic next_d_hit, next_i_hit;
  assign next_i_hit = ihit;
  assign next_d_hit = dhit;
  */

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

  always_ff @(posedge CLK, negedge nRST)
  begin
    if(!nRST) begin
      iREN <= 1;
      dREN <= 0;
      dWEN <= 0;
    end else begin
      iREN <= next_i_ren;
      dREN <= next_d_ren;
      dWEN <= next_d_wen;
    end
  end

  /*always_ff @(posedge CLK, negedge nRST)
  begin
    if(!nRST) begin
      imemREN <= 1;
      dmemREN <= 0;
      dmemWEN <= 0;
    end else begin
      if(ihit) begin
        dmemREN <= dREN;
        dmemWEN <= dWEN;
      end
      else begin
        dmemREN <= next_d_ren;
        dmemWEN <= next_d_wen;
      end
      if(dhit) begin
        dmemREN <= 0;
        dmemWEN <= 0;
      end
    end
  end*/

  always_comb
  begin
  	next_i_ren = 1;
  	next_d_ren = dREN;
  	next_d_wen = dWEN;
    //check this, student said this will break design
    
  	/*if(halt == 1'b1) begin
  		next_i_ren = 0;
  		next_d_ren = 0;
  		next_d_wen = 0;
  	end
  	else */if(dhit == 1'b1) begin
  		next_d_ren = 0;
  		next_d_wen = 0;
  	end
  	else if(ihit == 1'b1) begin
  		//enums for LW + SW from cpu_types_pkg
  		if(imemload [31:26] == 6'b100011) begin	//6'b100011 = LW
  			next_d_ren = 1;
  		end
  		else if (imemload [31:26] == 6'b101011) begin	//6'b101011 = SW
  			next_d_wen = 1;
  		end
  	end
    else begin
      next_i_ren = 1;
      next_d_ren = dREN;
      next_d_wen = dWEN;
    end
  end

endmodule