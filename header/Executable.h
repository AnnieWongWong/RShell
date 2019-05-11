#ifndef _EXECUTABLE_H_
#define _EXECUTABLE_H_

class Executable: public Juat{
    private:
        string exec;
        
    public:
        Executable(){}
        Executable(string executable){exec = executable;}
        string get_Line(){ return "Nothing";}
        void run();
};

#endif _EXECUTABLE_H_