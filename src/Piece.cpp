#include "Piece.hpp"

std::ostream& operator << (std::ostream& os, const Piece& piece)
{
    //(left side, right side)
    for (int i = 0; i < 4; i ++)
    {
        os << "(" << piece.blocks[i].x << ", " << piece.blocks[i].y << ")" << ", ";
    }
    os << std::endl; 
    return os;
}
//over writing the command, what the command does