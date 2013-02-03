#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <numeric>
#include <cmath> //note that there is math.h and cmath and how this works is compiler dependent

using namespace std;

int main(){
  int num_bins;
  int num_per_bin;
  vector<int> bins;
  string line;
  string _;
  int num_bricks;
  int set_num = 0;
  while (cin){
    cin >> num_bins;
    getline(cin, _); // throw away newline
    if (!num_bins){
      break;
    }
    ++set_num;
    getline(cin, line);
    istringstream is(line);
    vector<int> bins(istream_iterator<int>(is),
                     (istream_iterator<int>()) ); //extra parens necessary to prevent compiler from considering this a function
    num_per_bin = accumulate(bins.begin(), bins.end(), 0) / num_bins;
    num_bricks = 0;
    for (vector<int>::iterator it = bins.begin();
         it != bins.end();
         ++it){
      num_bricks += std::abs(*it - num_per_bin);
    }
    cout << "Set #" << set_num << endl;
    cout << "The minimum number of moves is " << num_bricks / 2 << "." << endl << endl; // Note the 2nd endl due to "output empty line after each set."
  }
}
