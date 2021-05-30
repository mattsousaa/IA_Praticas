#ifndef NODE_H
#define NODE_H

#include "state.h"
#include "action.h"

using namespace std;

class Node {

private:
    State state;
    float pathCost;
    Action action;
    int heuristic;

public:
    Node * dad;

    Node();

    Node(State _state, Node* _dad, Action _action, float _cost);

    State getStateNode();

    void setState(State value);

    float getPathCost();

    void setPathCost(float value);

    Action getAction();

    void setAction(Action value);

    Node* getDad();

    void setDad(Node *value);

    int getHeuristic();

    void setHeuristic(int value);

    bool operator==(Node& _node);

    struct SortByCost{
        bool operator()(Node& lhs, Node& rhs){
            return lhs.getHeuristic() > rhs.getHeuristic();
        }
    };
};


#endif // NODE_H