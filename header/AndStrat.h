#ifndef __ANDSTRAT_H__
#define __ANDSTRAT_H__
#include "Connector.h"

class AndStrat : public Connector{
public:

AndStrat(){connex = "&&";};

virtual bool run(bool runned){
if(runned == true) return true;
else return false;
}
string getConnex(){return connex;}
};
#endif
