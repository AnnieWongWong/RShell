#ifndef _EXECUTABLE_H_
#define _EXECUTABLE_H_

#include <vector>
using namespace std;

class Executable: public Juat{
    private:
        vector<string> exec;
        
    public:
        Executable(){}
        Executable(vector<string> executable){exec = executable;}
        string get_Line(){ return "Nothing";}
        bool run();
};

#endif _EXECUTABLE_H_