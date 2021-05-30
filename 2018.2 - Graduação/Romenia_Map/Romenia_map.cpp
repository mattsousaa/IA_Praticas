#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum City {

	  ORADEA,
    ZERIND,
    ARAD,
    TIMISOARA,
    LUGOJ,
    MEHADIA,
    DROBETA,
    SIBIU,
    RIMNICU_VILCEA,
    CRAIOVA,
    FAGARAS,
    PITESTI,
    BUCHAREST,
    GIURGIU,
    NEAMT,
    IASI,
    VASLUI,
    URZICENI,
    HIRSOVA,
    EFORIE
};

vector<string> CityName = {"ORADEA",
                           "ZERIND",
                           "ARAD",
                           "TIMISOARA",
                           "LUGOJ",
                           "MEHADIA",
                           "DROBETA",
                           "SIBIU",
                           "RIMNICU_VILCEA",
                           "CRAIOVA",
                           "FAGARAS",
                           "PITESTI",
                           "BUCHAREST",
                           "GIURGIU",
                           "NEAMT",
                           "IASI",
                           "VASLUI",
                           "URZICENI",
                           "HIRSOVA",
                           "EFORIE"};

/* Matriz de adjacência para o mapa rodoviário da Romênia */
                           
int grafo[20][20] = {0,	71,	-1,	-1,	-1,	-1,	-1,	151, -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//ORADEA
                     71,0, 75,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//ZERIND
                     -1,75,	0,	118,-1,	-1,	-1,140,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//ARAD
                     -1,-1,118,	0, 111, -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//TIMISOARA
                     -1,-1,	-1,	111, 0,	70,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//LUGOJ
                     -1,-1,	-1,	-1,	70,	 0,	75,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//MEHADIA
                     -1,-1,	-1,	-1,	-1,	75,	 0,	-1,	-1,120,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//DROBETA
                     151,-1,140,-1,	-1,	-1,	-1,	 0,	80,	-1,	99,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//SIBIU
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	80,	 0,146,	-1,	97,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//RIMNICU_VILCEA
                     -1,-1,	-1,	-1,	-1,	-1,120,	-1,146,	 0,	-1,138,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//CRAIOVA
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	99,	-1,	-1,	 0,	-1,211,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//FAGARAS
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	97,138,	-1,	 0,101,	-1,	-1,	-1,	-1,	-1,	-1,	-1,		//PITESTI
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,211,101,	 0,	90,	-1,	-1,	-1,	85,	-1,	-1,		//BUCHAREST
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	90,	 0,	-1,	-1,	-1,	-1,	-1,	-1,		//GIURGIU
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	 0,	87,	-1,	-1,	-1,	-1,		//NEAMT
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	87,  0,	92,	-1,	-1,	-1,		//IASI
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	92,	 0,142,	-1,	-1,		//VASLUI
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	85,	-1,	-1,	-1,142,	 0,	98,	-1,		//URZICENI
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	98,	 0,	86,		//HIRSOVA
                     -1,-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	86,	0 };	//EFORIE


//Obtem todos os lados adjacentes
vector <City> getAdjacentes(City i){
	vector<City> adj;

	for(int j = 0; j < 20; j++)
		if(grafo[i][j] != -1 && i != j)
			adj.push_back((City) j);

	return adj;
}

//Retorna a quantidade de lados adjacentes aos vértices
int qtdAdjacente(City i){
    int count = 0;
    for(int j = 0; j < 20; j++)
        if(grafo[i][j] != -1)
            count++;

    //diminui de 1 pois ele conta a ele mesmo
    return (count-1);
}

//retorna o custo se for adjacentes ou retorna -1 caso contrario
int adjacente(City i, City j){
    if(grafo[i][j] != -1)
        return grafo[i][j];
    return -1;
}

string getCityName(enum City city){

  switch (city){

    case ORADEA:          return "ORADEA";
    case ZERIND:          return "ZERIND";
    case ARAD:            return "ARAD";
    case TIMISOARA:       return "TIMISOARA";
    case LUGOJ:           return "LUGOJ";
    case MEHADIA:         return "MEHADIA";
    case DROBETA:         return "DROBETA";
    case SIBIU:           return "SIBIU";
    case RIMNICU_VILCEA:  return "RIMNICU_VILCEA";
    case CRAIOVA:         return "CRAIOVA";
    case FAGARAS:         return "FAGARAS";
    case PITESTI:         return "PITESTI";
    case BUCHAREST:       return "BUCHAREST";
    case GIURGIU:         return "GIURGIU";
    case NEAMT:           return "NEAMT";
    case IASI:            return "IASI";
    case VASLUI:          return "VASLUI";
    case URZICENI:        return "URZICENI";
    case HIRSOVA:         return "HIRSOVA";
    case EFORIE:          return "EFORIE";
    /* etc... */
  }

}

City getNameCity(string city){  

  if(city == "ORADEA")              return ORADEA;  
  else if(city == "ZERIND")         return ZERIND;  
  else if(city == "ARAD")           return ARAD;  
  else if(city == "TIMISOARA")      return TIMISOARA;  
  else if(city == "LUGOJ")          return LUGOJ;  
  else if(city == "MEHADIA")        return MEHADIA;  
  else if(city == "DROBETA")        return DROBETA;  
  else if(city == "SIBIU")          return SIBIU;  
  else if(city == "RIMNICU_VILCEA") return RIMNICU_VILCEA;  
  else if(city == "CRAIOVA")        return CRAIOVA;  
  else if(city == "FAGARAS")        return FAGARAS;  
  else if(city == "PITESTI")        return PITESTI;  
  else if(city == "BUCHAREST")      return BUCHAREST;  
  else if(city == "GIURGIU")        return GIURGIU;  
  else if(city == "NEAMT")          return NEAMT;  
  else if(city == "IASI")           return IASI;  
  else if(city == "VASLUI")         return VASLUI;  
  else if(city == "URZICENI")       return URZICENI;  
  else if(city == "HIRSOVA")        return HIRSOVA;  
  else if(city == "EFORIE")         return EFORIE;   
}


int main(){

int qtd_adj;
int teste;
string op = "";
string name_city1, name_city2;

vector<City> caminho;

cout << "1 - Retorna o custo entre duas cidades" << endl
     << "2 - Retorna a quantidade de lados Adjacentes" << endl
     << "3 - Retorna as cidades Adjacentes" << endl;

  while(1){

  cin >> op;

  if(op == "1"){
    /* Retorna o custo entre duas cidades */
    cin >> name_city1;
    cin >> name_city2;

    transform(name_city1.begin(), name_city1.end(), name_city1.begin(), ::toupper);
    transform(name_city2.begin(), name_city2.end(), name_city2.begin(), ::toupper);

    qtd_adj = adjacente(getNameCity(name_city1), getNameCity(name_city2));

    cout << qtd_adj << endl;
  } else if(op == "2"){
    /* Retorna a quantidade de lados Adjacentes */
    cin >> name_city1;
    
    transform(name_city1.begin(), name_city1.end(), name_city1.begin(), ::toupper);

    teste = qtdAdjacente(getNameCity(name_city1));

    cout << teste << endl;
  } else if(op == "3"){
    /*Retorna as cidades Adjacentes a escolhida */

    cin >> name_city1;

    transform(name_city1.begin(), name_city1.end(), name_city1.begin(), ::toupper); 

    cout << endl;

    caminho = getAdjacentes(getNameCity(name_city1));

    for(int i = 0; i < caminho.size();i++)
      cout << getCityName(caminho[i]) << endl;
  }

  cout << endl;

}

}