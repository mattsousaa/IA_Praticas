#ifndef HEURISTICS
#define HEURISTICS

#include <string>

int heuristicCity(std::string city){

    if(city == "ARAD")              return 366;
    else if(city == "BUCHAREST")    return 0;
    else if(city == "CRAIOVA")      return 160;
    else if(city == "DROBETA")      return 242;         
    else if(city == "EFORIE")       return 161;
    else if(city == "FAGARAS")      return 176;
    else if(city == "GIURGIU")      return 77;
    else if(city == "HIRSOVA")      return 151;
    else if(city == "IASI")         return 226;
    else if(city == "LUGOJ")        return 244;
    else if(city == "MEHADIA")      return 241;
    else if(city == "NEAMT")        return 234;            
    else if(city == "ORADEA")       return 380;
    else if(city == "PITESTI")      return 100;
    else if(city == "RVILCEA")      return 193;
    else if(city == "SIBIU")        return 253;         
    else if(city == "TIMISOARA")    return 329;
    else if(city == "URZICENI")     return 80;
    else if(city == "VASLUI")       return 199;
    else                            return 374;     // ZERIND     

}

#endif // HEURISTICS