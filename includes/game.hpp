#ifndef ZERO_GAME_HPP
#define ZERO_GAME_HPP

#include <vector>

#include "position.hpp"
#include "piece.hpp"
#include "board.hpp"

class Game {
    private:
        std::vector<Piece*> pieces;
        Board* board;
        Pos kings[2];
        bool turn;
    public:
        Game(int width, int height);
        
        virtual ~Game();
        
        void addPiece (Piece* piece);
        
        Piece* getPiece (uint8_t id);

        Board* getBoard ();

        Pos getKing (bool color);
        
        bool isTurn ();
        
        bool move (Pos p1, Pos p2);
};

#endif