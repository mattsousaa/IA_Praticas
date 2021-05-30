#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include "enum.h"
#include "graph.h"
#include "state.h"
#include "node.h"

using namespace std;

//Width search.
class Width_Search{
public:
    Width_Search();

    vector<Node> BFS(State _origin, State _destiny, Graph graph);
};


#endif // BFS_H
