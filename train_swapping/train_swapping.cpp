#include <iostream>
#include <list>
#include <sstream>

using namespace std;

int get_num_swaps(list<int> cars){
  /*
    The idea is to count the number of cars with a higher number that
    are ahead in the list, 

    e.g., for 3,2,4,1 

    3 has no elements ahead of it (so it contributes 0) 
    2 has 1 larger element ahead of it
    4 has no larger elements ahead of it
    1 has 3 larger elements ahead of it

    so the number of swaps is 1 + 3 = 4.

    I think a reasonably efficient way to implement this 
    is with a merge sort and counting the number of times 
    an element is chosen from the right side during merge
    (I think it would be O(n*log(n)).

    For now, a naive approach is taken, i.e., for each
    element, count the number if larger elements in front of 
    it (which I thin is O(n^2)).
   */
  int i = 0;
  list<int> in_front_of;
  for (list<int>::iterator it = cars.begin();
       it != cars.end();
       ++ it){
    for (list<int>::iterator jt = in_front_of.begin();
	 jt != in_front_of.end();
	 ++jt){
      if (*it < *jt){
	++i;
      }
    }
    in_front_of.push_back(*it);
  }
  return i;
}


void split(string line, list<int> &cars){
  //string s = "1 2 3";
  istringstream ss(line);
  int car_num;
  while (ss >> car_num){
    cars.push_back(car_num);
  }      
}

int main(){
  string line;
  // could use the line nums, etc to contorl loops, 
  // but instead let's ignore them.
  getline(cin, line); //number of trains, discard
  int car_num;
  int num_swaps;
  while (getline(cin, line)) { //number of cars, discard
    list<int> cars;
    getline(cin, line); //car order, keep this
    split(line, cars);
    num_swaps = get_num_swaps(cars);
    cout << "Optimal train swapping takes " << num_swaps << " swaps." << endl;
  }
}
