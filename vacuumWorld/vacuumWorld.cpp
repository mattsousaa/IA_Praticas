#include <iostream>
#include <vector>

using namespace std;

/*

*Perception:

*location - variável booleana que é verdadeira quando o robô está na sala A e falsa quando o robô está na sala B.

*isDirty - variável booleana que é verdadeira se a sala na qual o robô se encontra está suja e falsa caso a sala que 
o robô se encontra esteja limpa.

*/

class Perception {

    bool location;
    bool isDirty;

public:

    Perception(bool location = false, bool isDirty = true){
        this->isDirty = isDirty;
        this->location = location;
    }

    bool getIsDirty(){
        return this->isDirty;
    }

    void setIsDirty(bool value){
        this->isDirty = value;
    }

    bool getLocation(){
        return this->location;
    }

    void setLocation(bool value){
        this->location = value;
    }

};


/*

*Action

*name - string que armazena o nome de uma ação do agente.

*/

class Action {
    string name;
    
public:

    Action(string name){
        this->name = name;
    }

    string getName(){
        return this->name;
    }

};


/*

*Agent

*perception - variavel  que  ira  armazenar  a  percepção  atual  do agente proveniente do sensor de localização e 
verificação de sujeira.

*actions - conjunto de ações que o agente pode executar.

A classe Agent terá duas especializações TableDrivenAgent (agente dirigido por tabela) e SimpleReflexAgent 
(agente reativo simples) nas quais serão implementadas as especificidades de cada programa de agente.

*/

class Agent {

protected:

    Perception perception;
    vector<Action> actions;

public:

    void setPerception(Perception perception){
        this->perception = perception;
    }

    Perception getPerception(){
        return this->perception;
    }
};


/*

*Environment

∗ isDirtyA - variável booleana que é verdadeira se a sala A está limpa.
∗ isDirtyB - variável booleana que é verdadeira se a sala B está limpa.
∗ agentLocation - variável booleana que é verdadeira se o agente está na sala A e falsa se o agente está na sala B.

*/

class Environment {

    bool isDirtyA, isDirtyB, agentLocation;

public:

    Environment(bool isDirtyA, bool isDirtyB, bool agentLocation){
        this->isDirtyA = isDirtyA;
        this->isDirtyB = isDirtyB;
        this->agentLocation = agentLocation;
    }

    Perception getPerception(){
        return Perception(agentLocation, agentLocation ? isDirtyA : isDirtyB);
    }

    void updateEnvironment(Perception p){
        p.getLocation() ? isDirtyA = p.getIsDirty() : isDirtyB = p.getIsDirty();
        this->agentLocation = p.getLocation();
    }

    bool isDirty(){
        return this->isDirtyA | this->isDirtyB;
    }

    bool getIsDirtyA() const{
        return isDirtyA;
    }

    void setIsDirtyA(bool value){
        this->isDirtyA = value;
    }

    bool getIsDirtyB() const{
        return isDirtyB;
    }

    void setIsDirtyb(bool value){
        this->isDirtyB = value;
    }

    bool getAgentLocation() const{
        return this->agentLocation;
    }
    void setAgentLocation(bool value){
        this->agentLocation = value;
    }
};


/*

*SimpleRefrexAgent

Herança da classe Agent. 

*/

class SimpleRefrexAgent : Agent {

private:

public:

    Action selectAction(Perception perception1){

        this->perception = perception1;

        if(perception.getIsDirty()){
            this->actions.push_back(Action("Aspirar"));
            this->perception.setIsDirty(false);
            return Action("Aspirar");
        }
        else if(perception.getLocation()){
            this->actions.push_back(Action("Direita"));
            this->perception.setLocation(false);
            return Action("Direita");
        }
        else if(!perception.getLocation()){
            this->actions.push_back(Action("Esquerda"));
            this->perception.setLocation(true);
            return Action("Esquerda");
        }
    }

    void setPerception(Perception perception){
        this->perception = perception;
    }

    Perception getPerception(){
        return this->perception;
    }
};

int main(){

    SimpleRefrexAgent s;

    int num;
    bool location,dirtyA, dirtyB;
    cout << "Digite a quantidade de interações: " << endl;
    cin >> num;

    //cout << "Location, dirtyA, dirtyB" << endl;
    //cin >> location >> dirtyA >> dirtyB;

    Environment ambiente(true,true,true);

    while(num > 0){

        s.setPerception(ambiente.getPerception());

        cout << "Sala: ";
        cout << (ambiente.getAgentLocation() ? "A" : "B") << endl;

        cout << "Suja: ";
        cout << (ambiente.getAgentLocation() ? (ambiente.getIsDirtyA() ? "Sim" : "Não") : (ambiente.getIsDirtyB() ? "Sim" : "Não")) << endl;
        cout << s.selectAction(s.getPerception()).getName() << endl << endl;

        ambiente.updateEnvironment(s.getPerception());

        num--;
    }

}
