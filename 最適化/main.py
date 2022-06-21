# NN個の荷物があり、荷物iiは重さw[i]、利益v[i]とする。
# 許容重量がWWで、許容重量を超えず、かつ利益が最大になるような荷物の選択をする。
# https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E6%AC%A1%E5%9B%9E%E4%BB%A5%E9%99%8D%E3%81%AE%E4%BA%88%E5%AE%9A/
# https://zeronosu77108.hatenablog.com/entry/2017/12/25/131726
# python3 main.pyを実行


from csv import reader
import time

def csv_to_list(filename):
    with open(filename, 'r') as read_obj:
        csv_reader = reader(read_obj)
        return list(csv_reader)

# 利得が最大となるような組み合わせと合計サイズを全て表示
def print_combs_info(comb, price, size):
    total_price = 0
    for i in range(len(comb)):
        total_price += comb[i] * price[i]
    if total_price == max_price:
        print(comb)
        print_sizes(comb, size, total_price)

def print_sizes(comb, size, total_price):
    total_size = 0
    for i in range(len(comb)):
        total_size += comb[i] * size[i]
    if total_price == max_price:
        print(total_size)

if __name__ == "__main__":
    start = time.time()
    # 適宜ファイル名を変更
    input_filename = "input1.csv"
    df = csv_to_list(input_filename)

    # 各製品の容量と利益をcsvから抽出
    size = [int(c) for c in df[0]]
    price = [int(c) for c in df[1]]

    # 容量
    capacity = int(df[2][0])
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

            if curr_size > capacity :
                over_maz_size = True
                break

        if (not over_maz_size) and curr_price >= max_price :
            max_price = curr_price
            max_size = curr_size
            # combination = tmp_comb
            combination.append(tmp_comb)




    print("合計が最大になる組み合わせ（全て）")
    for comb in combination:
        print_combs_info(comb, price, size)


    # print(combination)

    print("合計価格: ", max_price)
    print("合計サイズ: ", max_size)
    print("実行時間:{0}(s)".format(time.time() - start))
