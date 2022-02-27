#include "../includes/piece.hpp"

Piece::Piece (std::string n, uint i) {
    name = n;
    id = i;
}

Piece::~Piece () {}

uint Piece::getId () {
    return id;
}
        
std::string Piece::getName () {
    return name;
}

bool Piece::logic () {
    return false;
}