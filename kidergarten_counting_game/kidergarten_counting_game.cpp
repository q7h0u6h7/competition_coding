#include <iostream>

using namespace std;


/*
The below uses anything onther than alpha as a delimiter.
 */

int count_words(string line){

  bool current_isalpha = false;
  int word_count = 0;
  for (string::iterator it = line.begin();
       it != line.end();
       ++it){
    if (isalpha(*it)){
      if (not current_isalpha){
        ++word_count;
      }
      current_isalpha=true;
    }
    else{
      current_isalpha = false;
    }
  }
  return word_count;
}

int main(){
  string line;
  while (getline(cin, line)){
    cout << count_words(line) << endl;
  }
}
