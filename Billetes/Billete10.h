#ifndef BILLETE10_H
#define BILLETE10_H

#include "billete.h"

#define _10_BILLET_VALUE (10) //Valor del billete

class Billete10 : public Billete
{
public:
	Billete10() { value = _10_BILLET_VALUE; }
	~Billete10() {}

private:

};






#endif