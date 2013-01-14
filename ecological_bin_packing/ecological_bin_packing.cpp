#include <iostream>
#include <sstream>

using namespace std;

/*
naive solution:
brute force check all 6 possible solutions
(each solution cost computed by by summing 6 numbers)

other solutions:
?
 */

void naive_solve(long b1, long g1, long c1, 
                 long b2, long g2, long c2, 
                 long b3, long g3, long c3){
  string sol = "BCG";
  long min_moves, num_moves;
  //BCG
  min_moves = g1 + c1 + b2 + g2 + b3 + c3;

  //BGC
  num_moves = g1 + c1 + b2 + c2 + b3 + g3;
  if (num_moves < min_moves){ //ties go in lexigraphic order
    sol = "BGC";
    min_moves = num_moves;
  }
  //CBG
  num_moves = b1 + g1 + c2 + g2 + b3 + c3;
  if (num_moves < min_moves){
    sol = "CBG";
    min_moves = num_moves;
  }
  //CGB
  num_moves = b1 + g1 + b2 + c2 + c3 + g3;
  if (num_moves < min_moves){
    sol = "CGB";
    min_moves = num_moves;
  }
  //GBC
  num_moves = b1 + c1 + c2 + g2 + b3 + g3;
  if (num_moves < min_moves){
    sol = "GBC";
    min_moves = num_moves;
  }
  //GCB
  num_moves = b1 + c1 + b2 + g2 + c3 + g3;
  if (num_moves < min_moves){
    sol = "GCB";
    min_moves = num_moves;
  }
  cout << sol << " " << min_moves << endl;
}

int main(){
  string line;
  long b1, g1, c1, b2, g2, c2, b3, g3, c3;
  while (getline(cin, line)){
    stringstream words;
    words << line;
    words >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3;
    naive_solve(b1, g1, c1, b2, g2, c2, b3, g3, c3);
  }
}
