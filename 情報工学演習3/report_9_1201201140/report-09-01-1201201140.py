# 1201201140
# 八木洸太

def v_sum(v1, v2):
    return [x + y for (x, y) in zip(v1, v2)]

def v_div(v1, v2):
    return [x - y for (x, y) in zip(v1, v2)]

def v_ip(v1, v2):
    return sum([x * y for (x, y) in zip(v1, v2)])



if __name__ == "__main__":
    v1 = [1, 2, 3]
    v2 = [4, 5, 6]

    # 和
    print(v_sum(v1, v2)) # [5, 7, 9]

    # 差
    print(v_div(v1, v2)) # [-3, -3, -3]

    # 内積
    print(v_ip(v1, v2)) # 32
