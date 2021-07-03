#include <iostream>
#include "bfs.h"
#include "graph.h"

WidthSearch::WidthSearch(){}

    vector<Node> WidthSearch::BFS(State _origin, State _destiny, Graph graph){
    
    string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                         "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                         "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                         "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                        };

    Node *nodeInit = new Node();                        // Inicializa o nó raiz (nó de inicialização)
    nodeInit->setAction(Action(_origin, _destiny));     // Onde estou e para onde vou
    nodeInit->setDad(nullptr);                          // o nó inicial não tem pai
    nodeInit->setState(State(_origin.getState()));      // _origin.getState() retorna o estado em questão 

    queue<Node> edge;                                   // Fila de cidades (borda)
    vector<Node> solution;                              // Solução final (caminho de A até B)
    vector<string> path;                                // Caminho final da folha até a raiz

    // Verifica se o estado inicial é o destino
    if(nodeInit->getStateNode().getState() == _destiny.getState())
        return solution;

    // Se não é a cidade final então coloca na borda/fila
    edge.push(*nodeInit);

    // Declaração de um vetor de cidades exploradas (sim/não)
    bool explored[SIZE_MAP];

    for(int i = 0; i < SIZE_MAP; i++){
        explored[i] = false;                // por enquanto nenhuma cidade foi explorada
    }

    while(true){

        // Verifica se a borda está vazia
        // if(edge.empty()){
        //     throw string("Fail edge is empty!\n");  // lança exceção (catch na main)
        // }

        nodeInit = &edge.front();                                       // Pega o primeiro elemento/cidade da fila (borda)

        edge.pop();                                                     // Remove elemento da borda e define como explorado

        int currentLocation = nodeInit->getStateNode().getState();   // Pega a referência da cidade atual (em qual cidade nós estamos agora?)

        // Define a cidade atual como explorada
        // Se a cidade já tiver sido explorada, então não adiciona-se no vetor de solução
        if(!explored[currentLocation]){
            cout << "Visiting " << CityName[currentLocation] << "..." << endl;
            solution.push_back(*nodeInit);                              // Acrescenta o nó no vetor de solução    
            explored[currentLocation] = true;                           // Cidade atual agora está explorada no vetor de explorados
        }

        int weight_total = 0;                           // Peso total do caminho da folha até a raíz
        int atual_weight = 0;                           // Peso atual de uma cidade
        int column = 0;                                 // Coluna representa as cidades

        for(column = 0; column < SIZE_MAP; column++){                                                   // Itera 20x (procura todas as possibilidades de adjacência do mapa)
            if(graph.getWeight(currentLocation, column)){                                               // Pega os pesos das cidades adjacentes (só entra se existir adjacentes)
                
                Node *newNo = new Node(State(column), nodeInit, Action(currentLocation, column), 0);

                if(!explored[newNo->getStateNode().getState()]){                         // Verifico se o novo nó não foi explorado
                    if((newNo->getStateNode().getState()) == _destiny.getState()){       // O novo nó é o destino final que eu quero? 
                        //cout << CityName[newNo->getDad()->getStateNode().getState()] << endl;
                        //cout << CityName[newNo->getDad()->getDad()->getDad()->getStateNode().getState()] << endl;

                        // Adiciono o destino no vetor de caminho final
                        path.push_back(CityName[newNo->getStateNode().getState()]);

                        // Agora retorna até a raíz    
                        while(newNo->getDad() != nullptr){                                                                  // Enquanto não chegar no pai faça
                            //cout << CityName[newNo->getDad()->getStateNode().getState()] << endl;
                            path.push_back(CityName[newNo->getDad()->getStateNode().getState()]);                           // Adiciono o pai no vetor de caminho final

                            currentLocation = newNo->getStateNode().getState();                                             // atualiza a localização a cada iteração                                      
                                   
                            atual_weight = graph.getWeight(currentLocation, newNo->getDad()->getStateNode().getState());    // Pega o peso passando a localização atual e a cidade
                            //cout << "atual: " << atual_weight << endl;
                            weight_total += atual_weight;                                                                   // Acumula os pesos ao longo do caminho
                            
                            newNo = newNo->dad;                                                                             // Passa para o próximo nó pai
                        }

                        cout << "\nFinal Path: " << "[ ";

                        for(auto k : path)
                            cout << k << " ";   // Printa o caminho do destino até a origem 
                        
                        cout << "]" << endl;

                        cout << "Total Weight: " << weight_total << endl;

                        return solution;                                                    // Retorna o vetor de solução (cidades exploradas)
                    }
                    edge.push(*newNo);                                                      // Se não for o destino eu coloco o nó na fila
                }
            }
        }   
    }
}