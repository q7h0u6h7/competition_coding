#include <iostream>
#include <map>
#include <list>
#include <set>

using namespace std;


/*
  The idea behind this solution is to creat a list of ordered letter pairs.  
  Note that two properties must hold: 
   1) every letter must have its successive letter in a pair, and 
   2) there must be one letter that does not have any after it.
*/

typedef map<char,list<char> > hash;

void add_letter(const string prev_word, const string this_word, hash &fwd_hash, hash &rev_hash, set<char> &letters){
  int i = 0;
  int max_len = min(prev_word.size(), this_word.size());
  for (; i < max_len; ++i){
    if (prev_word[i] != this_word[i]){
      break;
    }
  }
  if (i == max_len){
    return;
  }
  letters.insert(prev_word[i]);
  letters.insert(this_word[i]);
  fwd_hash[prev_word[i]].push_back(this_word[i]);
  rev_hash[this_word[i]].push_back(prev_word[i]);
}

void load_letters(hash &fwd_hash, hash &rev_hash, set<char> &letters){
  string prev_word;
  string this_word;
  cin >> prev_word;
  while (cin >> this_word and this_word != "#"){
    add_letter(prev_word, this_word, fwd_hash, rev_hash, letters);
    prev_word = this_word;
  }
}

void sort_letters(hash &fwd_hash, hash &rev_hash, set<char> letters, list<char> &alphabet){
  //get first letter
  for (set<char>::iterator it = letters.begin();
       it != letters.end();
       ++it){
    if (rev_hash.count(*it) == 0){
      alphabet.push_back(*it);
    }
  }
  // would define more vars to make the below readable, but chose not to for grins
  while (alphabet.size() < letters.size()){
    char next_letter;
    for (list<char>::iterator it= fwd_hash[alphabet.back()].begin();
	 it != fwd_hash[alphabet.back()].end();
	 ++it){
      rev_hash[*it].remove(alphabet.back());
      if (rev_hash[*it].size() == 0){
	next_letter = *it;
      }
    }
    alphabet.push_back(next_letter);
  }
}

int main(){
  list<char> alphabet;
  set<char> letters;
  hash fwd_hash;
  hash rev_hash;
  load_letters(fwd_hash, rev_hash, letters);
  sort_letters(fwd_hash, rev_hash, letters, alphabet);
  for (list<char>::iterator it = alphabet.begin();
       it != alphabet.end();
       ++it){
    cout << *it;
  }
  cout << endl;
}

