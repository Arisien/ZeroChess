#ifndef ZERO_PIECE_HPP
#define ZERO_PIECE_HPP

#include <string>

class Piece {
    private:
        uint id;
        std::string name;
    public:
        Piece (std::string n, uint i);

        virtual ~Piece ();

        uint getId();
        
        std::string getName();

        virtual bool logic();
};

#endif