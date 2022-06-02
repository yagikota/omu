# 1201201140
# 八木洸太

if __name__ == '__main__':
    scores = [100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50]
    passing_score = 60

    print("学生10名の課題の最高点，最低点，平均点を表示します．")
    print("最高点：", max(scores))
    print("最高点：", min(scores))
    print("最高点：", sum(scores) / len(scores))

    print("合否")
    for idx, val in enumerate(scores):
        if val >= passing_score:
            print("{0}：{1} 合格".format(idx+1, val))
        else:
            print("{0}：{1} 不合格".format(idx+1, val))
