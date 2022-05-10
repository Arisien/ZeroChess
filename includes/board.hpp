#ifndef ZERO_BOARD_HPP
#define ZERO_BOARD_HPP

#include <vector>
#include <string>

#include "vectors.hpp"

class Board {
    private:
        std::vector<int> tiles;
        int height, width;
    public:
        Board(int h, int w);

        virtual ~Board();
        
        int getHeight();
        
        int getWidth();
        
        int getTile(Vec2D<int> pos);

        void setTile (Vec2D<int> pos, int value);

        Vec2D<void*> getInfo (Vec2D<int> pos) {
            
        }
};

#endif