#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class State{
    int state;
  public:
    State();
    State(int _state);

    int getState();
    void setState(int value);
};

#endif // STATE_H
