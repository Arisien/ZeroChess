#ifndef ZERO_PIECE_HPP
#define ZERO_PIECE_HPP

#include <string>

class Piece {
    private:
        int id;
        std::string name;
    public:
        Piece (std::string name, int id);

        virtual ~Piece ();

        int getId();
        
        std::string getName();

        virtual bool logic();
};

#endif