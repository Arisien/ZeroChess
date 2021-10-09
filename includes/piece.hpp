#ifndef ZERO_PIECE_HPP
#define ZERO_PIECE_HPP

#include <string>

class Game;

class Piece {
    public:
        std::string name;
        char symbol;
        int value;
        int id;
        Piece(std::string n, char s, int v, int i);
        ~Piece();
        virtual bool isMove(Game* game, int a, int b, int c, int d);
};

class King: public Piece {
  public:
    King(int i): Piece(n, s, v, i) {
        name = "King";
        symbol = 'K';
        value = 200;
    }
};

#endif