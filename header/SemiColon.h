#ifndef __SEMICOLONSTRAT_H__
#define __SEMICOLONSTRAT_H__

#include "Connector.h"

class SemiColon : public Connector{
public:

SemiColon(){}

bool run(bool runned);

string getCrets(){return connex;}
};

#endif
