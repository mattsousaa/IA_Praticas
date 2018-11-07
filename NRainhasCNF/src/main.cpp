#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]){

//int n = atoi(argv[1]);

//cout << n << endl;

int board[N][N];
clock_t start, end;

for(int i = 0; i < N;i++){
    for(int j = 0; j < N;j++){
        board[i][j] = 0;
    }
}

if(solve(board, 0) == false){
	cout << "Solução não existe!" << endl;
    return -1;
}

start = clock();
               
cnf();

end = clock();

float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);

printSolution(board);

cout << "Runtime of writing in CNF file: " << time << "ms" << endl;

return 0;

}
