#include "DigitChecker.h"

int main(int argc, char *argv[])
{
	DigitChecker Checker1(201012341);
	//DigitChecker Checker1("201012341");

	std::cout << Checker1.GetOperation() << Checker1.GetOriginalValue() << std::endl;
	std::cout << Checker1.GetOperation() << Checker1.SwapValue() << std::endl;
	std::cout << Checker1.GetOperation() << Checker1.SequentialMultiply(2, 7) << std::endl;
	std::cout << Checker1.GetOperation() << Checker1.OperateValue() << std::endl;

	//std::cout << Checker1.GetOperation() << Checker1.CalculateDigit(2,7) << std::endl;


	system("pause");

	return 0;
}