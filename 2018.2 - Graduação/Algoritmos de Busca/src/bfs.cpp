#include "bfs.h"
#include "graph.h"


Width_Search::Width_Search(){}

vector<Node> Width_Search::BFS(State _origin, State _destiny, Graph graph){

    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                              "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                              "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                              "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                             };


    //Initializing at the root of the graph
    Node nodeInit;
    nodeInit.setAction(Action(_origin, _destiny));
    //nodeInit.setPathCost(0);
    nodeInit.setDad(nullptr);
    nodeInit.setState(State(_origin.getState()));
    //Finishing at the root of the graph

    queue<Node> edge;
    vector<Node> solution;

    //Checking whether the initial state is the destination
    if(nodeInit.getStateNode().getState() == _destiny.getState()){
        return solution;
    }

    //If it is not add on edge
    edge.push(nodeInit);

    // Declaring exploited
    bool explored[SIZE_MAP];
    for(int i = 0; i <  SIZE_MAP; i++){
        explored[i] = false;
    }


    while (true) {
        //Checking if edge is empty
        if(edge.empty()){
            throw string("Fail edge is empty!\n");
        }


        //taking element from edge
        nodeInit = edge.front();

        //removing element from edge and setting element as explored
        edge.pop();
        int currentLocation = nodeInit.getStateNode().getState();
        if(!explored[currentLocation]){
            cout << "Visiting " << CityName[currentLocation] << "..." << endl;
            solution.push_back(nodeInit);
            explored[currentLocation] = true;
        }

        int weight_total = 0;
        int atual_weight = 0;
        int column = 0;
        for(column = 0; column < SIZE_MAP; column++){
            if(graph.getWeight(currentLocation, column)){
                //cout << "Weight " << graph.getWeight(currentLocation, column) << endl;
                atual_weight = graph.getWeight(currentLocation, column);
                weight_total = weight_total + atual_weight;
            }
        }   

        for(column = 0; column < SIZE_MAP; column++){
            //cout << "Weight " << graph.getWeight(currentLocation, column) << endl;
            if(graph.getWeight(currentLocation, column)){
                Node newNo = Node(State(column), &nodeInit, Action(currentLocation, column), 0);
                if(!explored[newNo.getStateNode().getState()]){
                    if((newNo.getStateNode().getState()) == _destiny.getState()){
                        cout << "Weight total " << weight_total << endl;
                        return solution;      
                    }
                    edge.push(newNo);
                }
            }
        }
    }
}
