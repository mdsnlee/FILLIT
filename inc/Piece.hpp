#pragma once
//#ifndef PIECE_HPP
//#define PIECE_HPP


#include <iostream>


//can put typedef up here
struct s_blocks
{
    int x;
    int y;

} typedef t_block;
//just variable name

class Piece
{
private:

public:
    t_block blocks[4];
    char value;

    Piece() {};
    Piece(t_block a, t_block b, t_block c, t_block d);
    ~Piece();
    
};

std::ostream& operator << (std::ostream& os, const Piece& piece);