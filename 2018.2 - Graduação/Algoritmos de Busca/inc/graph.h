#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include "enum.h"
using namespace std;

class Graph{
    int graph[20][20];
  public:
    Graph();

    void addPoint(int _line, int _column, int weight);
    int getWeight(int _line, int _column);
};


#endif // GRAFO_H
