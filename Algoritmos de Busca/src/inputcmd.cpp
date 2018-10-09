#include "inputcmd.h"



int inputCMD(string value){
    string str = value;
    for(int i=0; i< (int) str.size(); i++)
    {
        str[i] = toupper (str[i]); //Convert all letters of the word to UPPERCASE
    }

    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                              "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                              "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                              "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE"};
    for(int i = 0; i < 20; i++){
        if(CityName[i] == str)
            return i; //RETURN THE NUMBER REFERENT THE CITY IN ENUM

    }
    return 0;
}
