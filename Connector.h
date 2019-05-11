#ifndef _CONNECTOR_H_ 
#define _CONNECTOR_H_

#include "Juat.h"

class Connector: public Juat{
	private:
 		string connex;
		Command* comma;

	public:
<<<<<<< HEAD
=======
		Connector(){	};
		Connector(string c){connex = c};
		virtual string get_Line() = 0;	
		virtual bool run() = 0;
}
>>>>>>> OKH
	

#endif
