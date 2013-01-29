#include <iostream>

using namespace std;

void decode(string line, int offset=7){
  for (string::iterator it = line.begin();
       it != line.end();
       ++it){
    cout << char(int( (*it) - offset ));
  }
  cout << endl;
}

int main(){
  string line;
  while (getline(cin, line)){
    decode(line);
  }
}
