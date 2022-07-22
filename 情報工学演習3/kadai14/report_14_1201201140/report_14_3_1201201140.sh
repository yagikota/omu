#!/bin/sh

# copy all files in current directory into ./bk directory
`mkdir -p bk`

DEST_DIR="./bk"
FILES=`ls -F | grep -v "/"`
INTERVAL=2

for FILE in $FILES
do
	`cp ./$FILE $DEST_DIR/`
	sleep $INTERVAL
done

# Name: 八木洸太
# No: 1201201140
# コメント:
# lsコマンドでファイル名だけを取得する方法やmkdirコマンドでディレクトリが存在しない時だけディレクトリを作成するオプション
# を知らなかったので勉強になった
