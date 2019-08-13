#ifndef BILLETE_H
#define BILLETE_H

class Billete
{
public:
	//constructor y destructor
	Billete() {};
	~Billete() {};

	//Metodo comun a todos los billetes
	int getValue(void) { return value; };

protected:

	int value;	//valor de cada billete que herede

};


#endif