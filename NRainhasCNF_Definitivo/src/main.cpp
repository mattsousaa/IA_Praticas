#include <iostream>
#include "cnf.h"

using namespace std;

int main(int argc, char *argv[]){

    if(argc != 2){
        cout << "Entre com o tamanho do tabuleiro." << endl;
        return -1;
    }

    int N = atoi(argv[1]);

    if(!(N >= 4)){
        cout << "O tabuleiro precisa ser maior que 4x4." << endl;
        return -1;
    }

    CNF cnf(N);

    if(cnf.MakeCnfFile())
        cout << "Arquivo no diretório: " << cnf.getFileDirectory() << endl;
    else
        cout << "Erro em gerar o arquivo." << endl;

    return 0;
}