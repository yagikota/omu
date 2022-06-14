# NN個の荷物があり、荷物iiは重さw[i]、利益v[i]とする。
# 許容重量がWWで、許容重量を超えず、かつ利益が最大になるような荷物の選択をする。

if __name__ == "__main__":
    # 各製品の容量と利益
    size = [3, 5, 4, 2, 10, 7, 1, 5]
    price = [3, 7, 6, 3, 13, 9, 2, 6]

    # 容量
    capacity = 25
    # 製品の個数
    n = len(size)

    max_size = -1
    max_price = -1
    combination = []

    for i in range(2**n-1) :
        curr_size = 0
        curr_price = 0
        tmp_comb = []
        over_maz_size = False

        for j in range(n) :
            # シフトして１ビットずつ判断
            # TODO: 要説明
            is_put = i>>(n-j-1)&1
            tmp_comb.append(is_put)
            curr_size += is_put * size[j]
            curr_price += is_put * price[j]

            # capa を越えたらフラグを立てて break
            if curr_size > capacity :
                over_maz_size = True
                break

        if (not over_maz_size) and curr_price > max_price :
            max_price = curr_price
            max_size = curr_size
            combination = tmp_comb

    print("合計が最大になる組み合わせ")
    print(combination)
    print("合計価格: ", max_price)
    print("合計サイズ: ", max_size)

