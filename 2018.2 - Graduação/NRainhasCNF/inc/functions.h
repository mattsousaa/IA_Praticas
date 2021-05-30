#ifndef FUNCTIONS
#define FUNCTIONS
#define N 4         // N = ordem do tabuleiro

void printSolution(int board[N][N]);

bool check(int board[N][N], int row, int col);

bool solve(int board[N][N], int col);

int getPos(int i, int j);

void cnf();

#endif // FUNCTIONS
