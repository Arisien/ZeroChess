#include <iostream>
#include <cmath>

using namespace std;

class Piece {
  public:
    string name;
    char symbol;
    int x;
    int y;
    bool captured;
    bool moved;
    bool color;
    int value;
    int index;

    Piece(){}
    Piece(int a, int b, bool c){
      x = a;
      y = b;
      color = c;
      captured = false;
      moved = false;
    }
    Piece(string n, int a, int b, bool c, int i){
      name = n;
      x = a;
      y = b;
      color = c;
      captured = false;
      moved = false;
      index = i;
    }
};

class King: public Piece {
  public:
    King(int a, int b, bool c):Piece(a,b,c) {
      name = "King";
      symbol = 'K';
      value = 10;
    }
};

class Pawn: public Piece {
  public:
    Pawn(int a, int b, bool c):Piece(a,b,c){
      name = "Pawn";
      symbol = 'P';
      value = 1;
    }
};

class Rook: public Piece {
  public:
      Rook(int a, int b, bool c):Piece(a,b,c){
        name = "Rook";
        symbol= 'R';
        value = 5;
      }
};

class Bishop: public Piece {
  public:
    Bishop(int a, int b, bool c):Piece(a,b,c){
      name = "Bishop";
      symbol = 'B';
      value = 3;
    }
};

class Queen: public Piece {
  public:
    Queen(int a, int b, bool c):Piece(a,b,c){
      name = "Queen";
      symbol = 'Q';
      value = 9;
    }
};

class Knight: public Piece {
  public:
    Knight(int a, int b, bool c):Piece(a,b,c){
      name = "Knight";
      symbol = 'N';
      value = 3;
    }
};

class Game {
  public:
    int index;
    int count;
    Piece pieces[32];
    string moves;
    Game() {
      index = 0;
      count = 0;
    }
    Piece getKing (bool color){
      for(int i=0; i<32; i++){
        if(pieces[i].name == "King" && pieces[i].color == color) return pieces[i];
      }
    }
    bool turn () {
      return count%2;
    }
    bool hasPiece(int a, int b){
      for(int i=0; i<32; i++){
        if(pieces[i].x == a && pieces[i].y == b) return true;
      }
      return false;
    }
    Piece getPiece (int a, int b){
      for(int i=0; i<32; i++){
        if(pieces[i].x == a && pieces[i].y == b) return pieces[i];
      }
    }
    bool inCheck () {
      bool color = !turn();

      Piece king = getKing(!color);

      for(int i=0; i<32; i++){
        if(pieces[i].captured || pieces[i].color != color) continue;
        if(isMove(pieces[i], king.x, king.y)) return true;
      }

    }
    bool isMove(Piece p, int a, int b) {
      if(p.captured) return false;
      if((a==p.x && b==p.y) || a<0 || b<0 || a>7 || b>7) return false;
      if(hasPiece(a,b) && getPiece(a,b).color == p.color) return false;
      if(p.name == "Bishop"){
        if(abs(a-p.x) != abs(b-p.y)) return false;
        int yDir = (b-p.y)/abs(b-p.y);
        int xDir = (a-p.x)/abs(a-p.x);
        int xPos = p.x;
        int yPos = p.y;
        while(a != xPos){
          xPos += xDir;
          yPos += yDir;
          if(hasPiece(xPos,yPos) && xPos != a) {
            return false;
          }
        }
        return true;
      }
      else if(p.name == "Rook"){
        // Only adjacant movements
        if(a != p.x && b != p.y) return false;
        if(a != p.x){
          int xDir = (a-p.x)/abs(a-p.x);
          int xPos = p.x;
          while(xPos != a){
            xPos += xDir;
            if(hasPiece(xPos, b)) return false;
          }
        }
        else if (b != p.y) {
          int yDir = (b-p.y)/abs(b-p.y);
          int yPos = p.y;
          while(yPos != b){
            yPos += yDir;
            if(hasPiece(a, yPos)) return false;
          }
        }
        return true;
      }
      else if(p.name == "King"){
        if(abs(a-p.x) < 2 && abs(b-p.y) < 2) return true;
        if(p.moved) return false;
        // Long castle
        if(hasPiece(0,p.y)) {
          Piece piece = getPiece(0,p.y);
          if(piece.name == "Rook" && piece.color == p.color && !piece.moved && !hasPiece(1,p.y) && !hasPiece(2,p.y) && !hasPiece(3,p.y)) return true;
        }
        // Short castle
        if(hasPiece(7,p.y)) {
          Piece piece = getPiece(7,p.y);
          if(piece.name == "Rook" && piece.color == p.color && !piece.moved && !hasPiece(5,p.y) && !hasPiece(6,p.y)) return true;
        }
        return false;
      }
      else if(p.name == "Pawn"){
        // 1 movement
        if(b==p.y - (int(p.color)*2-1) && a==p.x) return true;
        // Double movement
        if(!p.moved && b==p.y - 2*(int(p.color)*2-1) && a==p.x && !hasPiece(p.x, p.y - (int(p.color)*2-1))) return true;
      }
      else if(p.name == "Queen"){
        if(a==p.x || b==p.y || abs(a-p.x) == abs(b-p.y)) return true;
      }
      else if(p.name == "Knight"){
        if((abs(a-p.x) == 2 && abs(b-p.y) == 1) || (abs(a-p.x) == 1 && abs(b-p.y) == 2)) return true;
      }
      return false;
    }
    void play(Piece p, int a, int b) {
      if(!isMove(p, a, b)) return;
      pieces[p.index].x = a;
      pieces[p.index].y = b;
    }
    void play(string move){
      bool color = count % 2;
      if(move[0] > 97){
        string type = "Pawn";
        int x = move[0] - 97;
        // for(int i=0; i<32; i++){
        //   if(pieces[i].name == type && pieces[i].x == x)
        // }

      }
      else {
        // if(first == 'K') type = "King";
        // else if(first == 'Q') type = "Queen";
        // else if(first == 'R') type = "Rook";
        // else if(first == 'B') type = "Bishop";
        // else if(first == 'N') type = "Knight";
      }
    }
};

