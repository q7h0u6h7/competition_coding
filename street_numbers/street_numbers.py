
from math import sqrt
from math import floor

def compute_sum(n, m, sum):
  return n * n + n + m - m * m - 2 * sum


def print_house_nums(house_num):
  sum = house_num * (house_num-1) / 2
  n = floor(sqrt( (-1) * compute_sum(0, house_num+1, sum)))
  if compute_sum(n, house_num+1, sum) == 0 and house_num < n:
    print house_num, int(n)
    return 1
  return 0


if __name__ == '__main__':
    num_printed = 0
    i = 2;
    #print_house_nums(204)
    while (num_printed < 10):
        if print_house_nums(i) == 1:
            num_printed += 1;
        i += 1

