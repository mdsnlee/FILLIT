#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Piece.hpp"
#include "LinkedList.hpp"
#include "colors.h"

class Fillit
{
private:
    LinkedList *_pieces;
    //save board that was loaded
    char **_board;
    int _boardSize;
//protected
    //stuff in here can be used inside inside the whole class, but not outside

public:
    Fillit()
    {
        _pieces = new LinkedList();
        _board = new char*[2];
        for(int i = 0; i < 2; i++)
        {
            _board[1] = new char[2];
        }

        _boardSize = 2;
    }
    bool inputParser(std::string f);
    bool makeBlock(char *line);
    void solver();
    void checkNextPiece(t_list *node, int n, bool &solved);
    void printBoard(void);

};



//inheritance: class Fillit: Class child <-- inherits what's inside Class Fillit into Class Child
//a is a character
//*a is a list
//**a is a list of lists