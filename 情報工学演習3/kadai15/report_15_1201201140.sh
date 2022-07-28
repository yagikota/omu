# 1201201140
# 八木洸太

#!/bin/sh

# 発生させる座標の数
M=$1
# 乱数の種の生成で用いる
# SEED=$2
# 求めるpiの数
N=10
# スクリプトの出力結果を保存するファイルの相対パス
OUT_FILE1="./report_15_1201201140-$M.txt"
# Mとpiの標本分散を記録するファイルの相対パス
OUT_FILE2="./report_15_1201201140.txt"
# piを求めるバイナリファイルの相対パス
BIN_FILE="./report_15_1201201140"
# スクリプト内で実行するawkファイルの相対パス
AWK_FILE="./report_15_1201201140.awk"

I=0
while test $I -lt $N
do
	# 乱数の種の生成で用いる
	read -p "SEED: " SEED
	# piを求めるプログラムを実行し結果をPIに代入
	PI=`$BIN_FILE $M $SEED`
	# 結果をファイルに追記
	`echo $PI >> $OUT_FILE1`
	I=`expr $I + 1`
done

# awkで標本分散を計算し結果を受け取る D: piの標本分散
D=`awk -f $AWK_FILE $OUT_FILE1`
# Mとpiの標本分散を記録する
OUT="$M $D"
`echo $OUT >> $OUT_FILE2`

# 講義や課題に関するコメント
# N回の実行で乱数の種を変える処理をする際、どのようにすればいいのかわからなかった。