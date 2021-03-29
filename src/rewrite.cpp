#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

using namespace std;

class Piece;
class Game;

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

    Piece() {
      name = "None";
    }

    virtual ~Piece() {}

    Piece (int a, int b, bool c) {
      name = "None";
      x = a;
      y = b;
      color = c;
      captured = false;
      moved = false;
    }

    virtual bool isMove (Game* game, int a, int b) {
      return false;
    }
};

class King: public Piece {
  public:
    King(int a, int b, bool c):Piece(a,b,c) {
      name = "King";
      symbol = 'K';
      value = 200;
    }

    bool isMove (Game* game, int a, int b) {
      if(abs(x-a) > 1 || abs(y-b) > 1) return false;
      return true;
    }
};

class Queen: public Piece {
  public:
    Queen(int a, int b, bool c):Piece(a,b,c) {
      name = "Queen";
      symbol = 'Q';
      value = 9;
    }

    bool isMove (Game* game, int a, int b) {
      return true;
    }
};

class Game {
  public:
    std::vector<std::unique_ptr<Piece>> v;
    int height;
    int width;
    Piece nullPiece;

    Game(int a, int b) {
      width = a;
      height = b;
      v.push_back(std::make_unique<King>(2,2,0));
      v.push_back(std::make_unique<King>(5,5,1));
      v.push_back(std::make_unique<Queen>(2,3,0));
      v.push_back(std::make_unique<Queen>(4,3,1));
      v.push_back(std::make_unique<Queen>(4,8,1));
    }

    bool hasPiece (int a, int b) {
      for (auto i = v.begin(); i != v.end(); ++i){
        if((*i)->x == a && (*i)->y == b) {
          return true;
        }
      }
      return false;
    }

    Piece* getPiece (int a, int b) {
      for (auto i = v.begin(); i != v.end(); ++i){
        if((*i)->x == a && (*i)->y == b) {
          return (*i).get();
        }
      }
      return &nullPiece;
    }

    int eval () {
      int value = 0;

      for (auto i = v.begin(); i != v.end(); ++i){
        value += (((*i)->color * 2) - 1) * (*i)->value;
      }

      return value;
    }

};

int main() {
  Game game(7,7);

  cout << game.getPiece(4,4)->isMove(&game, 1, 2) << endl;
  cout << game.getPiece(2,2)->isMove(&game, 1, 2) << endl;
  cout << game.getPiece(2,3)->isMove(&game, 1, 2) << endl;
  cout << game.getPiece(4,3)->isMove(&game, 1, 2) << endl;
  cout << game.getPiece(2,2)->isMove(&game, 1, 2) << endl;

  cout << game.eval() << endl;

  return 0;
}
