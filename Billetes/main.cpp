#include "CashRegister.h"

int main(void)
{
	CashRegister CReg1(6,9,0,40,2,3);

	std::cout << CReg1.GetCashRegisterInfo() << std::endl;

	std::cout << CReg1.MakeTransaction(517) << std::endl;

	std::cout << CReg1.GetCashRegisterInfo() << std::endl;



	system("pause");

	return 0;
}