#ifndef _JUAT_H_
#define _JUAT_H_

#include <string>
using namespace std;

class Juat{
	public:
		Juat(){}
		virtual bool run() = 0;
   virtual bool run2(bool runned) = 0;
   virtual string getConnex()=0;
};

#endif
