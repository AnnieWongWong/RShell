#ifndef _EXECUTABLE_H_
#define _EXECUTABLE_H_
#include <vector>
#include "Juat.h"
using namespace std;

class Executable : public Juat{
    private:
        vector<string> exec;
        
    public:
        Executable(){ 
            string x ;
            int i = 0;
            
            while (i != 2){
                cout << "enter string" << endl;
                cin >> x;
                exec.push_back(x);
                i++;
            }
        }
        Executable(vector<string> executable){exec = executable;}
        string getstring(){
            return exec.at(0);
        }
        bool run(bool x);
};

#endif