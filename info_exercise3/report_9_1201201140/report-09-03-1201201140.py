# 1201201140
# 八木洸太

import cmath
from math import sqrt


if __name__ == "__main__":
    print("ax^2+bx+c=0の解を求めるプログラム")
    print("a:")
    a = int(input())
    print("b:")
    b = int(input())
    print("c:")
    c = int(input())

    # 動作確認に用いた値と出力結果
    # a=0, b=0, c=1: 解なし
    # a=0, b=1, c=2: 解: -2.0
    # a=1, b=4, c=4: 解: -2.0
    # a=1, b=4, c=5: 解: (-2+1j) (-2-1j)
    # a=1, b=4, c=1: 解: -0.2679491924311228 -3.732050807568877

    if a == 0 and b == 0:
        print("解なし")
    elif a == 0:
        print("解:", -c / b)
    else:
        D = b**2-4*a*c
        if D == 0:
            print("解:", -b / (2 * a))
        elif D > 0:
            ans1 = (-b + sqrt(D)) / (2 * a)
            ans2 = (-b - sqrt(D)) / (2 * a)
            print("解:", ans1, ans2)
        else:
            ans1 = (-b + cmath.sqrt(D)) / (2 * a)
            ans2 = (-b - cmath.sqrt(D)) / (2 * a)
            print("解:", ans1, ans2)
