# 八木洸太
# 1201201140

import sys

def get_average(a, b, c):
    return (a + b + c) / 3

def get_max(a, b, c):
    max_score = a
    if a < b:
        max_score = b
    if max_score < c:
        max_score = c
    return max_score

def get_min(a, b, c):
    min_score = a
    if a > b:
        min_score = b
    if min_score > c:
        min_score = c
    return min_score


if __name__ == '__main__':
    scores = sys.argv[1:]
    a = int(scores[0])
    b = int(scores[1])
    c = int(scores[2])
    print("平均", get_average(a, b, c))
    print("最高点", get_max(a, b, c))
    print("最低点", get_min(a, b, c))
