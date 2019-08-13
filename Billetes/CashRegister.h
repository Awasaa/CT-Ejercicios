#ifndef CASHREGISTER_H
#define CASHREGISTER_H

//************************************INCLUDES************************************
#include <string>
#include <vector>
#include <iostream>

#include "Billete1.h"			//Cada billete esta representado como una clase..
#include "Billete5.h"
#include "Billete10.h"
#include "Billete20.h"
#include "Billete50.h"
#include "Billete100.h"

//************************************DEFINES************************************
#define MIN_CANT_OF_BILLETS (0)  //Cantidad minima de billetes de cada valor que quedara en la caja 
								 //(no se podran realizar transacciones con ellos)

class CashRegister
{
public:
	//Constructor y destructor
	CashRegister(int p1Amount, int p5Amount, int p10Amount, int p20Amount, int p50Amount, int p100Amount);
	~CashRegister() {}

	//Getters
	std::string GetCashRegisterInfo(void);	//Devuelve un string con toda la informacion de la caja
	std::string GetEachBilletAmount(void);	//Devuelve un string con la cantidad de billetes de cada tipo
	int			GetTotalMoney(void);		//Devuelve un int con el valor total de la caja

	//Metodo
	std::string MakeTransaction(int Value);	//Realiza un pago de valor "Value"

	

private:

	//Lista con los billetes de cada denominacion (se omitio el uso de new-delete para evitar problemas de Memory Leaks)
	std::vector<Billete1> p1;
	std::vector<Billete5> p5;
	std::vector<Billete10> p10;
	std::vector<Billete20> p20;
	std::vector<Billete50> p50;
	std::vector<Billete100> p100;

	int LastPayment; //Valor del ultimo pago
	int TotalMoney;  //valor total del dinero de la caja
	std::string CashRegisterInfo; 
	std::string LastPaymentInfo;
};


#endif