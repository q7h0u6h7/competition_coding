#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

/* There are a number of factoization algorithms written by very samrt people.
   I should learn some.  In the meantime, I have implemented a naieve algorithm
   that I beleive is O(sqrt(n)).
*/

int get_sum_of_divs(int input_int){
  if (input_int == 1){
    return 0; // 1 is apparently defficient 
  }

  int sum_of_divisors = 1; //appraently 1 counts when checking for divisors...
  float max_possible = sqrt(input_int);
  //cout << "THE # IS: " << input_int << " " << sqrt(input_int) << endl;
  for (int i=2;
       i < max_possible; //needs to be less than with seperate check at end to avoid couting sqrt twice
       ++i){
    if (input_int % i == 0){
      sum_of_divisors += i;
      sum_of_divisors += (input_int /i);
      //cout << "\tis div by: " << i << " " << input_int / i << endl;
      //cout << "\t\tsum of divs = " << sum_of_divisors << endl;
      if (sum_of_divisors > input_int){
	break;
      }
    }
  }
  int int_sqrt = floor(max_possible);
  if (int_sqrt == max_possible and int_sqrt > 1){
    sum_of_divisors += int_sqrt;
  }

  //cout << "\t\tfinal sum of divs = " << sum_of_divisors << endl;
  return sum_of_divisors;
}    


int main(){
  cout << "PERFECTION OUTPUT" << endl;
  int input_int;
  int sum_of_divisors;
  string perfect;
  while (cin >> input_int and input_int != 0){
    sum_of_divisors = get_sum_of_divs(input_int);
    if (sum_of_divisors < input_int){
      perfect = "DEFICIENT";
    }
    else if (sum_of_divisors == input_int){
      perfect = "PERFECT";
    }
    else if (sum_of_divisors > input_int){
      perfect = "ABUNDANT";
    }
    printf("%5d", input_int);
    cout << "  "<<  perfect << endl;
  }
  cout << "END OF OUTPUT" << endl;
}
