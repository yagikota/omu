# 1201201140
# 八木洸太

from collections import Counter

def write_count_result(counter_list, f):
    f.write("単語: 出現回数\n")
    for word, counter in counter_list:
        f.write("{0}:{1}\n".format(word, counter))

if __name__ == "__main__":
    input_filename = "2022_en3_kadai08_rep01_test.txt"
    output_filename = "2022_en3_kadai08_rep01_test_out.txt"
    with open(input_filename, "r") as f:
        data = f.read().split()
        pretty_data = " ".join(filter(str.isalnum, data))
    word_list = pretty_data.split()
    c = Counter(word_list)
    counter_list = c.most_common()

with open(output_filename, "w") as f:
    write_count_result(counter_list, f)
