#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int checkRightDiagonal(int boolRightDiag, int i, int j, char** board);
int checkLeftDiagonal(int boolRightDiag, int i, int j, char** board);
int checkSameRow(int boolRightDiag, int i, int j, char** board);
int checkSameCol(int boolRightDiag, int i, int j, char** board);
int checkRightDiagonal(int boolRightDiag, int i, int j, char** board) {
int k = 1;
while (((( j + k) < 8)) && ((( i - k) >= 0))) {
if (board[i-k][j+k] == 'Q') {
return 1;
}
k = k + 1;
}
k = 1;

while( (((j - k) >= 0)) && ((( i + k) < 8))) {
if (board[i+k][j-k] == 'Q') {
return 1;
}
k = k + 1;
}

/*int k, x, y;
k = i + j;
for (x = 0; x < 8; x = x + 1) {
for (y = 0; y < 8; y = y + 1) {
if (i != x && j != y && (k == (x + y)) && board[x][y] == 'Q') {
return 1; 
}
}
}
return 0;
*/
return 0;
}

int checkLeftDiagonal(int boolRightDiag, int i, int j, char** board) {
int k = 1;
while( (((j + k) < 8)) && (((i + k) < 8))) {
if (board[i + k][j + k] == 'Q') {
return 1;
}
k = k + 1;
}
k = 1;

while (((( j - k) >= 0)) && (((i - k) >= 0))) {
if (board[i - k][j - k] == 'Q') {
return 1;
}
k = k + 1;
}

/*
int k, x, y, l;
k = i - j;
l = j - i;
for (x = 0; x < 8; x = x + 1) {
for (y = 0; y < 8; y = y + 1) {
if (i != x && j != y && (k == (x - y) || l == (x - y)) && board[x][y] == 'Q') {
return 1;
}
}
}
return 0;
}
*/
return 0;
}
int checkSameRow(int boolRightDiag, int i, int j, char** board) {
int k = 0;
for (k = 0; k < 8; k = k + 1) {
if (board[i][k] == 'Q'&& k != j) {
    return 1;
}
}
return 0;
}
int checkSameCol(int boolRightDiag, int i, int j, char** board) {
int k = 0;
for (k = 0; k < 8; k = k + 1) {
if (board[k][j] == 'Q' && k!= i) {
    return 1;
} 
}
return 0;
}
/*
int checkAll(int boolCheck, int i, int j, char** board) {
int x = 0;
for (x = 0; x < i; x = x + 1) {
if ((board[i-1-x][j] == 'Q') || (board[i-1-x][j-1-x] == 'Q' && (j - x - 1 >= 0)) || (board[i-1-x][j+1+x] == 'Q' && (j+1+x <8))){
return 1;
} 
}
return 0;
}
*/
int main(int argc, char** argv) {
/* 
 * Get file
 * Allocate memory for the board
 * Allocate memory for newBoard
 * insert values and stuff into board
 *
 * check if any Q eats another Q
 *     if so INVALID
 *
 *     run through each spot in board
 *         check if it is unseen by an existing Q
 *                 if unseen put q there
 *
 *                 print new Board of Qs and qs
 *
 *                 */

char** board;
char** newBoard;
char entry;
int i, j;
int boolRightDiag = 0, boolLeftDiag = 0, boolSameRow = 0, boolSameCol = 0; 
//int boolCheck = 0;
FILE *filePointer = fopen(argv[argc - 1], "r");
board = (char**)malloc(8 * sizeof(char*));
    for (i = 0; i < 8; i = i + 1) {
        board[i] = (char*)malloc(8 * sizeof(char*));
    }
newBoard = (char**)malloc(8 * sizeof(char*));
    for (i = 0; i < 8; i = i + 1) {
        newBoard[i] = (char*)malloc(8 * sizeof(char*));
    }
    for (i = 0; i < 8; i = i + 1) {
        for (j = 0; j < 8; j = j + 1) {
            fscanf(filePointer,"%c ", &entry);
            board[i][j] = entry;
        }
        fscanf(filePointer,"\n");
    }
for (i = 0; i < 8; i = i + 1) {
for (j = 0; j < 8; j = j +1) {
newBoard[i][j] = board[i][j];
}
//printf("\n");
}
if(argc < 4) {
    for (i = 0; i < 8; i = i + 1) {
        for (j = 0; j < 8; j = j + 1) {
            if (board[i][j] == 'Q') {
	//	boolCheck = checkAll(boolCheck, i, j, board);
	 boolRightDiag = checkRightDiagonal(boolRightDiag, i, j, board);
           boolLeftDiag = checkLeftDiagonal(boolLeftDiag, i, j, board);
           boolSameRow = checkSameRow(boolSameRow, i, j, board);
           boolSameCol = checkSameCol(boolSameCol, i, j, board);
           if (boolRightDiag == 1 || boolLeftDiag == 1 || boolSameRow == 1 || boolSameCol == 1) {
               printf("Invalid");
		return EXIT_SUCCESS;
} 
}
}
}

                for (i = 0; i < 8; i = i + 1) {
		   for (j = 0; j < 8; j = j + 1) {
boolRightDiag = 0;
boolLeftDiag = 0;
boolSameRow = 0;
boolSameCol = 0;			
if (board[i][j] == 'Q') {
printf("Q");
//newBoard[i][j] = 'Q';
}else {
boolRightDiag = checkRightDiagonal(boolRightDiag, i, j, board);
boolLeftDiag = checkLeftDiagonal(boolLeftDiag, i, j, board);
boolSameRow = checkSameRow(boolSameRow, i, j, board);
boolSameCol = checkSameCol(boolSameCol, i, j, board);
if (boolRightDiag == 1 || boolLeftDiag == 1 ||  boolSameRow ==1 || boolSameCol == 1) {
//newBoard[i][j] = '.';
printf(".");
} else {
printf("q");
//newBoard[i][j] = 'q';
}

}
}
printf("\n");
}
}
if (argc == 3 && strcmp(argv[1], "+2") == 0) {
int count = 0;
boolRightDiag = 0;
boolLeftDiag = 0;
boolSameRow = 0;
boolSameCol = 0;

for (i = 0; i < 8; i = i + 1) {
for (j = 0; j < 8; j = j + 1) {
if (board[i][j] == 'Q') {
continue; 
} else if (board[i][j] == '.') {
boolRightDiag = checkRightDiagonal(boolRightDiag, i, j, board);
boolLeftDiag = checkLeftDiagonal(boolLeftDiag, i, j, board);
boolSameRow = checkSameRow(boolSameRow, i, j, board);
boolSameCol = checkSameCol(boolSameCol, i, j, board);
if (boolRightDiag == 1 || boolLeftDiag == 1 || boolSameRow == 1 || boolSameCol == 1) {
continue;
} else {
boolRightDiag = 0;
boolLeftDiag = 0;
boolSameRow = 0;
boolSameCol = 0;
boolRightDiag = checkRightDiagonal(boolRightDiag, i, j, newBoard);
boolLeftDiag = checkLeftDiagonal(boolLeftDiag, i, j, newBoard);
boolSameRow = checkSameRow(boolSameRow, i, j, newBoard);
boolSameCol = checkSameCol(boolSameCol, i, j, newBoard);
if (boolRightDiag == 1 || boolLeftDiag == 1 || boolSameRow == 1 || boolSameCol == 1) {
continue;
}else {
newBoard[i][j] = 'Q';
count = count + 1;
}
}
}
}
}
if (count == 0) {
printf("Zero");
} 
if (count == 1) {
printf("One");
}
if (count > 1) {
	printf("Two or more");
}	
}
if (argc == 4 && strcmp(argv[2],"w")) {
for (i = 0; i < 8; i = i + 1) {
for (j = 0; j < 8; j = j + 1) {
if (board[i][j] == 'W') {
newBoard[i][j] = 'W';
} else {
newBoard[i][j] = '.';
}
}
}
for (i = 0; i < 8; i = i + 1) {
 for (j = 0; j < 8; j = j + 1) {
if (newBoard[i][j] == 'W') {
printf("W");
} else {
printf(".");
}
}
printf("\n");
}
printf("Zero");
}
	  
return 0;
}
