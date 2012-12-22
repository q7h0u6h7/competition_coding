#include <iostream>
#include <vector>

using namespace std;

class Block{
  int birth_bin;
  int current_bin;
public:
  Block(int);
  int get_current_bin();
  void set_current_bin(int);
  int get_birth_bin();
};

Block::Block(int bin_num){
  birth_bin = bin_num;
  current_bin = bin_num;
}

int Block::get_current_bin(){
  return current_bin;
}

void Block::set_current_bin(int bin){
  current_bin = bin;
}

int Block::get_birth_bin(){
  return birth_bin;
}


class Board{
  std::vector< vector <Block*> > bins;
  
public:
  Board(int);
  ~Board();
  friend ostream& operator<<(ostream& os, const Board& dt);
};

Board::Board(int num_bins){
  for (int i=0; i<num_bins; i++){
    Block a_block(i);
    vector <Block*> v;
    v.push_back(&a_block);
    bins.push_back(v);
  }
}

Board::~Board(){

}

ostream& operator<<(ostream& os, const Board& a_board){
  
  int s = (a_board).bins.size();
  for (int i=0; i < s; i++){
    os << i << ':';
    for (vector<Block*>::iterator it = a_board.bins[i].begin() ; it != a_board.bins[i].end(); ++it){
      cout << i << endl;
//       os << *it;
    }
  }
  return os;
}



int main(){
  int num_blocks;
  cin >> num_blocks;
  Board a_board(num_blocks);
  cout << a_board << endl;
}
