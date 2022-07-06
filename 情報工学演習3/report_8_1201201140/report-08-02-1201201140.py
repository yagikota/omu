# 1201201140
# 八木洸太

from csv import reader

PASSING_SCORE = 60
TEST_NUM = 5


def csv_to_list(filename):
    with open(filename, 'r') as read_obj:
        csv_reader = reader(read_obj)
        return list(csv_reader)

def print_df(df):
    for row in df:
        print(row)

def write_score_details(df, max_score_and_idx_list, min_score_and_idx_list, avg_score_list, f):
    f.write("＜課題の平均点，最高点，最低点＞\n")
    for i in range(len(max_score_and_idx_list)):
        f.write("課題{0}\n".format(i+1))
        f.write("平均点:{0}点\n".format(avg_score_list[i]))
        max_score_idx = max_score_and_idx_list[i][1]
        f.write("最高点: {0} {1}点\n".format(df[max_score_idx][1] ,df[max_score_idx][i+2]))
        min_score_idx = min_score_and_idx_list[i][1]
        f.write("最低点: {0} {1}点\n".format(df[min_score_idx][1] ,df[min_score_idx][i+2]))
        f.write("\n")

def write_pass_or_not(df, f):
    f.write("＜各課題合否＞\n")
    for i in range(TEST_NUM):
        f.write("＜課題{0}＞\n".format(i+1))
        for j in range(len(df)):
            record = df[j]
            if int(record[i+2]) > PASSING_SCORE:
                judge = "合格"
            else:
                judge = "不合格"
            f.write("{0}: {1} {2}点 {3}\n".format(i+1, record[1], record[i+2], judge))
        f.write("\n")
    f.write("\n")

if __name__ == "__main__":
    input_filename = "2022_en3_kadai08_rep02_testdata.csv"
    output_filename = "2022_en3_kadai08_rep02_testdata_out.txt"

    df = csv_to_list(input_filename)
    print_df(df)
    # 各教科の最高点，最低点，平均点を順に格納
    max_score_and_idx_list = [None] * TEST_NUM
    min_score_and_idx_list = [None] * TEST_NUM
    avg_score_list = [None] * TEST_NUM
    for i in range(TEST_NUM):
        scores = [int(record[i+2]) for record in df]
        max_score = max(scores)
        min_score = min(scores)
        avg_score = sum(scores) / len(df)
        max_score_and_idx_list[i] = (max_score,scores.index(max_score))
        min_score_and_idx_list[i] = (min_score, scores.index(min_score))
        avg_score_list[i] = avg_score
    print(max_score_and_idx_list)
    print(min_score_and_idx_list)
    print(avg_score_list)

    with open(output_filename, "w") as f:
        write_score_details(df, max_score_and_idx_list, min_score_and_idx_list, avg_score_list, f)
        write_pass_or_not(df, f)

