#include "graph.h"




Graph::Graph(){}

void Graph::addPoint(int _line, int _column, int weight){
    graph[_line][_column] = weight;
}

int Graph::getWeight(int _line, int _column){
    if(graph[_line][_column]){
        return graph[_line][_column];
    }else if (graph[_column][_line]) {
        return graph[_column][_line];
    }
    return 0;
}
