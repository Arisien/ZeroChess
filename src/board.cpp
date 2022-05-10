#include "../includes/board.hpp"

Board::Board(int h, int w) {
    tiles = std::vector<int>(h*w);
    height = h;
    width = w;
}

Board::~Board() {}
        
int Board::getHeight() {
    return height;
}
        
int Board::getWidth() {
    return width;
}

int Board::getTile(Vec2D<int> pos) {
    return tiles[pos.x + pos.y*width];
}

void Board::setTile (Vec2D<int> pos, int value) {
    tiles[pos.x + pos.y*width] = value;
}