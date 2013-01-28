#include <iostream>
#include <sstream>

using namespace std;


/*
The below won't work because you need to split words on anything that is not a letter.
 */

bool is_word(string word){
  for (string::iterator it = word.begin();
       it != word.end();
       ++it){
    if (isalpha(*it)){
      return true;
    }
  }
  return false;
}

int count_words(string line){
  stringstream ss(line);
  string word;
  int num_words = 0;
  while (ss >> word){
    if (is_word(word)){
      ++num_words;
    }
  }
  return num_words;
}

int main(){
  string line;
  while (getline(cin, line)){
    cout << count_words(line) << endl;
  }
}
