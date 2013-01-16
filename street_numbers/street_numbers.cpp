#include <iostream>
#include <cmath>

using namespace std;

double compute_sum(double n, double m, double sum){
  return n * n + n + m - m * m - 2 * sum;
}

int print_house_nums(double house_num){
  double sum;
  sum = (house_num * (house_num - 1)) / 2;
  double n = floor(sqrt( (-1) * compute_sum(0, house_num+1, sum)));
  if (compute_sum(n, house_num+1, sum) == 0){
    printf ("%10.0lf", house_num);
    printf ("%10.0lf \n", n);
    return 1;
  }
  return 0;
}


int main(){
  int num_printed = 0;
  int i = 2;
  cout.precision(10);
  while (num_printed < 10){
    if (print_house_nums(i) == 1){
      ++num_printed;
    }
    ++i;
  }

}

