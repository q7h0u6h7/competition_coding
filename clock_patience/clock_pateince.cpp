#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Card{
private:
  map <string, int> rank_2_pos;
  string suit;
  string rank;
public:
  Card(char, char);
  string get_suit();
  string get_rank();
  int get_pos();
  bool is_down;
};

Card::Card(char r, char s){
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
  is_down = true;
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

class Table{
private:
   vector< vector<Card*> > piles;
public:
  void setup_game(vector<string>);
  Table(): piles(13){};
};

void Table::setup_game(vector<string> rank_suits){
  //Card a_card(rs[0], rs[1]);
  //table[( 12 - (i % 13) )].push_back(&a_card);
  for (vector<string>::iterator i)
}

bool play_game(){
  // Setup table
  string rs;
  
 // Play game
  //cout << table[0][0]->get_rank()<< endl;
}

int main(){
  while (cin){
    Table a_table;
    vector<string> rank_suits;
    string rs;
    for (int i=0; i<52; i++){
      cin >> rs;
      if (rs.compare("#") == 0){
        return false;
      }
      rank_suits.push_back(rs);
    }
    a_table.setup_game(rank_suits);
  }
}

