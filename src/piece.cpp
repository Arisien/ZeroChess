#include "../includes/piece.hpp"

Piece::Piece (std::string name, int id) {
    this->name = name;
    this->id = id;
}

Piece::~Piece () {}

int Piece::getId () {
    return id;
}
        
std::string Piece::getName () {
    return name;
}

bool Piece::logic () {
    return false;
}