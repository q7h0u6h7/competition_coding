#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Card{
  map <string, int> rank_2_pos;
  string suit;
  string rank;
public:
  Card(string, string);
  string get_suit();
  string get_rank();
  int get_pos();
  bool is_down;
};

Card::Card(string r, string s){
  rank = r;
  suit = s;
  rank_2_pos["1"] = 1;
  rank_2_pos["2"] = 2;
  rank_2_pos["3"] = 3;
  rank_2_pos["4"] = 4;
  rank_2_pos["5"] = 5;
  rank_2_pos["6"] = 6;
  rank_2_pos["7"] = 7;
  rank_2_pos["8"] = 8;
  rank_2_pos["9"] = 9;
  rank_2_pos["J"] = 10;
  rank_2_pos["Q"] = 11;
  rank_2_pos["K"] = 12;
  rank_2_pos["A"] = 13;
}

string Card::get_suit(){
  return suit;
}

string Card::get_rank(){
  return rank;
}

int Card::get_pos(){
  return rank_2_pos[rank];
}

bool play_game(){
  string rs;
  for (int i=0; i<52; i++){
    cin >> rs;
    if (rs.compare("#") == 0){
      return false;
    }
    cout << i << rs << endl;
  }
}
int main(){
  while (cin){
    if (not play_game()){
      break;
    }
  }
}
