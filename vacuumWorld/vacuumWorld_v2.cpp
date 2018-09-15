#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Environment{

public:

    bool isdirtyA;
    bool isdirtyB;
    bool agentLocation;


    Environment(bool isdirtyA = true, bool isdirtyB = true, bool agentLocation = true) {
        this->isdirtyA = isdirtyA;
        this->isdirtyB = isdirtyB;
        this->agentLocation = agentLocation;
    }

    bool getdirtyA(){
        return this->isdirtyA;
    }

    void setdirtyA(bool dirtyA){
        this->isdirtyA = dirtyA;
    }

    bool getdirtyB(){
        return this->isdirtyB;
    }

    void setdirtyB(bool dirtyB){
        this->isdirtyB = dirtyB;
    }

    bool getAgentLocation(){
        return this->agentLocation;
    }

    void setAgentLocation(bool location){
        this->agentLocation = location;
    }
};

class Perception{

    bool location;
    bool isDirty;

public:

    Perception(bool location = true, bool isDirty = true){
        this->location = location;
        this->isDirty = isDirty;
    }

    bool getLocation(){
        return this->location;
    }

    bool getIsDirty(){
        return this->isDirty;
    }

};

class Action{
    string name;

public:

    Action(string name = ""){
        this->name = name;

    }

    string getName(){
        return this->name;
    }
};

class Agent{

    Perception perception;
    vector<Action> actions;

public:

    vector<Action> getActions(){
        return this->actions;
    }
};


class TableDriveAgent : Agent{

    vector<Perception> perceptions;
    map<Perception*,Action*> table;

public:

    void setTable(){

        this->table.insert(make_pair(new Perception(true,false), new Action("Direita")));
        this->table.insert(make_pair(new Perception(true,true), new Action("Aspirar")));
        this->table.insert(make_pair(new Perception(false,false), new Action("Esquerda")));
        this->table.insert(make_pair(new Perception(false,true), new Action("Aspirar")));
    }

    Action selectAction(Perception perception){

        perceptions.push_back(perception);

        map<Perception*,Action*>::iterator it;

        for (it = table.begin(); it != table.end(); it++) {
            if((it->first->getLocation()== perception.getLocation()) && (it->first->getIsDirty() == perception.getIsDirty())){
                return *(it->second);
            }
        }

        return Action("Erro");
    }
};

int main(){


    TableDriveAgent agent;
    Action action;

    int number;
    bool location,dirtyA, dirtyB;
    bool isDirty;

    cout << "Digite o numero de vezes que o agente deve agir: " << endl;
    cin >> number;
    cout << "Location, dirtyA, dirtyB" << endl;
    cin >> location >> dirtyA >> dirtyB;

    Environment environment(location,dirtyA,dirtyB);

    agent.setTable();

    for(int i = 0; i < number; i++){
        
        cout << "Location: " << environment.getAgentLocation() << " isDurtyA: " << environment.getdirtyA()
         << " isDurtyB: " << environment.getdirtyB() << endl;

        environment.getAgentLocation() ? isDirty = environment.getdirtyA() : isDirty = environment.getdirtyB();
        action = agent.selectAction(Perception(environment.getAgentLocation(), isDirty));

        cout << "Action: " << action.getName() << endl;

        if(action.getName() == "Aspirar"){
            environment.getAgentLocation() ? environment.setdirtyA(0) : environment.setdirtyB(0);
        }
        if(action.getName() == "Esquerda"){
            environment.setAgentLocation(1);
        }
        if(action.getName() == "Direita"){
            environment.setAgentLocation(0);
        }
    }
}
