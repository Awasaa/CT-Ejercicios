#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <string>
#include <vector>
#include <iostream>

#include "Billete1.h"
#include "Billete5.h"
#include "Billete10.h"
#include "Billete20.h"
#include "Billete50.h"
#include "Billete100.h"

#define TOTAL_CLASSES_OF_BILLETS (6)


class CashRegister
{
public:
	CashRegister(int p1Amount, int p5Amount, int p10Amount, int p20Amount, int p50Amount, int p100Amount);
	~CashRegister() {}

	std::string GetCashRegisterInfo(void);
	std::string GetEachBilletAmount(void);
	int			GetTotalMoney(void);

	std::string MakeTransaction(int Value);

	

private:

	std::vector<Billete1> p1;
	std::vector<Billete5> p5;
	std::vector<Billete10> p10;
	std::vector<Billete20> p20;
	std::vector<Billete50> p50;
	std::vector<Billete100> p100;


	int LastPayment;
	int TotalMoney;
	std::string CashRegisterInfo;
	std::string LastPaymentInfo;
};


#endif