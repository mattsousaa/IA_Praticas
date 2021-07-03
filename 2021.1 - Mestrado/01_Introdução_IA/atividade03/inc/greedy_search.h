#ifndef GS_H
#define GS_H

#include <vector>
#include <string>
#include <queue>
#include "enum.h"
#include "graph.h"
#include "state.h"
#include "node.h"

using namespace std;

// breadth-first search

class GreedySearch {
public:
    GreedySearch();

    vector<Node> GSearch(State _origin, State _destiny, Graph graph);
};


#endif // GS_H