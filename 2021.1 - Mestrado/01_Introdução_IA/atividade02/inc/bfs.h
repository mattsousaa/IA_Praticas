#ifndef BFS_H
#define BFS_H

#include <vector>
#include <string>
#include <queue>
#include "enum.h"
#include "graph.h"
#include "state.h"
#include "node.h"

using namespace std;

// breadth-first search

class WidthSearch {
public:
    WidthSearch();

    vector<Node> BFS(State _origin, State _destiny, Graph graph);
};


#endif // BFS_H