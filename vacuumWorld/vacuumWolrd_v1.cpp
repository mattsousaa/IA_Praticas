#include <iostream>
#include <vector>

using namespace std;

// struct de identificação de sujeira para cada quarto
struct dirtyState {
    bool roomA;         // 1: sujo; 0: limpo
    bool roomB;         // 1: sujo; 0: limpo
};

/*
*Perception:
*location - variável booleana que é verdadeira quando o robô está na sala A e falsa quando o robô está na sala B.
*isDirty - variável booleana que é verdadeira se a sala na qual o robô se encontra está suja e falsa caso a sala que 
o robô se encontra esteja limpa.
*/

class Perception {

private:

    bool location;
    dirtyState isDirty;

public:

    Perception(bool location = false, bool isDirtyA = false, bool isDirtyB = false){
        this->location = location;
        isDirty.roomA = isDirtyA;
        isDirty.roomB = isDirtyB;
    }

    bool getIsDirty(){
        if(location){   // Se está no quarto A
            return isDirty.roomA;
        } else {        // Se está no quarto B
            return isDirty.roomB;
        }
    }

    void setIsDirty(bool value){
        if(location){   // Se está no quarto A   
            isDirty.roomA = value;
        } else {        // Se está no quarto B
            isDirty.roomB = value;
        }
    }

    bool getLocation(){
        return location;
    }

    void setLocation(bool value){
        location = value;
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
        return perception;
    }
};

/*
*SimpleAgent (agente reativo simples)
Herança da classe Agent. 
De acordo com uma percepção (location e isDirty) ele realiza uma ação(aspirar, direita ou esquerda)
*/

class SimpleAgent : public Agent {

private:

public:

    Action selectAction(Perception perception1){

        this->perception = perception1;

        if(perception.getIsDirty()){
            this->actions.push_back(Action("Aspirar"));     // Coloca "Aspirar" na lista de ações do agente
            this->perception.setIsDirty(false);             // Depois que aspira tá limpo
            return Action("Aspirar");                       // Retorna ação "Aspirar"
        }
        else if(perception.getLocation()){                  // Agente está na sala A
            this->actions.push_back(Action("Direita"));     // Coloca "Direita" na lista de ações do agente
            this->perception.setLocation(false);            // Agente agora está na sala B
            return Action("Direita");                       // Retorna ação "Direita"
        }
        else {                                              // Agente está na sala B (!perception.getLocation())
            this->actions.push_back(Action("Esquerda"));    // Coloca "Esquerda" na lista de ações do agente
            this->perception.setLocation(true);             // Agente agora está na sala A
            return Action("Esquerda");                      // Retorna ação "Esquerda"
        }
        
    }

    void setPerception(Perception perception){
        this->perception = perception;
    }

    Perception getPerception(){
        return perception;
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
        return Perception(agentLocation, isDirtyA, isDirtyB);
    }

    void updateEnvironment(Perception p){
        
        p.getLocation() ? isDirtyA = p.getIsDirty() : isDirtyB = p.getIsDirty();
        agentLocation = p.getLocation();

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

int main(int argc, char *argv[]){

    int num;
    SimpleAgent s;

    num = atoi(argv[1]);

    Environment ambiente(true, true, true);                    // isDirtyA, isDirtyB, agentLocation (1: A, 0: B)

    while(num > 0){

        s.setPerception(ambiente.getPerception());    

        cout << "Sala: ";
        cout << (ambiente.getAgentLocation() ? "A" : "B") << endl;

        cout << "Suja: ";
        cout << (ambiente.getAgentLocation() ? (s.getPerception().getIsDirty() ? "Sim" : "Não") : (s.getPerception().getIsDirty() ? "Sim" : "Não")) << endl;
        cout << s.selectAction(s.getPerception()).getName() << endl << endl;

        ambiente.updateEnvironment(s.getPerception());

        num--;
    }

}