#include "ucs.h"

UniformCostSearch::UniformCostSearch(){}

vector<Node> UniformCostSearch::UCS(State _origin, State _destiny, Graph graph){

    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                              "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                              "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                              "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                             };

    //Initializing at the root of the graph

    Node nodeInit;
    nodeInit.setAction(Action(_origin, _destiny));
    nodeInit.setPathCost(0);
    nodeInit.setDad(nullptr);
    nodeInit.setState(State(_origin.getState()));

    priority_queue<Node,vector<Node>,Node::SortByCost> edge;
    vector<Node> solution;

    edge.push(nodeInit);

    bool explored[SIZE_MAP];
    for(int i = 0; i <  SIZE_MAP; i++){
        explored[i] = false;
    }

    while(true){
        if(edge.empty())
            throw string("Fail edge is empty!\n");

        nodeInit = edge.top();

        if(nodeInit.getStateNode().getState() == _destiny.getState()){
            solution.push_back(nodeInit);
            return solution;
        }

        edge.pop();
        int line = nodeInit.getStateNode().getState();
        if(!explored[line]){
            cout << "Visiting " << CityName[line] << "..." << endl;
            solution.push_back(nodeInit);
            explored[line] = true;
        }


        for(int j = 0; j < SIZE_MAP; j++){
            if(graph.getWeight(line,j)){
                Node newNo = Node(State(j),&nodeInit,Action(line,j),nodeInit.getPathCost() + graph.getWeight(line,j));
                if(!explored[newNo.getStateNode().getState()]){
                    edge.push(newNo);
                }
            }
        }
    }
}
