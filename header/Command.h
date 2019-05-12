#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "Juat.h"

class Node{
friend class Command;
protected:
   Node* parent;
   
   bool success;
   bool isRoot;
   bool isConnecter;

public:
   Node* left;
   Node* right;
   Juat* j;
   Node(){left = 0; right  = 0; parent = 0; j = 0; success = false;}
   Node(Node* l, Node* r, Node* p, Juat* jay, bool heim){left = l; right = r; parent = p; j = jay; success = heim;}
   void setLeft(Node* exec){left = exec; exec->parent = this;}
   void setRight(Node* connex){right = connex; connex->parent = this;}
   void setParent(Node* p){ parent = p;}
   Node* getParent(){return parent;}
   void setleft(Node* exec){left = exec;}
   void setright(Node* connex){right = connex;}
   Juat* getJuat(){return j;}
   void setRoot(){isRoot = true;}
   bool getIsRoot(){return isRoot;}
   bool getIsConnector(){return isConnecter;}
   void setConnector(){isConnecter = true;}
   bool evaluate(){
      return j->run(success);
   }
   void setBool(bool succes){success = succes;}
   bool successful(){return success;}
};

class Command : public Juat{
protected:
   bool eqex;
   Node* root;
   Node* power;

public:
   Command();
   void start_Command_prompt();
   bool getEqex(){return eqex;}
   bool run();

};
#endif
