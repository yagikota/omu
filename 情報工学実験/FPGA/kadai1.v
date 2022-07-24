// 1201201140
// 八木洸太

module or2(a, b, x);
	input a, b;
	output x;
	assign x = a | b;
endmodule

/********************************
必要なモジュールを追加すること
*********************************/
module or3(a, b, c, x);
	input a, b, c;
	output x;
	assign x = a | b | c;
endmodule

module nor4(a, b, c, d, x);
	input a, b, c, d;
	output x;
	assign x = ~(a | b | c | d);
endmodule


module seg7_top();
	reg a, b, c, d;
	reg [6:0] x;
	/* 必要な変数を追加すること　ヒント：各演算ごとに変数が必要 */
	wire s0, s1, s2, s3, s4, s5, s6;

	initial begin
		#10 a <= 0; b <= 0; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 1; b <= 0; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 0; b <= 1; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 1; b <= 1; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 0; b <= 0; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 1; b <= 0; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 0; b <= 1; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 1; b <= 1; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 0; b <= 0; c <= 0; d <= 1;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 a <= 1; b <= 0; c <= 0; d <= 1;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
		#10 $finish;
	end

	/*********************************
	入力に応じて該当するbitを1にする処理
	各自で条件を設定すること
	bitマスク処理は以下のどちらでも可能
	**********************************/
	always@(*) begin
		x = 7'b0000000;
		if(s0 == 1'b1)
			x = x | 7'b0000001;
			// x[0] = 1;
		if(s1 == 1'b1)
			x = x | 7'b0000010;
			//x[1] = 1;
		if(s2 == 1'b1)
			x = x | 7'b0000100;
			//x[2] = 1;
		if(s3 == 1'b1)
			x = x | 7'b0001000;
			//x[3] = 1;
		if(s4 == 1'b1)
			x = x | 7'b0010000;
			//x[4] = 1;
		if(s5 == 1'b1)
			x = x | 7'b0100000;
			//x[5] = 1;
		if(s6 == 1'b1)
			x = x | 7'b1000000;
			//x[6] = 1;
	end

	/*****************************************
	必要なモジュールのインスタンスを作成すること
	ヒント：演算ごとにインスタンスが必要
	******************************************/
	or2 or_0((a & ~b & ~c & ~d) , (~a & ~b & c & ~d), s0);
	or2 or_1((a & ~b & c & ~d), (~a & b & c & ~d), s1);
	or2 or_2((~a & b & ~c & ~d), 1'b0, s2);
	or3 or_3((a & ~b & ~c & ~d), (~a & ~b & c & ~d), (a & b & c & ~d), s3);
	nor4 or_4((~a & ~b & ~c & ~d), (~a & b & ~c & ~d), (~a & b & c & ~d), (~a & ~b & ~c & d), s4);
	or3 or_5((a & ~b & ~c & ~d), (~a & b & ~c & ~d), (a & b & ~c & ~d), s5);
	or3 or_6((~a & ~b & ~c & ~d), (a & ~b & ~c & ~d), (a & b & c & ~d), s6);

endmodule
