#include <iostream>

using namespace std;

int main(){
  string line;
  bool is_left = true;
  while (getline(cin, line)){
    for (string::iterator it = line.begin();
	 it != line.end();
	 ++it){
      if (*it == '"'){
	if (is_left == true){
	  cout << "``";
	  is_left = false;
	}
	else{
	  cout << "''";
	  is_left = true;
	}
      }
      else{
	cout << *it;
      }
    }
    cout << endl;
  }
}

