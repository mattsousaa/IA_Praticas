#include "node.h"

Node::Node(){}

Node::Node(State _state, Node *_dad, Action _action, int _euristic, float _cost){
    state = _state;
    dad = _dad;
    action = _action;
    euristic = _euristic;
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

int Node::getEuristic(){
    return euristic;
}

void Node::setEuristic(int _euristic){
    euristic = _euristic;
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