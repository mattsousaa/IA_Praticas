#include "inputcmd.h"

int inputCMD(string value){

    string str = value;

    for(int i = 0; i < (int)str.size(); i++){
        str[i] = toupper(str[i]); // Converto todas as letras de minusculas para maiusculas
    }

    // vetor de strings referentes ao ENUM do arquivo enum.h
    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                              "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                              "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                              "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE"};

    for(int i = 0; i < 20; i++){
        if(CityName[i] == str)      // verifica qual cidade é passada na linha de comando
            return i;               // Retorna o número referente a cidade definida no ENUM
    }
    
    return 0;
}