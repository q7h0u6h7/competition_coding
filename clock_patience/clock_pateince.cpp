#include <iostream>
#include <list>
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

ostream& operator<< (ostream& os, Card& a_card)
{
  os << a_card.get_rank() 
     << a_card.get_suit();
  return os;
}

Card::Card(char r, char s){
  rank = r;
  suit = s;
  rank_2_pos["A"] = 0;
  rank_2_pos["2"] = 1;
  rank_2_pos["3"] = 2;
  rank_2_pos["4"] = 3;
  rank_2_pos["5"] = 4;
  rank_2_pos["6"] = 5;
  rank_2_pos["7"] = 6;
  rank_2_pos["8"] = 7;
  rank_2_pos["9"] = 8;
  rank_2_pos["T"] = 9;
  rank_2_pos["J"] = 10;
  rank_2_pos["Q"] = 11;
  rank_2_pos["K"] = 12;
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
   vector< list<Card*> > piles;
public:
  void setup_game(vector<string>);
  Table(): piles(13){};
  bool play_game();
  friend ostream& operator<< (ostream&, Table&);
};

ostream& operator<< (ostream& os, Table& a_table)
{
  for (int i=0; i<13; i++){
    list <Card*> pile = a_table.piles[i];
    for (list <Card*>::iterator it = pile.begin();
	 it != pile.end();
	 ++it){
      os << **it << " ";
    }
    os << endl;
  }
  return os;
}

void Table::setup_game(vector<string> rank_suits){
  int i = 0;
  int pile_num;
  for (vector<string>::iterator it = rank_suits.begin();
       it != rank_suits.end(); 
       it++){
    Card *a_card = new Card( (*it)[0], (*it)[1]);
    pile_num = ( 12-(i % 13));
    piles[pile_num].push_front(a_card);
    ++i;
  }
}

bool Table::play_game(){
  int pile_num = 12; //first card is the last dealt
  Card a_card = *(piles[pile_num].back());
  int num_cards = 0;
  while (a_card.is_down){
    a_card.is_down = false;
    piles[pile_num].pop_back();
    pile_num = a_card.get_pos();
    piles[pile_num].push_front(&a_card);
    a_card = *(piles[pile_num].back());
    ++num_cards;
  };
  string zero = "";
  if (num_cards<10){
    zero = "0";
  }
  cout << zero << num_cards << "," << a_card << endl;
  return false;
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
    a_table.play_game();
  }
}
