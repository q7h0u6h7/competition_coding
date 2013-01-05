#include <iostream>
#include <vector>
#include <typeinfo>

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
  vector < vector <Block*> > bins;
  //vector< vector< int > > bins;
public:
  //vector< vector< int > > bins;
  Board(int);
  ~Board();
  friend ostream& operator<<(ostream& os, const Board& dt);
  //void print_board();
};

Board::Board(int num_bins){
  for (int i=0; i<num_bins; i++){
    Block* a_block = new Block(i);
    vector <Block*> v;
    v.push_back(a_block);

    //vector< int > v;
    //v.push_back(i);

    bins.push_back(v);
    cout << i << ':' << &v << "--" << v.size() << ';' << (*a_block).get_birth_bin() << endl;
  }
}

Board::~Board(){

}

ostream& operator<<(ostream& os, const Board& a_board){
  int s = a_board.bins.size();
  for (int i=0; i < s; i++){
    os << i << ':';
    for (vector< Block* >::const_iterator it = a_board.bins[i].begin(); 
 	 it != a_board.bins[i].end(); ++it){
      cout << (**it).get_current_bin() << endl;
    }
  }
  return os;
}

int main(){
  int num_blocks;
  cin >> num_blocks;
  Board a_board(num_blocks);
  //a_board.print_board();
  cout << a_board;
//   for (vector< vector< int > >::iterator it = (a_board).bins.begin(); it != (a_board).bins.end(); ++it){
//     for (vector< int >::iterator jt = (*it).begin(); jt != (*it).end(); ++jt){
//       cout << *jt;
//     }
//   }
}
