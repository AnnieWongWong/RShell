#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "Juat.h"

class Node{
friend class Command;
protected:
   Node* parent;
   Juat* j;
   bool hohen;

public:
   Node* left;
   Node* right;
   Node(){left = 0; right  = 0; parent = 0; j = 0; hohen = false;}
   Node(Node* l, Node* r, Node* p, Juat* jay, bool heim){left = l; right = r; parent = p; j = jay; hohen = heim;}
   void setLeft(Node* exec){left = exec; exec->parent = this;}
   void setRight(Node* connex){right = connex; connex->parent = this;}
   void setParent(Node* p){ parent = p;}
   Node* getParent(){return parent;}
   void setleft(Node* exec){left = exec;}
   void setright(Node* connex){right = connex;}
   Juat* getJuat(){return j;}
   void evaluate1(){
   	hohen = j->run();
   }
   void evaluate2(bool prevRan){
   	hohen = j->run2(prevRan);
   }
   bool getHohenheim(){return hohen;}
};

class Command : public Juat{
protected:
   bool eqex;
   Node* root;
   Node* power;

public:
   Command();
   void start_Command_prompt();
   bool getEqex();
   bool run();
   bool run2(bool prev){return false;};
   string getConnex(){return 0;}

};
#endif
