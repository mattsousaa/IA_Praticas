#include "action.h"


Action::Action(){}

Action::Action(State _origin, State _destiny){
    origin = _origin;
    destiny = _destiny;
}

State Action::getOrigin(){
    return origin;
}

void Action::setOrigin(State value){
    origin = value;
}

State Action::getDestiny(){
    return destiny;
}

void Action::setDestiny(State value){
    destiny = value;
}
