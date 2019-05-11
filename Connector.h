#ifndef _CONNECTOR_H_ 
#define _CONNECTOR_H_

#include "Juat.h"

class Connector: public Juat{
	private:
		ConnectStrat* s; 

	public:
		string get_Line(string input);
		void bool run(string connector);

};
	

#endif
