#ifndef _EXECUTABLE_H_
#define _EXECUTABLE_H_
#include "Juat.h"
#include <string>
#include <vector>
using namespace std;

class Executable: public Juat{
    private:
        vector<string> exec;
        
    public:
        Executable(){}
        Executable(vector<string> executable){exec = executable;}
        bool run();
        bool run2(bool prev){return false;}
        string getConnex();
};

#endif 

