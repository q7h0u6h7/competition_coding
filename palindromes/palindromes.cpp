#include <iostream>
#include <map>
#include <stack>

using namespace std;



string solve(string word, map<char, char> rev_map){
  stack<char>  myStack;
  bool is_palindrome = true;
  bool is_mirror = true;
  int i = 0;
  for (;
       i < (word.size() / 2);
       ++i){
    //cout << word[i];
    myStack.push(word[i]);
  }

  if (word.size() % 2){
    //cout << word[i];
    if (rev_map[word[i]] != word[i]){
      is_mirror = false;
    }
    ++i;
  }
  char match;
  for (;
       i < word.size();
       ++i){
    match = myStack.top();
    myStack.pop();
    //cout << match << " " << word[i] << endl;
    if (match != word[i]){
      is_palindrome = false;
    }
    if (match != rev_map[word[i]]){
      is_mirror = false;
    }
  }
  if (is_mirror){
    if (is_palindrome){
      return "is a mirrored palindrome.";
    }
    else{
      return "is a mirrored string.";
    }
  }
  if (is_palindrome){
    return "is a regular palindrome.";
  }
  return "is not a palindrome";
}

int main(){
  string word;
  map <char, char> fwd_map;
  map <char, char> bi_map;

  fwd_map['A'] = 'A';
  fwd_map['E'] = '3';
  fwd_map['H'] = 'H';
  fwd_map['I'] = 'I';
  fwd_map['J'] = 'L';
  fwd_map['M'] = 'M';
  fwd_map['O'] = 'O';
  fwd_map['S'] = '2';
  fwd_map['T'] = 'T';
  fwd_map['U'] = 'U';
  fwd_map['V'] = 'V';
  fwd_map['W'] = 'W';
  fwd_map['X'] = 'X';
  fwd_map['Y'] = 'Y';
  fwd_map['Z'] = '5';
  fwd_map['1'] = '1';
  fwd_map['8'] = '8';

  for (map<char,char>::iterator it=fwd_map.begin(); 
       it!=fwd_map.end(); 
       ++it){
    bi_map[it->first] = it->second;
    bi_map[it->second] = it->first;
  }

  while (cin >> word){
    cout  << word << " -- " << solve(word, bi_map) << endl;
    cout << endl;
  }
}
