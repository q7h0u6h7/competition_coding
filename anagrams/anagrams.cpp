#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

int main(){
  vector <string> words;
  unordered_set <string> sorted_words;
  unordered_set <string> sorted_word_anagrams;
  string word;
  while (cin){
    cin >> word;
    if (word.compare("#") == 0){
      break;
    }
    words.push_back(word);
    string sorted_word = word;
    transform(sorted_word.begin(),
	      sorted_word.end(), 
	      sorted_word.begin(), 
	      ::tolower);
    sort(sorted_word.begin(), sorted_word.end());
    if (sorted_words.count(sorted_word) > 0){
	sorted_word_anagrams.insert(sorted_word);
    }
    else{
      sorted_words.insert(sorted_word);
    }
  }
  sort(words.begin(), words.end());
  for (vector <string>::iterator it = words.begin(); 
       it != words.end(); ++it){
    word = *it;
    string sorted_word = word;
    transform(sorted_word.begin(),
	      sorted_word.end(), 
	      sorted_word.begin(), 
	      ::tolower);
    sort(sorted_word.begin(), sorted_word.end());
    if (sorted_word_anagrams.count(sorted_word) == 0){
      cout << word << endl;
    }
  }
}
