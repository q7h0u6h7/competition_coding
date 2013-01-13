#include <iostream>
#include <vector>

using namespace std;

class Board{
private:
  int board_size;
  vector< int > board;
  int move_2_int(char);
public:
  Board():board_size(3), board(board_size * board_size){};
  void move(char);
  friend ostream& operator<<(ostream&, Board&);
};

int Board::move_2_int(char c){
  return int(c) - int('a');
}
void Board::move(char c_move){
  int i_move = move_2_int(c_move);
  //increment this square
  ++board[i_move];
  //increment square to left
  int left = i_move - 1;
  if (left >= 0 and
      left / 3 == i_move / 3){
    ++board[left];
  }
  //increment square to right
  int right = i_move + 1;
  if ( right / 3 == i_move / 3 ){
    ++board[right];
  }
  //increment square above
  int above = i_move - board_size;
  if (above >=0){
    ++board[above];
  }
  //increment square below
  int below = i_move + board_size;
  if (below < board_size * board_size){
    ++board[below];
  }
}

ostream& operator<<(ostream& os, Board& a_board){
  for (int i=0; i< (a_board.board_size*a_board.board_size); i++){
      os << a_board.board[i] << " ";
      if (i > 0 and 
	  (i+1) % a_board.board_size == 0 and
	  i < (a_board.board_size*a_board.board_size) -1){
	os << endl;
      }
  }
  return os;
}

int main(){
  string moves;
  int case_num = 1;
  while (getline(cin, moves)){
    Board a_board;
    for (string::iterator it = moves.begin();
	 it != moves.end();
	 it++){
      a_board.move((*it));
   }
    cout << "Case #" << case_num << ":" << endl;
    cout << a_board << endl;
    ++case_num;
  }
}