//ChessGame: Game with pieces generated in starting positions
class ChessGame: public Game {
  public:
    ChessGame () {
      //Generating all the pieces
      for(int i=0; i<2; i++) {
        pieces[0 + i*16] = King(4, 7*i, i);
        pieces[1 + i*16] = Queen(3, 7*i, i);
        pieces[2 + i*16] = Rook(0, 7*i, i);
        pieces[3 + i*16] = Rook(7, 7*i, i);
        pieces[4 + i*16] = Knight(1, 7*i, i);
        pieces[5 + i*16] = Knight(6, 7*i, i);
        pieces[6 + i*16] = Bishop(2, 7*i, i);
        pieces[7 + i*16] = Bishop(5, 7*i, i);
        for(int j=0; j<8; j++){
          pieces[8 + j + i*16] = Pawn(j, abs(i*7-1), i);
        }
      }
      //Indexing all the pieces
      for(int i=0; i<32; i++) {
        pieces[i].index = i;
      }
    }
};

// //Portable game notation class
// class PGN {
//
// };

void displayBoard(ChessGame game) {
  cout << "  ";
  for(int i=0; i<=7; i++) cout << (char)(65 + i) << " ";
  cout << endl;
  for(int i=7; i>=0; i--){
    cout << i+1 << " ";
    for(int j=0; j<=7; j++){
      if(game.hasPiece(j,i)) cout << game.getPiece(j,i).symbol;
      else cout << " ";
      cout << " ";
    }
    cout << endl;
  }
}


int main() {
  ChessGame game;
  displayBoard(game);
  while(true){
    int a, b, i;
    cin >> a;
    cin >> b;
    cin >> i;
    cout << game.pieces[i].x << " " << game.pieces[i].y << " " << game.pieces[i].name << endl;
    cout << "Going to: " << a<< " " << b << endl;
    game.play(game.pieces[i], a, b);
    displayBoard(game);
  }
  return 0;
}
