#ifndef ZERO_BOARD_HPP
#define ZERO_BOARD_HPP

#include <vector>
#include <string>

class Board {
    private:
        std::vector<int> tiles;
        uint8_t height, width;
    public:
        Board(int h, int w);

        virtual ~Board();
        
        uint8_t getHeight();
        
        uint8_t getWidth();
        
        int getTile(int x, int y);

        void setTile (int x, int y, int tile);
};

#endif