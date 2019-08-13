#include "CashRegister.h"

CashRegister::CashRegister(int p1Amount,int p5Amount, int p10Amount,
						   int p20Amount, int p50Amount, int p100Amount)
{
	TotalMoney = 0;
	CashRegisterInfo.clear();
	LastPaymentInfo.clear();

	p1.resize(p1Amount);
	p5.resize(p5Amount);
	p10.resize(p10Amount);
	p20.resize(p20Amount);
	p50.resize(p50Amount);
	p100.resize(p100Amount);
}

std::string
CashRegister::GetCashRegisterInfo(void)
{
	GetEachBilletAmount();
	CashRegisterInfo +=  "\nEl monto total de la caja es: " + std::to_string(GetTotalMoney());
	return CashRegisterInfo;
}

std::string
CashRegister::GetEachBilletAmount(void)
{
	CashRegisterInfo.clear();

	CashRegisterInfo += "Cantidad de Billetes de 1: " + std::to_string(p1.size()) + '\n';
	CashRegisterInfo += "Cantidad de Billetes de 5: " + std::to_string(p5.size()) + '\n';
	CashRegisterInfo += "Cantidad de Billetes de 10: " + std::to_string(p10.size()) + '\n';
	CashRegisterInfo += "Cantidad de Billetes de 20: " + std::to_string(p20.size()) + '\n';
	CashRegisterInfo += "Cantidad de Billetes de 50: " + std::to_string(p50.size()) + '\n';
	CashRegisterInfo += "Cantidad de Billetes de 100: " + std::to_string(p100.size()) + '\n';

	return CashRegisterInfo;
}

int
CashRegister::GetTotalMoney(void)
{
	TotalMoney = 0;

	if (!p1.empty())
		TotalMoney += p1[0].getValue() * p1.size();
	if (!p5.empty())
		TotalMoney += p5[0].getValue() * p5.size();
	if (!p10.empty())
		TotalMoney += p10[0].getValue() * p10.size();
	if (!p20.empty())
		TotalMoney += p20[0].getValue() * p20.size();
	if (!p50.empty())
		TotalMoney += p50[0].getValue() * p50.size();
	if (!p100.empty())
		TotalMoney += p100[0].getValue() * p100.size();

	return TotalMoney;
}

std::string
CashRegister::MakeTransaction(int Value)
{
	LastPayment = Value;
	int  TempPayment = 0;

	while (p100.size() != 0 && TempPayment + p100[0].getValue() <= Value)
	{
		TempPayment += p100[0].getValue();
		p100.pop_back();
	}
	while (p50.size() != 0 && TempPayment + p50[0].getValue() <= Value)
	{
		TempPayment += p50[0].getValue();
		p50.pop_back();
	}
	while (p20.size() != 0 && TempPayment + p20[0].getValue() <= Value)
	{
		TempPayment += p20[0].getValue();
		p20.pop_back();
	}
	while (p10.size() != 0 && TempPayment + p10[0].getValue() <= Value)
	{
		TempPayment += p10[0].getValue();
		p10.pop_back();
	}
	while (p5.size() != 0 && TempPayment + p5[0].getValue() <= Value)
	{
		TempPayment += p5[0].getValue();
		p5.pop_back();
	}
	while (p1.size() != 0 && TempPayment + p1[0].getValue() <= Value)
	{
		TempPayment += p1[0].getValue();
		p1.pop_back();
	}

	LastPaymentInfo = "\nUltimo Valor a Pagar: " + std::to_string(LastPayment);
	LastPaymentInfo += "\nPago Realizado: " + std::to_string(TempPayment);
	if (TempPayment < LastPayment)
		LastPaymentInfo += "\nEstado: Pago menor del solicitado. Dinero insuficiente en caja\n";
	else
		LastPaymentInfo += "\nEstado: Pago realizado correctamente\n";


	return LastPaymentInfo;
}