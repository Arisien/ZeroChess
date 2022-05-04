#include "../includes/piece.hpp"

Piece::Piece (std::string n, uint8_t i) {
    name = n;
    id = i;
}

Piece::~Piece () {}

uint8_t Piece::getId () {
    return id;
}
        
std::string Piece::getName () {
    return name;
}

bool Piece::logic () {
    return false;
}

// class King: public Piece {

// };