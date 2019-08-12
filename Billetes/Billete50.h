#ifndef BILLETE50_H
#define BILLETE50_H

#include "Billete.h"

#define _50_BILLET_VALUE (50)

class Billete50 : public Billete
{
public:
	Billete50() { value = _50_BILLET_VALUE; }
	~Billete50() {}

private:

};




#endif