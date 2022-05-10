#ifndef ZERO_GAME_HPP
#define ZERO_GAME_HPP

#include <vector>

#include "piece.hpp"
#include "board.hpp"
#include "vectors.hpp"

class Game {
    private:
        std::vector<Piece*> pieces;
        Board* board;
        Vec2D<int> kings[2];
        bool turn;
    public:
        Game(int width, int height);
        
        virtual ~Game();
        
        void addPiece (Piece* piece);
        
        Piece* getPiece (int id);

        Board* getBoard ();

        Vec2D<int> getKing (bool color);
        
        bool isTurn ();
        
        bool move (Vec2D<int> p1, Vec2D<int> p2);
};

#endif