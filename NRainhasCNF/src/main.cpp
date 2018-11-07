#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]){

//int n = atoi(argv[1]);	
	
//cout << n << endl;
	
int board[N][N];

for(int i = 0; i < N;i++){
    for(int j = 0; j < N;j++){
        board[i][j] = 0;
    }
}

if(solve(board, 0) == false ){
	cout << "Solução não existe!" << endl;
    return -1;
}

cnf();
printSolution(board);
return 0;

}
