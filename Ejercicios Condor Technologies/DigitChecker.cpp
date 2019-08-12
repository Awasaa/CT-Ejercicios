#include "DigitChecker.h"

DigitChecker::DigitChecker(unsigned long long int Value, bool ShowMessage)
{
	OriginalValue = SwappedValue = std::to_string(Value);
	SequentialMultiplyValue = 0;
	Result = NOT_STARTED;
	Operation = START;

	if (ShowMessage)
	{
		std::cout << Operation << std::endl;
	}
}

DigitChecker::DigitChecker(const char* Value, bool ShowMessage)
{
	OriginalValue = SwappedValue = Value;
	SequentialMultiplyValue = 0;
	Result = NOT_STARTED;
	Operation = START;

	if (ShowMessage)
	{
		std::cout << Operation << std::endl;
	}
}

std::string
DigitChecker::SwapValue(void)
{
	std::string::iterator it1 = OriginalValue.begin();
	std::string::iterator it2 = OriginalValue.end();
	unsigned int i = 0;

	while (it1 != (OriginalValue.end()))
	{
		SwappedValue[i] = *(--it2);
		it1++;
		i++;
	}

	Operation = SWAP_OPERATION;

	return SwappedValue;
}

unsigned long long int
DigitChecker::SequentialMultiply(int StartMult, int FinishMult)
{
	std::string::iterator it1 = SwappedValue.begin();
	int tempMult = StartMult;
	int i = 0;
	SequentialMultiplyValue = 0;

	while (it1 != SwappedValue.end())
	{
		SequentialMultiplyValue += (ASCII_TO_INT(SwappedValue[i])) * tempMult;

		///std::cout << "sequential " << tempMult << " " << ASCII_TO_INT(SwappedValue[i]) << " "<< std::endl;

		if (tempMult == FinishMult)
		{
			tempMult = StartMult;
		}		
		else
		{
			tempMult++;
		}
			
		i++;
		it1++;
	}

	Operation = SEQ_MULTIPLY_OPER;

	return SequentialMultiplyValue;
}

unsigned int
DigitChecker::OperateValue(void)
{
	int tempResult = (SequentialMultiplyValue % MODULE_NUMBER);
	tempResult = SUBS_NUMBER - tempResult;

	if (tempResult == VALUE1)
	{
		Result = RESULT1;
	}
	else if (tempResult == VALUE2)
	{
		Result = RESULT2;
	}
	else
	{
		Result = tempResult;
	}

	Operation = FINAL_OPER;

	return Result;
}

unsigned int
DigitChecker::CalculateDigit(int StartValue, int FinishValue)
{
	GetOriginalValue();
	SwapValue();
	SequentialMultiply(StartValue, FinishValue);
	OperateValue();

	Operation = FAST_DIGIT;

	return Result;
}