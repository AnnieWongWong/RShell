#ifndef __SEMICOLONSTRAT_H__
#define __SEMICOLONSTRAT_H__

#include "Connector.h"

class SemiColon : public Connector{
public:

SemiColon(){connex = ";";
}
bool run(bool runned);

string getstring(){return connex;}

};


#endif
