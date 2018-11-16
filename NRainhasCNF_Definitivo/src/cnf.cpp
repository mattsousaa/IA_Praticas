#include "cnf.h"

CNF::CNF(int N) : N(N), qtd(0){
    ostringstream os;
    os << "/home/mateus/Desktop/2018.2/Praticas_IA/NRainhasCNF_Definitivo" << N << "x" << N << ".cnf";
    this->FileDirectory = os.str();

    this->cnfFile.open(os.str());
}

int CNF::getLocation(int i, int j){
    return (i * this->N + j + 1);
}

string CNF::getFileDirectory(){
    return this->FileDirectory;
}

bool CNF::MakeCnfFile(){

    if(!cnfFile.is_open())
        return false;

    cnfFile << "         \0\r" << endl;
    cnfFile << "         \0\r" << endl;

    for(int i = 1;i <= N*N;i = i+N){
        for(int j = i;j < i+N;j++)
            cnfFile << j << " ";

        cnfFile << "0" << endl;
        this->qtd++;
    }

    cnfFile << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for(int k = 0; k < N;k++){
                if(getLocation(i,j)*-1 != getLocation(i,k)*-1){
                    cnfFile << getLocation(i,j)*-1 << " " << getLocation(i,k)*-1 << " 0" << endl;
                    this->qtd++;
                }
                if(getLocation(i,j)*-1 != getLocation(k,j)*-1){
                    cnfFile << getLocation(i,j)*-1 << " " << getLocation(k,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }
        }
    }

    for(int k = 0;k < N;k++){
        for(int z = 0;z < N;z++){

            for (int i=k, j=z; i>=0 && j>=0; i--, j--){
                if(getLocation(i,j) != getLocation(k,z)){
                    cnfFile << getLocation(k,z)*-1 << " " << getLocation(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }

            for (int i=k, j=z; j>=0 && i<N; i++, j--){
                if(getLocation(i,j) != getLocation(k,z)){
                    cnfFile << getLocation(k,z)*-1 << " " << getLocation(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }

            for (int i=k, j=z; j<N && i>=0; i--, j++){
                if(getLocation(i,j) != getLocation(k,z)){
                    cnfFile << getLocation(k,z)*-1 << " " << getLocation(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }

            for (int i=k, j=z; j<N && i<N; i++, j++){
                if(getLocation(i,j) != getLocation(k,z)){
                    cnfFile << getLocation(k,z)*-1 << " " << getLocation(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }
        }
    }

    cnfFile.seekp(0);
    cnfFile << "p cnf " << N*N << " " << this->qtd << endl;
    cnfFile.close();

    return true;
}

