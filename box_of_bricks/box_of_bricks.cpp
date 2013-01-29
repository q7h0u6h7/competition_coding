#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <numeric>


using namespace std;

int main(){
  int num_bins;
  int num_per_bin;
  //vector<int> bins;
  string line;
  while (cin){
    cin >> num_bins;
    if (!num_bins){
      break;
    }
    getline(cin, line);
    istringstream is(line);
    vector<int> bins(istream_iterator<int>(is),
                     istream_iterator<int>());
    for (vector<int>::iterator it = bins.begin();
         it != bins.end();
         ++it){
      cout << *it << endl;
    }
    //num_per_bin = accumulate(bins.begin(), bins.end(), 0);
  }
}
