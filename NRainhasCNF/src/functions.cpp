#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

void printSolution(int board[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool check(int board[N][N], int row, int col){
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve(int board[N][N], int col){

    if(col >= N)
        return true;

    for(int i = 0; i < N; i++){

        if(check(board, i, col) ){
            board[i][col] = 1;

            if(solve(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int getPos(int i, int j){
    return i * N + j + 1;
}

void cnf(){

    ofstream outFile;
    outFile.open("/home/mateus/Desktop/2018.2/Praticas_IA/NRainhasCNF/solutionCNF/saida.txt");
    outFile << "p cnf " << N*N << " " << N*N*10 << endl;

    for(int i = 1;i <= N*N;i = i+N){
        for(int j = i;j < i+N;j++)
            outFile << j << " ";
        outFile << "0" << endl;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for(int k = 0; k < N;k++){
                if(getPos(i,j)*-1 != getPos(i,k)*-1)
                    outFile << getPos(i,j)*-1 << " " << getPos(i,k)*-1 << " 0" << endl;
                if(getPos(i,j)*-1 != getPos(k,j)*-1)
                    outFile << getPos(i,j)*-1 << " " << getPos(k,j)*-1 << " 0" << endl;
            }
        }
    }

    for(int k = 0;k < N;k++){
        for(int z = 0;z < N;z++){

            for (int i=k, j=z; i>=0 && j>=0; i--, j--)
                if(getPos(i,j) != getPos(k,z))
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;

            for (int i=k, j=z; j>=0 && i<N; i++, j--)
                if(getPos(i,j) != getPos(k,z))
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;

            for (int i=k, j=z; j<N && i>=0; i--, j++)
                if(getPos(i,j) != getPos(k,z))
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;

            for (int i=k, j=z; j<N && i<N; i++, j++)
                if(getPos(i,j) != getPos(k,z))
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;
        }
    }
}
