from random import random, randint
import closeset_pair
MAX = 10000
MIN = -MAX
MAX_DATA = 1000001
MAX_DATA = 25

input_filepath = 'test_x.txt'
answer_filepath = 'test_y.txt'


def gen_datapoints(n_data):
    ret_list = []
    for _ in range(n_data):
        # x = random() * 2*MAX - MIN
        # y = random() * 2*MAX - MIN
        x = randint(MIN, MAX)
        y = randint(MIN, MAX)
        ret_list.append((x, y))

    return ret_list


if __name__ == '__main__':
    with open(answer_filepath, 'w') as f_ans:
        with open(input_filepath, 'w') as f_ipt:
            for n_data in range(2, MAX_DATA+1):
                data = gen_datapoints(n_data)
                data_str = [str(val) for point in data for val in point]

                datapoints = [closeset_pair.Point(x, y) for x, y in data]
                golden_ans = closeset_pair.bruteForce(
                    datapoints, len(datapoints))

                f_ipt.write(f'{n_data} ')
                f_ipt.write('\n')
                f_ipt.write(' '.join(data_str))
                f_ipt.write('\n')
                f_ans.write(f'{round(golden_ans, 3)}\n')
