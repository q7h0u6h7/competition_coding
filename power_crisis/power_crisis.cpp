#include <iostream>
#include <set>

using namespace std;

int get_last_region(int num_regions, int m){
  std::set<int> off_regions;
  off_regions.insert(1);
  int this_cnt = m;
  int last_region;
  while (off_regions.size() < num_regions){
    for (int this_region=2; this_region <= num_regions; this_region++){
      if (off_regions.count(this_region) == 0){
        this_cnt--;
      }
      if (this_cnt == 0){
        off_regions.insert(this_region);
        last_region = this_region;
        this_cnt = m;
      }
    }
  }
  return last_region;
}

int run_alg(int num_regions, int last_region=13){
  int m=1;
  while(m){
    if (get_last_region(num_regions, m) == last_region){
      break;
    }
    m++;
  }
  return m;
}

int main(){
  int num_regions;
  while (cin >> num_regions){
    if (num_regions == 0){
      break;
    }
    cout << run_alg(num_regions) << endl;
  }
}
