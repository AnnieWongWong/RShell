#ifndef __ORSTRAT_H__
#define __ORSTRAT_H__
#include "Connector.h"

class OrStrat : public Connector{

virtual bool run(bool runned){
if(runned == false) return true;
else return false;
}
};
#endif