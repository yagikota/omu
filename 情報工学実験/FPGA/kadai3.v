// 1201201140
// 八木洸太

// https://www.geeksforgeeks.org/full-adder-using-verilog-hdl/
// https://esrd2014.blogspot.com/p/full-adder.html
// https://peterfab.com/ref/verilog/verilog_renerta/source/vrg00006.htm


module N_bit_adder(input1, input2, answer);
	parameter N=32;
	input [N-1:0] input1, input2;
	output [N-1:0] answer;
	wire  carry_out;
	wire [N-1:0] carry;
	genvar i;
	generate 
		for(i = 0; i < N; i = i + 1)
			begin: generate_N_bit_Adder
		if(i == 0) 
			half_adder ha(input1[0], input2[0], answer[0], carry[0]);
		else
			full_adder fa(input1[i], input2[i], carry[i-1], answer[i], carry[i]);
			end
		assign carry_out = carry[N-1];
	endgenerate
endmodule 

// 半加算器
module half_adder(a, b, s, c);
	input a, b;
	output s, c;
	assign s = a ^ b;
	assign c = a & b;
endmodule

// 全加算器
module full_adder(a, b, c_in, s, c_out);
	input a, b, c_in;
	output s, c_out;
	assign s = a ^ b ^ c_in;
	assign c_out = (a & b) | (b & c_in) | (c_in & a);
endmodule


module m_top();
	// 全加算器の真偽表を表示
	reg a, b, c_in;
	wire s, c_out;
	initial begin
		#10 a <= 0; b <= 0; c_in <= 0;
		#10 a <= 0; b <= 0; c_in <= 1;
		#10 a <= 0; b <= 1; c_in <= 0;
		#10 a <= 0; b <= 1; c_in <= 1;
		#10 a <= 1; b <= 0; c_in <= 0;
		#10 a <= 1; b <= 0; c_in <= 1;
		#10 a <= 1; b <= 1; c_in <= 0;
		#10 a <= 1; b <= 1; c_in <= 1;
	end
	initial $display("Truth Table of Full Adder");
	initial $display("    a b c_in s c_out");
	always @(*) #1 $display("%2d: %d %d %4d %d %4d", $time, a, b, c_in, s, c_out);
	full_adder fd(a, b, c_in, s, c_out);



	// 全加算器と半加算器を用いて，2進数n桁の加算を行う
	// input1 + input2 = ans

	// initial $display("N bit adder");
	// reg [31:0] input1, input2;
	// wire [31:0] ans;
	// initial begin
	// 	// 適宜値を変える
	// 	input1 = 5;
	// 	// 適宜値を変える
	// 	input2 = 7;
	// end
	// N_bit_adder nba(input1, input2, ans);
	// initial $display("%b(2) + %b(2) = %b(2)", input1, input2, ans);
	// initial $display("%d + %d = %d", input1, input2, ans);
endmodule
