#!/bin/sh

# fibonacci sequence
VAR1=0
VAR2=1

while test $VAR1 -lt 1000
do
	FIB_SEQ="$FIB_SEQ $VAR1"
	TMP=$VAR2
	VAR2=`expr $VAR1 + $VAR2`
	VAR1=$TMP
done
echo $FIB_SEQ

# Name: 八木洸太
# No: 1201201140
# コメント: 講義資料でヒントがあったので取り組みやすかった．
