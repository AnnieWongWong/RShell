#ifndef _CONNECTOR_H_ 
#define _CONNECTOR_H_

#include "Juat.h"

class Connector: public Juat{
	private:
 		string connex;
		Command* comma;

	public:
		Connector(){	};
		Connector(string c){connex = c};	
		virtual bool run() = 0;
}
	

#endif
