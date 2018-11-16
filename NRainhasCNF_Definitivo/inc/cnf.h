#ifndef CNF_H
#define CNF_H
#include <fstream>
#include <sstream>


using namespace std;

class CNF{
private:
    string FileDirectory;
    int N, qtd;
    ofstream cnfFile;
    int getLocation(int i, int j);

public:
    
    CNF(int N);
    bool MakeCnfFile();
    string getFileDirectory();
};



#endif // CNF_H