// example1
// module main();
// 	integer result, i;
// 	initial begin
// 		for(i = 0; i < 10; i = i + 1) begin
// 			result = i * (i + 1) / 2;
// 			#100 $display("%d: %4d", i, result);
// 		end
// 	end
// endmodule


// example2
// AND
// module main();
// 	reg a, b;
// 	wire c;
// 	assign c  = a & b;
// 	initial begin
// 		#10 a <= 0; b<= 0;
// 		#10 a <= 0; b<= 1;
// 		#10 a <= 1; b<= 0;
// 		#10 a <= 1; b<= 1;
// 	end
// 	always @(*) #1 $display("%2d: %d %d -> %d", $time, a, b, c);
// endmodule
// 11: 0 0 -> 0
// 21: 0 1 -> 0
// 31: 1 0 -> 0
// 41: 1 1 -> 1



// example3
module m_top();
	reg a, b;
	wire s;
	assign c  = a & b;
	initial begin
		#10 a <= 0; b<= 0;
		#10 a <= 0; b<= 1;
		#10 a <= 1; b<= 0;
		#10 a <= 1; b<= 1;
	end
	always @(*) #1 $display("%2d: %d %d -> %d", $time, a, b, s);
	m_or m_or1(a, b, s);
endmodule

module m_or(a, b, s);
	input wire a, b;
	output wire s;
	assign s = a | b;
endmodule
// 11: 0 0 -> 0
// 21: 0 1 -> 1
// 31: 1 0 -> 1
// 41: 1 1 -> 1
