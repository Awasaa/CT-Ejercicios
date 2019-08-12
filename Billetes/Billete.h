#ifndef BILLETE_H
#define BILLETE_H

class Billete
{
public:
	Billete() {};
	~Billete() {};

	int getValue(void) { return value; };

protected:

	int value;

};


#endif