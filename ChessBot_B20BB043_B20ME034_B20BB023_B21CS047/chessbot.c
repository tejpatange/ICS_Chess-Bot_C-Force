#include "stdio.h"
#include "defs.h"

#define START_FEN  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

int main(){
    
    AllInit();

    S_BOARD board[1];
    S_MOVELIST list[1];

    ParseFen(START_FEN, board);

    printf("Welcome to the Game!\n");
    printf("Instructions:\n");
    printf("1. At the start Board will be printed with white to start.\n");
    printf("2. Capital lettes are White and small letter are black.\n");
    printf("3. P- Pawn, B-Bishop, N-Knight, R-Rook, Q-Queen, K-King.\n");
    printf("4. If you want to enter move write current position of piece then where you want to move it\n");
    printf(" ex:- if pawn is at e2 and want to move it to e4 write 'e2e5'\n");
    printf("5. Have fun and enjoy the game!\n");
    
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
