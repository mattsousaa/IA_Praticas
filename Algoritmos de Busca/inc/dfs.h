#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>
#include <string>
#include <stack> // Pilha para Busca por profundidade (DFS)
#include "enum.h"
#include "graph.h"
#include "state.h"
#include "node.h"

using namespace std;
//Deep Search.
class Deep_Search{
public:
    Deep_Search();

    vector<Node> DFS(State _origin, State _destination, Graph _graph);
};

#endif // DFS_H
