#ifndef BILLETE1_H
#define BILLETE1_H

#include "billete.h"

#define _1_BILLET_VALUE (1)	//Valor del billete

class Billete1 : public Billete
{
public:
	Billete1() { value = _1_BILLET_VALUE; }
	~Billete1() {}

private:

};

#endif
