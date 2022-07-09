// 1201201140
// 八木洸太

//7segment LED
module m_7segled (w_in, r_led);
	input wire [3:0] w_in;
	output reg [6:0] r_led;
	always@(*) begin
		case (w_in)
			4'h0 : r_led <= 7'b1000000;
			4'h1 : r_led <= 7'b1111001;
			4'h2 : r_led <= 7'b0100100;
			4'h3 : r_led <= 7'b0110000;
			4'h4 : r_led <= 7'b0011001;
			4'h5 : r_led <= 7'b0010010;
			4'h6 : r_led <= 7'b0000010;
			4'h7 : r_led <= 7'b1011000;
			4'h8 : r_led <= 7'b0000000;
			4'h9 : r_led <= 7'b0010000;
			4'ha : r_led <= 7'b0001000;
			4'hb : r_led <= 7'b0000011;
			4'hc : r_led <= 7'b1000110;
			4'hd : r_led <= 7'b0100001;
			4'he : r_led <= 7'b0000110;
			4'hf : r_led <= 7'b0001110;
			default : r_led <= 7'bxxxxxxx;
		endcase
	end
endmodule

module m_top();
	reg [3:0] r_in;
	wire [6:0] w_led;
	integer i;
	initial $display ("       gfedcba");
	initial begin
		#10 r_in <= 4'd0; i = 0;
		#1 $display("%3d -> %b", i, w_led);
		for(i = 1; i <= 30; i = i + 1) begin
			#10 r_in <= r_in + 1;
			if (r_in >= 9)
				r_in <= r_in - 9;
			#1 $display("%3d -> %b", i, w_led);
		end
	end
	
	m_7segled m_7segled1(r_in, w_led);
endmodule