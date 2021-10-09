#ifndef ZERO_GAME_HPP
#define ZERO_GAME_HPP

#include <vector>
#include <map>

class Piece;

class Game {
    public:
        std::vector<std::vector<int>> board;
        std::map<int, Piece*> pieces;
        Game();
        ~Game();
        void addPiece (Piece* piece);
};

#endif