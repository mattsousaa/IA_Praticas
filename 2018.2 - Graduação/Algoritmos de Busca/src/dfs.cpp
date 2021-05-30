#include "dfs.h"




Deep_Search::Deep_Search(){}

vector<Node> Deep_Search::DFS(State _origin, State _destination, Graph _graph){
    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                              "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                              "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                              "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                             };


    //Initializing at the root of the graph
    Node noInit;
    noInit.setAction(Action(_origin, _destination));
    noInit.setPathCost(0);
    noInit.setDad(nullptr);
    noInit.setState(State(_origin.getState()));

    stack<Node> edge;
    vector<Node> solution;

    //Checking whether the initial state is the destination
    if(noInit.getStateNode().getState() == _destination.getState()){
        return solution;
    }

    //If it is not add on edge
    edge.push(noInit);

    //Declaring exploited
    bool explored[SIZE_MAP];
    for(int i = 0; i <  SIZE_MAP; i++){
        explored[i] = false;
    }

    while (true) {
        //Checking is edge is empty
        if(edge.empty()){
            throw string("Fail edge is empty!\n");
        }

        //taking element from edge
        noInit = edge.top();

        //removing element from edge and setting element as explored
        edge.pop();
        int currentLocation = noInit.getStateNode().getState();
        if(!explored[currentLocation]){
            cout << "Visiting " << CityName[currentLocation] << "..." << endl;
            solution.push_back(noInit);
            explored[currentLocation] = true;
        }


        int column;
        for(column = 0; column < SIZE_MAP; column++){
            if(_graph.getWeight(currentLocation, column)){
                Node newNode = Node(State(column), &noInit, Action(currentLocation, column), 0);
                if(!explored[newNode.getStateNode().getState()]){
                    if((newNode.getStateNode().getState()) == _destination.getState()){
                        return solution;
                    }
                    edge.push(newNode);
                }
            }
        }
    }
}
