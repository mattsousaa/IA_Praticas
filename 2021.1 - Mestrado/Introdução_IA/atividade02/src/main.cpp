#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "graph.h"
#include "bfs.h"
#include "inputcmd.h"

using namespace std;

/*

// Matriz de adjacência para o mapa rodoviário da Romênia (grafo em matriz - possivel representação)
                           
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
*/

void InitGrafo(Graph& grafo){

  // preenche toda a matriz com zeros
  for(int i = 0; i < 20; i++)
      for(int j = 0; j < 20; j++)
          grafo.addPoint(i, j, 0);    

  // define a distancia de cada ponto em relação a outras cidade adjacentes
  grafo.addPoint(ORADEA, ZERIND, 71);
  grafo.addPoint(ORADEA, SIBIU, 151);
  grafo.addPoint(ZERIND, ARAD, 75);
  grafo.addPoint(ARAD, SIBIU, 140);
  grafo.addPoint(ARAD, TIMISOARA, 118);
  grafo.addPoint(TIMISOARA, LUGOJ, 111);
  grafo.addPoint(LUGOJ, MEHADIA, 70);
  grafo.addPoint(MEHADIA, DROBETA, 75);
  grafo.addPoint(DROBETA, CRAIOVA, 120);
  grafo.addPoint(SIBIU, FAGARAS, 99);
  grafo.addPoint(SIBIU, RVILCEA, 80);
  grafo.addPoint(RVILCEA, PITESTI, 97);
  grafo.addPoint(RVILCEA, CRAIOVA, 146);
  grafo.addPoint(CRAIOVA, PITESTI, 138);
  grafo.addPoint(FAGARAS, BUCHAREST, 211);
  grafo.addPoint(PITESTI, BUCHAREST, 101);
  grafo.addPoint(BUCHAREST, GIURGIU, 90);
  grafo.addPoint(BUCHAREST, URZICENI, 85);
  grafo.addPoint(URZICENI, HIRSOVA, 98);
  grafo.addPoint(URZICENI, VASLUI, 142);
  grafo.addPoint(HIRSOVA, EFORIE, 86);
  grafo.addPoint(VASLUI, IASI, 92);
  grafo.addPoint(IASI, NEAMT, 87);
}

int main(int argc, char *argv[]){

  Graph graph;
  InitGrafo(graph);               // Inicia o mapa da Romenia

  WidthSearch bfs;
  vector<Node> solution;          // Vetor de soluções

  int _originInt, _destinyInt;;
  string _origin, _destiny;
  State origin, destiny;

  string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                      "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                      "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                      "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                      };


  _originInt = inputCMD(argv[1]);       // Retorna o inteiro referente a origem
  _destinyInt = inputCMD("bucharest");  // Retorna o inteiro referente ao destino

  origin = State(_originInt);       // Define o Estado de origem na classe State
  destiny = State(_destinyInt);     // Define o Estado de destino na classe State

  cout << "Search in Width:" << endl << endl;
  solution = bfs.BFS(origin, destiny, graph);  // Armazena o vetor de solução em solution
  
  cout << "Solution: " << "[ ";

  for(auto element : solution){
      cout << CityName[element.getStateNode().getState()] << " ";   // Printa a solução     
  }
  cout << "]" << endl;

  // cout << CityName[ptr->getStateNode().getState()] << endl;
  // cout << CityName[ptr->getDad()->getStateNode().getState()] << endl;

  return 0;

}