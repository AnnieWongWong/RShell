#ifndef _CONNECTOR_H_ 
#define _CONNECTOR_H_

#include "Juat.h"
#include "Command.h"

class Connector: public Juat{
	protected:
 		string connex;
		Command* comma;

	public:
		Connector(){	};
		Connector(string c){connex = c;};
		virtual bool run(){return true;};
};

	

#endif
