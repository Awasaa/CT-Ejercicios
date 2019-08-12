#ifndef BILLETE20_H
#define BILLETE20_H

#include "Billete.h"

#define _20_BILLET_VALUE (20)

class Billete20 : public Billete
{
public:
	Billete20() { value = _20_BILLET_VALUE; }
	~Billete20() {}

private:

};


#endif