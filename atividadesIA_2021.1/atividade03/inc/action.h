#ifndef ACTION_H
#define ACTION_H

#include "state.h"

using namespace std;

class Action {

private:
    State origin;
    State destiny;

public:
    Action();
    Action(State _origin, State _destiny);
    State getOrigin();
    void setOrigin(State value);
    State getDestiny();
    void setDestiny(State value);
};

#endif // ACTION_H