#include <iostream>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int char_2_int(char c){
  return int(c) - int('a') + 1;
}

long encode(string word){
  int enc = 0;
  int last_letter = 27;
  int exp = 0;
  for (string::reverse_iterator it = word.rbegin();
       it != word.rend();
       it++){
    int letter = char_2_int(*it);
    if (last_letter <= letter){
      return 0;
    }
    last_letter = letter;
    long mult = pow(26.0, exp);
    //cout <<  "M " << mult << endl;
    enc += (letter) * mult  - (letter * exp);
    ++exp;
  }
  return enc;
}

int naieve(string word){
  int word_num = 1;
  string test_word;
  for (int m=0; m<26; ++m){
    stringstream tmp;
    tmp << char(m + int('a'));
    tmp >> test_word;
    if (word.compare(test_word) == 0){
      return word_num;
    }
    ++word_num;
  }

  for (int m=0; m<26; ++m){
    for (int l=m+1; l<26; ++l){
      stringstream tmp;
      tmp << char(m + int('a')) 
	  << char(l + int('a'));
      tmp >> test_word;
      if (word.compare(test_word) == 0){
	return word_num;
      }
      ++word_num;
    }
  }

  for (int m=0; m<26; ++m){
    for (int l=m+1; l<26; ++l){
      for (int k=l+1; k<26; ++k){
	stringstream tmp;
	tmp << char(m + int('a')) 
	    << char(l + int('a')) 
	    << char(k + int('a'));
	tmp >> test_word;
	if (word.compare(test_word) == 0){
	  return word_num;
	}
	++word_num;
      }
    }
  }
  
  for (int m=0; m<26; ++m){
    for (int l=m+1; l<26; ++l){
      for (int k=l+1; k<26; ++k){
	for (int j=k+1; j<26; ++j){
	  stringstream tmp;
	  tmp << char(m + int('a')) 
	      << char(l + int('a')) 
	      << char(k + int('a')) 
	      << char(j + int('a'));
	  tmp >> test_word;
	  if (word.compare(test_word) == 0){
	    return word_num;
	  }
	  ++word_num;
	}
      }
    }
  }

  for (int m=0; m<26; ++m){
    for (int l=m+1; l<26; ++l){
      for (int k=l+1; k<26; ++k){
	for (int j=k+1; j<26; ++j){
	  for (int i=j+1; i<26; ++i){
	    stringstream tmp;
	    tmp << char(m + int('a')) 
		<< char(l + int('a')) 
		<< char(k + int('a')) 
		<< char(j + int('a')) 
		<< char(i + int('a'));
	    tmp >> test_word;
	    if (word.compare(test_word) == 0){
	      return word_num;
	    }
	    ++word_num;
	  }
	}
      }
    }
  }
}

int main(){
  string word;
  while (cin >> word){
    cout << word << " " << naieve(word) << endl;
   }

//   int sum = 0;
//   for (int l=1; l<=26; ++l){
//     for (int k=1; k<l; ++k){
//       for (int j=1; j<k; ++j){
// 	for (int i=1; i<j; ++i){
// 	  sum += i;
// 	}
//       }
//     }
//   }
//   cout << sum << endl;

//   cout << char(97) << endl;
}  
