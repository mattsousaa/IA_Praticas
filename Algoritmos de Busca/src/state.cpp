#include "state.h"




State::State(){}

State::State(int _state){
    state = _state;
}

int State::getState(){
    return state;
}

void State::setState(int value){
    state = value;
}
