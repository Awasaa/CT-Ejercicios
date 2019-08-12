#include "CashRegister.h"

int main(void)
{
	CashRegister CReg1(10,3,2,0,2,6);

	//std::cout << CReg1.GetTotalMoney() << std::endl;

	std::cout << CReg1.GetCashRegisterInfo() << std::endl;


	system("pause");

	return 0;
}