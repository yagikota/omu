#!/bin/sh

# change files name
DIR="./test_dir"
FILES=`ls $DIR`
EXT="go"

I=1
for FILE in $FILES
do
	`mv $DIR/$FILE $DIR/fruit$I.$EXT`
	I=`expr $I + 1`
done

# Name: 八木洸太
# No: 1201201140
# コメント: ディレクトリ名や拡張子の部分は切り離して，変更に強いようにした．
