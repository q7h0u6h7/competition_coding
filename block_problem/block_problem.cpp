#include <iostream>
#include <vector>
#include <map>

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
  vector< vector< Block* > > bins;
  map <int, Block* > blocks;
  int get_current_bin_from_block_num(int);
  pair < int, vector <int> > clear_off_top(int);
  void pile(int, int);
  //void move(int, int);
public:
  void move(int, int);
  Board(int);
  ~Board();
  friend ostream& operator<<(ostream&, const Board&);
  bool is_illegal_move(int, int);
  void move_onto(int, int);
  void move_over(int, int);
  void pile_onto(int, int);
  void pile_over(int, int);
};

Board::Board(int num_bins){
  for (int i=0; i<num_bins; i++){
    Block* a_block = new Block(i);
    blocks[i] = a_block;
    vector <Block*> v;
    v.push_back(a_block);
    bins.push_back(v);
  }
}

Board::~Board(){
  int s = bins.size();
  for (int i=0; i < bins.size(); i++){
    for (int j=0; j < bins[i].size(); j++){
      delete bins[i][j];
    }
  }
}

ostream& operator<<(ostream& os, const Board& a_board){
  for (int i=0; i < a_board.bins.size(); i++){
    os << i << ':';
    for (vector< Block* >::const_iterator it = a_board.bins[i].begin(); 
 	 it != a_board.bins[i].end(); ++it){
      os << " " << (**it).get_birth_bin();
    }
    os << endl;
  }
  return os;
}

int Board::get_current_bin_from_block_num(int block_num){
  return (*blocks[block_num]).get_current_bin();
}

bool Board::is_illegal_move(int a, int b){
  if (a==b){
    return true;
  }
  if (get_current_bin_from_block_num(a) == get_current_bin_from_block_num(b)){
    return true;
  }
  return false;
}

pair< int, vector< int > > Board::clear_off_top(int block_num){
  int bin = get_current_bin_from_block_num(block_num);
  Block last_block = *bins[bin].back();
  vector <int> removed_block_nums;
  while (last_block.get_birth_bin() != block_num){
    int birth_bin = last_block.get_birth_bin();
    removed_block_nums.push_back(birth_bin);
    move(bin, birth_bin);
    last_block = *bins[bin].back();
  }
  return make_pair(bin, removed_block_nums);
}

void Board::move(int old_bin, int new_bin){
  Block* a_block = bins[old_bin].back();
  (*a_block).set_current_bin(new_bin);
  bins[old_bin].pop_back();
  bins[new_bin].push_back(a_block);
}

void Board::pile(int block_num_a, int new_bin){
  pair< int, vector< int > > ret = clear_off_top(block_num_a);
  int old_bin = ret.first;
  vector <int> removed_block_nums = ret.second;
  move(old_bin, new_bin);
  for (vector< int >::reverse_iterator it = removed_block_nums.rbegin(); 
       it != removed_block_nums.rend(); ++it){
    move(*it, new_bin);
  }
}

void Board::move_onto(int block_num_a, int block_num_b){
  int old_bin = clear_off_top(block_num_a).first;
  int new_bin = clear_off_top(block_num_b).first;
  move(old_bin, new_bin);
}

void Board::move_over(int block_num_a, int block_num_b){
  int old_bin = clear_off_top(block_num_a).first;
  int new_bin = get_current_bin_from_block_num(block_num_b);
  move(old_bin, new_bin);
}

void Board::pile_onto(int block_num_a, int block_num_b){
  int new_bin = clear_off_top(block_num_b).first;
  pile(block_num_a, new_bin);
}

void Board::pile_over(int block_num_a, int block_num_b){
  int new_bin = get_current_bin_from_block_num(block_num_b);
  pile(block_num_a, new_bin);
}


int main(){
  int num_blocks;
  cin >> num_blocks;
  Board a_board(num_blocks);
  a_board.move(1,5);
  a_board.move(3,5);
  a_board.move(8,5);
  a_board.move(9,6);
  a_board.move(7,6);
  cout << a_board << endl;
  //a_board.move_onto(5,6);
  //a_board.move_over(5,6);
  //a_board.pile_onto(5,6);
  a_board.pile_over(5,6);
  cout << a_board;
}
