#ifndef __SEMICOLONSTRAT_H__
#define __SEMICOLONSTRAT_H__

#include "Connector.h"

class SemiColon : public Connector{
public:

SemiColon();
virtual bool run1(){ return true;}
bool run2(bool runned);

string getConnex(){return connex;}
};

#endif
