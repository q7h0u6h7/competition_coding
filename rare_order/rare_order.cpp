#include <iostream>
#include <set>
#include <list>

using namespace std;


/*
  The idea behind this solution is to creat a list of ordered letter pairs.  
  Note that two properties must hold: 
   1) every letter must have its successive letter in a pair, and 
   2) there must be one letter that does not have any after it.
*/

void load_words(list<string> &words, set<char> &letters, list<char> &alphabet){
  string word;
  while (cin >> word and word != "#"){
    words.push_back(word);
    for (string::iterator it = word.begin();
         it != word.end();
         ++it){
      if (it == word.begin() and *it != alphabet.back()){
        alphabet.push_back(*it);
        }
      letters.insert(*it);      
    }
  }
}

void add_letter(string &prev_word, string &this_word, list<char> &alphabet){
  int i = 0;
  int max_len = min(prev_word.size(), this_word.size());
  for (; i < max_len; ++i){
    if (prev_word[i] != this_word[i]){
      break;
    }
  }
  if (i == 0 or i == max_len){
    return;
  }
  cout << prev_word << " " << this_word << " " << i << endl;
}

void add_letters(list<string> &words, list<char> &alphabet){
  string prev_word;
  string this_word;
  list<string>::iterator it = words.begin();
  this_word = *it;
  while (*it != words.back()){
    prev_word = this_word;
    this_word = *(++it);
    add_letter(prev_word, this_word, alphabet);
  }
}

int main(){
  list<string> words;
  set<char> letters;
  list<char> alphabet;
  load_words(words, letters, alphabet);
  while (alphabet.size() < letters.size()){
    add_letters(words, alphabet);
    break;
    //cout << letters.size() << " " << alphabet.size() << endl;
  }
}
