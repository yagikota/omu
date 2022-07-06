# 1201201140
# 八木洸太

# 両面が赤，両面が青，表が赤で裏が青の3枚のカードがある．
# このカードを裏返すことを含めてシャッフルする．
# カードをランダムに１枚選び置いたとき，赤が見えた．
# このカードの裏が青である確率はいくつか？

# モンテカルロ法で確率を求める
from random import randint
# 試行回数
N = 10000

if __name__ == "__main__":
    # 赤: 0
    # 青: 1
    # カードの引き方 [表,裏]
    cards = [[0,0], [0,0], [1,1], [1,1], [0,1], [1,0]]

    a_and_b = 0
    b = 0
    for _ in range(N):
        idx = randint(0, 5)
        card = cards[idx]
        front, back = card[0], card[1]
        if front == 0:
            b += 1
            if back == 1:
                a_and_b += 1
    probability = a_and_b / b
    print(f"確率:{probability}")
