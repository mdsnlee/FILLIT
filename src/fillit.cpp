#include <cstring>
#include <iostream>

#include "fillit.hpp"

bool Fillit::makeBlock(char* line)
{

    //FIX THIS
    //std::cout << line << std::endl;


    //std::cout << "the line we are working on: " << line << std::endl;
    Piece* current_piece = new Piece();

    static int count = 0;
    current_piece->value = 'a' + count;
    count++;
    //read line until we find the first hashtag
        //going down a column

    int i = 0;
    int block_num = 0;
    while(i < 20 && line[i] != '#')
    {
        i++;
    }
    //arroved at first #
    current_piece->blocks[block_num] = {0,0};
    block_num++;
    int current_x = 0;
    int current_y = 0;

    while (i < 20 && block_num < 4)
    {
        i++;
        current_x++;
        
        if (line[i] == '#')
        {
            current_piece->blocks[block_num] = {current_x, current_y};
            block_num++;
        }
        else if (line[i] == '\n')
        {
            current_y++;
            current_x -= 5;
        }

    }
    // validate the piece
    //add it to the linked list
    //std::cout << *current_piece << std::endl;
    _pieces->addNode(current_piece);

    return true;

}


bool Fillit::inputParser(std::string f)
{
   char line[21];
    std::ifstream input_file;
    input_file.open(f);
    if (input_file.is_open())
    {
        while (input_file.peek() != EOF)
        {   input_file.read(line, 21);
            line[20] = '\0';
            
            makeBlock(line);

            // std::cout << line << std::endl;
        }
        input_file.close();
    }
    else
    {
        std::cout << "Error: File won't open"  << std::endl;
        return false;
    }
    return true;
}

void Fillit::checkNextPiece(t_list *node, int n, bool &solved)
{//Piece *current_piece
    // if current piece is null
    if (!node)
    {
        solved = true;
        return;
    }
        // mark solved,save solved state, exit recursion
    Piece *current_piece = (Piece*)node->value;

    for(int y = 0 ; y < n ; y ++ )
    {
        for(int x = 0; x < n ; x ++ )
        {
        //attempt to add piece to board
            //check all 4 coordinates in piece
            //1. all in board range
            //function check in range
            if (y + current_piece -> blocks[0].y < n && x + current_piece->blocks[0].x < n &&
                y + current_piece -> blocks[1].y < n && x + current_piece->blocks[1].x < n &&
                y + current_piece -> blocks[2].y < n && x + current_piece->blocks[2].x < n &&
                y + current_piece -> blocks[3].y < n && x + current_piece->blocks[3].x < n &&
                //2. check if it's an open space
                _board[y + current_piece -> blocks[0].y][x + current_piece->blocks[0].x] == '.' &&
                _board[y + current_piece -> blocks[1].y][x + current_piece->blocks[1].x] == '.' &&
                _board[y + current_piece -> blocks[2].y][x + current_piece->blocks[2].x] == '.' &&
                _board[y + current_piece -> blocks[3].y][x + current_piece->blocks[3].x] == '.'
                )
            {
                //add piece to board:
                //funtion add piece
                _board[y + current_piece -> blocks[0].y][x + current_piece->blocks[0].x] = current_piece->value;
                _board[y + current_piece -> blocks[1].y][x + current_piece->blocks[1].x] = current_piece->value;
                _board[y + current_piece -> blocks[2].y][x + current_piece->blocks[2].x] = current_piece->value;
                _board[y + current_piece -> blocks[3].y][x + current_piece->blocks[3].x] = current_piece->value;
                
                //recur next piece
                checkNextPiece(node->next, n, solved);
                if(solved)
                {
                    //std::cout << "solved?" << std::endl;
                    return;
                }
                //remove piece from board
                //function remove piece
                _board[y + current_piece -> blocks[0].y][x + current_piece->blocks[0].x] = '.';
                _board[y + current_piece -> blocks[1].y][x + current_piece->blocks[1].x] = '.';
                _board[y + current_piece -> blocks[2].y][x + current_piece->blocks[2].x] = '.';
                _board[y + current_piece -> blocks[3].y][x + current_piece->blocks[3].x] = '.';
            }
        }
    }
}


void Fillit::solver(void)
{
    bool solved = false;

    while (!solved)
    {
        //reallocate memory
        //create board of size _boardSize
        _board = new char*[_boardSize];
        for (int i = 0; i < _boardSize; i++)
        {
            _board[i] = new char[_boardSize];
        }
        for (int y = 0; y < _boardSize; y++)
            for (int x = 0; x < _boardSize; x++)
                _board[y][x] = '.';

        checkNextPiece(_pieces->getHead(), _boardSize, solved);
        //recursion here
        if (!solved)
        {
            //Delete board
            for (int i = 0; i < _boardSize; i++)
                //it's a double pointer
                delete _board[i];
            delete _board;

            _boardSize++;
        }
    }
}

void Fillit::printBoard(void)
{

    char* colors[7] = {
        BG_RED, 
        BG_GREEN,
        BG_YELLOW,
        BG_BLUE,
        BG_PURPLE,
        BG_CYAN,
        BG_WHITE
    };

    int current_color = 0;

    for (int y = 0; y < _boardSize; y++)
    {
        for (int x = 0; x < _boardSize; x++)
        {
            if (_board[y][x] == '.')
                std::cout << DEFAULT << " ";
            else
                std::cout << colors[_board[y][x] % 7] << " ";
        }


        std::cout << DEFAULT << std::endl;
    }
}



    //attempt to add piece to board
        //check all 4 coordinates in piece
            //1. all in board range
            //2. all spots free
        //add to board
        //recur next piece
    //else, exit recursion (to create a larger board)

        // fit in blocks to see if they all fit
        // if no pieces left to fit
    
    
    
    
    
    
    //    save solution and save as done
    //  while blocks exist and fit on board
    //        place current block on board
    //        if it worked
    //            recur to next block
    //            delete current block
    //        
    //if they don't all fit, re try it
    //delete board, make a bigger board

//read 4 lines
//save to object
//read 1 line for empty newline
//loop

//to do
//segmentation error: solver