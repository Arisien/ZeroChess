#ifndef ZERO_PIECE_HPP
#define ZERO_PIECE_HPP

#include <string>

class Piece {
    private:
        uint8_t id;
        std::string name;
    public:
        Piece (std::string n, uint8_t i);

        virtual ~Piece ();

        uint8_t getId();
        
        std::string getName();

        virtual bool logic();
};

#endif