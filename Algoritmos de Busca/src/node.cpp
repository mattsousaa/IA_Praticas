#include "node.h"

Node::Node(){}

Node::Node(State _state, Node *_dad, Action _action, float _cost){
    state = _state;
    dad = _dad;
    action = _action;
    pathCost = _cost;
}

State Node::getStateNode(){
    return state;
}

void Node::setState(State value){
    state = value;
}

float Node::getPathCost(){
    return pathCost;
}

void Node::setPathCost(float value){
    pathCost = value;
}

Action Node::getAction(){
    return action;
}

void Node::setAction(Action value){
    action = value;
}

Node &Node::getDad(){
    return *dad;
}

void Node::setDad(Node *value){
    dad = value;
}

bool Node::operator==(Node &_node){
    return this->pathCost == _node.getPathCost();
}
