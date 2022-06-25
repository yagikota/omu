# 1201201140
# 八木洸太

from audioop import avg, maxpp
from csv import reader
from mimetypes import init
from pickle import NONE
from math import sqrt
PASSING_SCORE = 60
TEST_NUM = 5


def csv_to_list(filename):
    with open(filename, 'r') as read_obj:
        csv_reader = reader(read_obj)
        return list(csv_reader)

def write_score_details(students, avg_score_list, max_scores_list, min_scores_list, std_deviations_list, f):
    f.write("＜課題の平均点, 最高点, 最低点, 偏差値の情報＞\n")
    f.write("課題数 5\n")
    f.write("学生人数 20\n")
    for i in range(TEST_NUM):
        f.write("<課題{0}>\n".format(i+1))
        f.write("平均点:{0}点\n".format(avg_score_list[i]))

        max_score = max_scores_list[i]
        f.write("最高点: {0}点\n".format(max_score))
        s_list = get_max_score_students_list(students, max_score, i)
        f.write("最高点取得学生: {0}名\n".format(len(s_list)))
        for idx, student in enumerate(s_list):
            f.write("{0}: {1}\n".format(idx+1, student.id))

        min_score = min_scores_list[i]
        f.write("最低点: {0}点\n".format(min_score))
        s_list = get_min_score_students_list(students, min_score, i)
        f.write("最低点取得学生: {0}名\n".format(len(s_list)))
        for idx, student in enumerate(s_list):
            f.write("{0}: {1}\n".format(idx+1, student.id))

        f.write("偏差値\n")
        for j in range(6):
            min_dev_val = 20 + j * 10
            max_dev_val = min_dev_val + 10
            counter = count_students_with_deviation_value(students, min_dev_val, max_dev_val, i)
            f.write("{0}~{1}: {2}名\n".format(min_dev_val, max_dev_val, counter))
        f.write("\n")

class Student:
    def __init__(self, s_id, name, scores):
        self.id = s_id
        self.name = name
        self.score1 = scores[0]
        self.score2 = scores[1]
        self.score3 = scores[2]
        self.score4 = scores[3]
        self.score5 = scores[4]
        self.deviation_value1 = 0
        self.deviation_value2 = 0
        self.deviation_value3 = 0
        self.deviation_value4 = 0
        self.deviation_value5 = 0

    def get_scores(self):
        return [self.score1, self.score2, self.score3, self.score4, self.score5]

    def get_deviation_values(self):
            return [self.deviation_value1, self.deviation_value2, self.deviation_value3, self.deviation_value4, self.deviation_value5]

    def set_deviation_values(self, std_deviations_list, avg_scores_list):
        self.deviation_value1 = 50 + 10 * (self.score1 - avg_scores_list[0]) / std_deviations_list[0]
        self.deviation_value2 = 50 + 10 * (self.score2 - avg_scores_list[1]) / std_deviations_list[1]
        self.deviation_value3 = 50 + 10 * (self.score3 - avg_scores_list[2]) / std_deviations_list[2]
        self.deviation_value4 = 50 + 10 * (self.score4 - avg_scores_list[3]) / std_deviations_list[3]
        self.deviation_value5 = 50 + 10 * (self.score5 - avg_scores_list[4]) / std_deviations_list[4]

    def print_info(self):
        print(self.id, self.name, self.score1, self.score2, self.score3, self.score4, self.score5,
            self.deviation_value1, self.deviation_value2, self.deviation_value3, self.deviation_value4, self.deviation_value5)

def init_students(df):
    students = [None] * len(df)
    for i in range(len(df)):
        s_id = int(df[i][0])
        name = df[i][1]
        scores = list(map(int, df[i][2:]))
        student = Student(s_id, name, scores)
        students[i] = student
    return students

def print_students_info(students):
    for s in students:
        s.print_info()

def get_avg_scores_list(students):
    scores_sum = students[0].get_scores()
    for student in students[1:]:
        scores_sum  = [x + y for x, y in zip(scores_sum, student.get_scores())]
    return [score_sum / len(students) for score_sum in scores_sum]

def get_max_scores_list(students):
    max_scores_list = []
    for i in range(TEST_NUM):
        max_score = max([s.get_scores()[i] for s in students])
        max_scores_list.append(max_score)
    return max_scores_list

def get_min_scores_list(students):
    min_scores_list = []
    for i in range(TEST_NUM):
        max_score = min([s.get_scores()[i] for s in students])
        min_scores_list.append(max_score)
    return min_scores_list

def get_std_deviations_list(students, avg_scores_list):
    std_deviations_list = []
    for i in range(TEST_NUM):
        rest_pow_sum = sum([pow(s.get_scores()[i] - avg_scores_list[i], 2) for s in students])
        std_deviation = sqrt(rest_pow_sum / len(students))
        std_deviations_list.append(std_deviation)
    return std_deviations_list

def set_deviation_values_to_students(students, std_deviations_list, avg_scores_list):
    for s in students:
        s.set_deviation_values(std_deviations_list, avg_scores_list)

# 課題iの最高得点者
def get_max_score_students_list(students, max_score, i):
    students_list = []
    for s in students:
        if s.get_scores()[i] == max_score:
            students_list.append(s)
    return students_list

# 課題iの最低得点者
def get_min_score_students_list(students, min_score, i):
    students_list = []
    for s in students:
        if s.get_scores()[i] == min_score:
            students_list.append(s)
    return students_list

def count_students_with_deviation_value(students, min_dev_val, max_dev_val, i):
    counter = 0
    for s in students:
        dev_val = s.get_deviation_values()[i]
        if dev_val > min_dev_val and dev_val < max_dev_val:
            counter += 1
    return counter

if __name__ == "__main__":
    input_filename = "2022_en3_kadai08_rep02_testdata.csv"
    output_filename = "report-10-01-1201201140-out.txt"

    df = csv_to_list(input_filename)

    students = init_students(df)

    avg_scores_list = get_avg_scores_list(students)
    print(avg_scores_list)
    max_scores_list = get_max_scores_list(students)
    print(max_scores_list)
    min_scores_list = get_min_scores_list(students)
    print(min_scores_list)
    std_deviations_list = get_std_deviations_list(students, avg_scores_list)
    print(std_deviations_list)

    set_deviation_values_to_students(students, std_deviations_list, avg_scores_list)
    print_students_info(students)

    with open(output_filename, "w") as f:
        write_score_details(students, avg_scores_list, max_scores_list, min_scores_list, std_deviations_list, f)