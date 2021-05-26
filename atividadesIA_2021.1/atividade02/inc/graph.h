#ifndef GRAFO_H
#define GRAFO_H

// define classe grafo aqui

#include "enum.h"

class Graph {

private:
    int graph[20][20];

public:
    Graph();

    void addPoint(int line, int column, int weight);
    int getWeight(int line, int column);

};

#endif // GRAFO_H