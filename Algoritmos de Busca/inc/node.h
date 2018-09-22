#ifndef NODE_H
#define NODE_H

#include "state.h"
#include "action.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    State state;
    float pathCost;
    int euristic;
    Action action;
public:
    Node * dad;
    Node();
    Node(State _state, Node* _dad, Action _action, int _euristic, float _cost);

    State getStateNode();

    void setState(State value);

    float getPathCost();

    void setPathCost(float value);

    Action getAction();

    void setAction(Action value);

    Node& getDad();

    int getEuristic();

    void setEuristic(int _euristic);

    void setDad(Node *value);

    bool operator==(Node& _node);

    struct SortByCost{
        bool operator()(Node& lhs, Node& rhs){
            return lhs.getPathCost() > rhs.getPathCost();
        }
    };

};


#endif // NODE_H