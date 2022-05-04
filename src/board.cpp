#include "../includes/board.hpp"

Board::Board(int h, int w) {
    tiles = std::vector<int>(h*w);
    height = h;
    width = w;
}

Board::~Board() {}
        
uint8_t Board::getHeight() {
    return height;
}
        
uint8_t Board::getWidth() {
    return width;
}
        
int Board::getTile(int x, int y) {
    return tiles[x + y*width];
}

void Board::setTile (int x, int y, int tile) {
    tiles[x + y*width] = tile;
}