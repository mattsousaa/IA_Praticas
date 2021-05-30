#include <iostream>
#include "greedy_search.h"
#include "graph.h"
#include "heuristics.h"

string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                         "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                         "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                         "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                        };

// Função que retorna o número de filhos de um nó correspondente i
int getQtdAdjacents(int i, Graph *graph){

    int count = 0;

    for(int column = 0; column < SIZE_MAP; column++){
        if(graph->getWeight(i, column)){ 
            count++;
        }
    }    

    return count;
}

GreedySearch::GreedySearch(){}

    vector<Node> GreedySearch::GSearch(State _origin, State _destiny, Graph graph){

    Node *nodeInit = new Node();                                                            // Inicializa o nó raiz (nó de inicialização)
    nodeInit->setAction(Action(_origin, _destiny));                                         // Onde estou e para onde vou
    nodeInit->setDad(nullptr);                                                              // o nó inicial não tem pai
    nodeInit->setState(State(_origin.getState()));                                          // _origin.getState() retorna o estado em questão 
    nodeInit->setHeuristic(heuristicCity(CityName[nodeInit->getStateNode().getState()]));   // Define a heurística do nó

    queue<Node> edge;                                                                       // Fila de cidades (borda)
    vector<Node> solution;                                                                  // Solução final (caminho de A até B)
    vector<string> path;                                                                    // Caminho final da folha até a raiz
    priority_queue<Node,vector<Node>,Node::SortByCost> fila;                                // Fila de prioridades de nós organizados por menor heuristica
    int child = 0;                                                                          // Contador para contagem de nós filhos

    if(nodeInit->getStateNode().getState() == _destiny.getState())                          // Verifica se o estado inicial é o destino
        return solution;

    edge.push(*nodeInit);                                                                   // Se não é a cidade final então coloca na borda/fila

    bool explored[SIZE_MAP];                                                                // Declaração de um vetor de cidades exploradas (sim/não)

    for(int i = 0; i < SIZE_MAP; i++){
        explored[i] = false;                                                                // Por enquanto nenhuma cidade foi explorada
    }

    while(true){

        nodeInit = &edge.front();                                                           // Pega o primeiro elemento/cidade da fila (borda)

        edge.pop();                                                                         // Remove elemento da borda e define como explorado

        int currentLocation = nodeInit->getStateNode().getState();                          // Pega a referência da cidade atual (em qual cidade nós estamos agora?)

        // Define a cidade atual como explorada
        // Se a cidade já tiver sido explorada, então não adiciona-se no vetor de solução
        if(!explored[currentLocation]){
            cout << "Visiting " << CityName[currentLocation] << "..." << endl;
            solution.push_back(*nodeInit);                                                  // Acrescenta o nó no vetor de solução    
            explored[currentLocation] = true;                                               // Cidade atual agora está explorada no vetor de explorados
            //cout << "Filhos: " << getQtdAdjacents(currentLocation, &graph) << endl;
        }

        int heuristic_total = 0;                                                            // Heuristica total do caminho da folha até a raíz
        int atual_heuristic = 0;                                                            // Heuristica atual de uma cidade
        int column = 0;                                                                     // Coluna representa as cidades

        for(column = 0; column < SIZE_MAP; column++){                                                   // Itera 20x (procura todas as possibilidades de adjacência do mapa)
            if(graph.getWeight(currentLocation, column)){                                               // Pega os pesos das cidades adjacentes (só entra se existir adjacentes)
                
                Node *newNo = new Node(State(column), nodeInit, Action(currentLocation, column), 0);    // Cria novo nó filho
                newNo->setHeuristic(heuristicCity(CityName[newNo->getStateNode().getState()]));         // Seta a heuristica para cada nó expandido
                fila.push(*newNo);                                                                      // Coloca o nó na fila de prioridades
                child++;                                                                                // Conta mais um nó filho expandido

                if(child == getQtdAdjacents(currentLocation, &graph)){                                  // Todos os nós filhos já foram expandidos?

                    Node *n = (Node *)&fila.top();                                                      // Pego o nó de menor heuristica na fila de prioridades
                    //cout <<  CityName[n->getStateNode().getState()] << endl;

                    if(!explored[n->getStateNode().getState()]){                                        // Verifico se o novo nó não foi explorado
                                          
                        if((n->getStateNode().getState()) == _destiny.getState()){                      // O novo nó é o destino final que eu quero? 

                            path.push_back(CityName[n->getStateNode().getState()]);                     // Adiciono o destino no vetor de caminho final

                            // Agora retorna até a raíz    
                            while(n->getDad() != nullptr){                                              // Enquanto não chegar no pai faça

                                path.push_back(CityName[n->getDad()->getStateNode().getState()]);       // Adiciono o pai no vetor de caminho final

                                currentLocation = n->getStateNode().getState();                         // atualiza a localização a cada iteração                                      

                                atual_heuristic = n->getDad()->getHeuristic();                          // Pega a heuristica do pai
                               
                                heuristic_total += atual_heuristic;                                     // Acumula as heuristicas ao longo do caminho
                                
                                n = n->dad;                                                             // Passa para o próximo nó pai
                            }

                            cout << "\nFinal Path: " << "[ ";

                            for(auto k : path)
                                cout << k << " ";                                                   // Printa o caminho do destino até a origem 
                            
                            cout << "]" << endl;

                            cout << "Total Heuristics: " << heuristic_total << endl;

                            return solution;                                                        // Retorna o vetor de solução (cidades exploradas)
                        }
                        edge.push(*n);                                                              // Se não for o destino eu coloco o nó de menor heuristica na fila (borda)
                        fila = priority_queue<Node,vector<Node>,Node::SortByCost> ();               // Esvazio a fila de prioridades 
                        child = 0;                                                                  // Zera o contador de filhos
                    }                                                 
                }
            }
        }   
    }
}