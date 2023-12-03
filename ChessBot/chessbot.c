#include "stdio.h"
#include "defs.h"

#define START_FEN  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

int main(){
    
    AllInit();

    S_BOARD board[1];
    S_MOVELIST list[1];

    ParseFen(START_FEN, board);
    
    char input[6];
    int Move = NOMOVE;
    while(TRUE){
        PrintBoard(board);
        printf("Please enter a move >");
        fgets(input, 6, stdin);

        if(input[0]=='q'){
            break;
        }else if(input[0]=='t'){
            TakeMove(board);
        }else{
            Move = ParseMove(input,board);
            if(Move != NOMOVE){
                MakeMove(board,Move);
            }
        }

        fflush(stdin);
    }

    return 0;
}