#ifndef _CONNECTOR_H_ 
#define _CONNECTOR_H_

#include "Juat.h"
#include "Command.h"
using namespace std;

class Connector: public Juat{
	protected:
 		string connex;
		Command* comma;

	public:
		Connector(){	}
		Connector(string c){connex = c;}
		virtual bool run(bool x){return true;}
		virtual string getstring(){}
};

	

#endif
