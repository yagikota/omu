# 1201201140
# 八木洸太

{
    sum += $1
    square_sum += $1 * $1;
}

END {
    avg = sum / NR;
    # 標本分散
    variance = square_sum / NR - avg * avg;
    print(variance);
}

# 講義や課題に関するコメント
# 型付けがないので楽だった。
