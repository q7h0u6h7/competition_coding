#include <iostream>
#include <stack>

using namespace std;

bool is_valid(string inputstring){
  stack<char> mystack;
  for (string::iterator it = inputstring.begin();
       it != inputstring.end();
       ++it){
    if (*it == '(' or *it == '['){
      mystack.push(*it);
    }
    else{
      if (mystack.size() == 0){
        return false;
      }      
      if (*it == ')'){
        if (mystack.top() != '('){
          return false;
        }
        mystack.pop();
      }
      else if (*it == ']'){
        if (mystack.top() != '['){
          return false;
        }
        mystack.pop();
      }
      else{
        return false;
      }
    }
  }
  if (mystack.size() != 0){
    return false;
  }
  return true;
}

int main(){
  cin.ignore(256, '\n'); // ignore the number of lines and just loop until cin goes away
  string inputstring;
  while (cin >> inputstring){
    if (is_valid(inputstring)){
        cout << "Yes" << endl;
      }
    else{
      cout << "No" << endl;
    }
  }
}
