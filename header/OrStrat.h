#ifndef __ORSTRAT_H__
#define __ORSTRAT_H__
#include "Connector.h"

class OrStrat : public Connector{
public:
OrStrat(){connex = "||";};
<<<<<<< HEAD
virtual bool run(bool runned){
	if(runned == false) 
		return true;
	else {
	 return false;
	}
}

=======

virtual bool run(bool runned){
if(runned == false) return true;
else return false;
}
string getErOfSe(){return connex;}
>>>>>>> 5fde9cb240cfe9ca685f658412f50aa760bd5590
};
#endif
