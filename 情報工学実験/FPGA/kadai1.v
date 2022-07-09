// https://www.electronicshub.org/bcd-7-segment-led-display-decoder-circuit/
// https://github.com/tnat93/Up-Down-Counter---7-segment-display/blob/master/Seven_seg.v

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

module seg7_top();
	reg a, b, c, d;
	reg [6:0] x;
	/* 必要な変数を追加すること　ヒント：各演算ごとに変数が必要 */
	// wire 

	initial begin
		#10 a <= 0; b <= 0; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 1; b <= 0; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("a=%d, b=%d, c=%d, d=%d", a, b, c, d);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 0; b <= 1; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 1; b <= 1; c <= 0; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 0; b <= 0; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 1; b <= 0; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 0; b <= 1; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 1; b <= 1; c <= 1; d <= 0;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 0; b <= 0; c <= 0; d <= 1;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 a <= 1; b <= 0; c <= 0; d <= 1;
		#1 $display ("%3d: %d %d %d %d -> %b", $time, d, c, b, a, x);
			// $display("x[0]:%d", (d | b | (c & a) | (~c & ~a)));
		#10 $finish;
	end

	/*********************************
	入力に応じて該当するbitを1にする処理
	各自で条件を設定すること
	bitマスク処理は以下のどちらでも可能
	**********************************/
	always@(*) begin
		x = 7'b0000000;
		if(((a & ~b & ~c & ~d) | (~a & ~b & c & ~d)) == 1'b1)
		// if((d | b | (c & a) | (~c & ~a)) == 1'b0)
			x = x | 7'b0000001;
			// x[0] = 1;
		if(((a & ~b & c & ~d) | (~a & b & c & ~d)) == 1'b1)
		// if(((~c) | (~b & ~a) | (b & a))  == 1'b0)
			x = x | 7'b0000010;
			//x[1] = 1;
		if((~a & b & ~c & ~d) == 1'b1)
		// if((c | ~b | a) == 1'b0)
			x = x | 7'b0000100;
			//x[2] = 1;
		if((a & ~b & ~c & ~d) | (~a & ~b & c & ~d) | (a & b & c & ~d) == 1'b1)
		// if(((~c & ~a) | (b & ~a) | (c & ~b & a) | (~c & b) | d) == 1'b0)
			x = x | 7'b0001000;
			//x[3] = 1;
		if(((a & ~b & ~c & ~d) | (a & b & ~c & ~d) | (~a & ~b & c & ~d) | (a & ~b & c & ~d) | (a & b & c & ~d) | (a & ~b & ~c & d)) == 1'b1)
		// if(((~c & ~a) | (b & ~a)) == 1'b0)
			x = x | 7'b0010000;
			//x[4] = 1;
		if((a & ~b & ~c & ~d) | (~a & b & ~c & ~d) | (a & b & ~c & ~d) == 1'b1)
		// if((d | (~b & ~a) | (c & ~b) | (c & ~a)) == 1'b0)
			x = x | 7'b0100000;
			//x[5] = 1;
		if((~a & ~b & ~c & ~d) | (a & ~b & ~c & ~d) | (a & b & c & ~d) == 1'b1)
		// if((d | (c & ~b) | (~c & b) | (b & ~a)) == 1'b0)
			x = x | 7'b1000000;
			//x[6] = 1;
	end

	/*****************************************
	必要なモジュールのインスタンスを作成すること
	ヒント：演算ごとにインスタンスが必要
	******************************************/
	// m_or2 m_or_0()

endmodule