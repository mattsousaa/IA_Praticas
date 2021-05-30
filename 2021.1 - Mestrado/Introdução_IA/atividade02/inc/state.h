#ifndef STATE_H
#define STATE_H

using namespace std;


class State {

private:
    int state;

public:
    State();
    State(int _state);
    int getState();            
    void setState(int value);
};

#endif // STATE_H