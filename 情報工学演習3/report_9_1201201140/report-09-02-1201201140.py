# 1201201140
# 八木洸太

def v_sum(v1, v2):
    return [x + y for (x, y) in zip(v1, v2)]

def m_sum(m1, m2):
    result = []
    for i in range(len(m1)):
        result.append(v_sum(m1[i], m2[i]))
    return result

def m_pow(m1, m2):
    result = []
    for i in range(len(m1)):
        row = []
        for j in range(len(m2[0])):
            tmp = 0
            for k in range(len(m1[0])):
                tmp += m1[i][k] * m2[k][j]
            row.append(tmp)
        result.append(row)
    return result


if __name__ == "__main__":
    m = 3
    n = 2

    matrix1 = [[1 for _ in range(n)]] * m

    matrix2 = [[2 for _ in range(n)]] * m

    matrix3 = [[2 for _ in range(m)]] * n

    print(matrix1)
    print(matrix2)
    print(matrix3)

    # 行列の和
    # [[1, 1], [1, 1], [1, 1]]と
    # [[2, 2], [2, 2], [2, 2]]の和
    print(m_sum(matrix1, matrix2)) # [[3, 3], [3, 3], [3, 3]]

    # 行列の積
    # [[1, 1], [1, 1], [1, 1]]と
    # [[2, 2, 2], [2, 2, 2]]の積
    print(m_pow(matrix1, matrix3)) # [[4, 4, 4], [4, 4, 4], [4, 4, 4]]
