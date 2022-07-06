# 1201201140
# 八木洸太
import sys


if __name__ == '__main__':
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    c = int(sys.argv[3])

    print("2次方程式 ax^2+bx+c=0 の解がどのようになるか判別します．")
    print("a={0}, b={1}, c={2}".format(a, b, c))
    d = b**2-4*a*c
    print("判別式 b^2-4ac = {0}".format(d))
    if d == 0:
        print("重解")
    elif d > 0:
        print("2実数解")
    else:
        print("虚数解")

