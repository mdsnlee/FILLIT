#include "header.h"

// open file given as an argument
//argc argv     //aka ac and av

//read file and figure which block it is, save peice code

//loop create a square solution board start at 2x2

//fit in blocks to see if they all fit
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

//linked lists for input

//#define print(x) std::cout << x << std::endl

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Error: Give File" << std::endl;
        //print("Error: Give File");
        return 0;
    }

    Fillit fillit;
    fillit.inputParser(av[1]);
    fillit.solver();
    fillit.printBoard();

    return 0;
}

//./fillit hello there this is things
//ac = 6 (6 things)
//av = [
//    "fillit"
//    "hello"
//   "there"
//    "this"
//    "is"
//    "things"

//      ]