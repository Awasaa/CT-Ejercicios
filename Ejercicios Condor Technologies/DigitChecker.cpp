#include "DigitChecker.h"

DigitChecker::DigitChecker(unsigned long long int Value, bool ShowMessage)
{
	OriginalValue = SwappedValue = std::to_string(Value);	//Convierto el valor a un string
	SequentialMultiplyValue = 0;
	Result = NOT_STARTED;	//Valor para identificar que el resultado no ha sido calculado
	Operation = START;		//Mensaje para el usuario

	if (ShowMessage)	//Condicional para mostrar el mensaje
	{
		std::cout << Operation << std::endl;
	}
}

DigitChecker::DigitChecker(const char* Value, bool ShowMessage)
{
	OriginalValue = SwappedValue = Value;
	SequentialMultiplyValue = 0;
	Result = NOT_STARTED;	//Valor para identificar que el resultado no ha sido calculado
	Operation = START;	//Mensaje para el usuario

	if (ShowMessage)	//Condicional para mostrar el mensaje
	{
		std::cout << Operation << std::endl;
	}
}

std::string
DigitChecker::SwapValue(void)
{
	std::string::iterator it1 = OriginalValue.begin();	//Creo los iteradores y los posiciones en las puntas
	std::string::iterator it2 = OriginalValue.end();	//opuestas del mismo string
	unsigned int i = 0;

	while (it1 != (OriginalValue.end()))
	{
		SwappedValue[i] = *(--it2);	//Disminuyo it2 ya que .end(devuelve un iterador al siguiente elemento del ultimo "past-end iterator")
		it1++;
		i++;
	}

	Operation = SWAP_OPERATION;	//Mensaje para el usuario

	return SwappedValue;
}

unsigned long long int
DigitChecker::SequentialMultiply(int StartMult, int FinishMult)
{
	std::string::iterator it1 = SwappedValue.begin();	//iterador en la primera posicion de la string swapeada
	int tempMult = StartMult;	//Valor inicual de la multiplicacion secuencial
	int i = 0;
	SequentialMultiplyValue = 0;

	while (it1 != SwappedValue.end())
	{
		SequentialMultiplyValue += (ASCII_TO_INT(SwappedValue[i])) * tempMult;	//Convierto el valor de la string en un int y lo multiplico por
																				//el valor secuencial correspondiente

		if (tempMult == FinishMult)	//si llegue al ultimo multiplicador secuencial, reseteo los mulplicadores
		{
			tempMult = StartMult;
		}		
		else	//Caso contrario, aumento el multiplicador
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
	int tempResult = (SequentialMultiplyValue % MODULE_NUMBER);	//Le aplico el modulo
	tempResult = SUBS_NUMBER - tempResult;		//Le aplico la resta

	if (tempResult == VALUE1)		//Condiciones del ejercicio
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
	//Metodo automatico para resolver el digito verificador

	GetOriginalValue();
	SwapValue();
	SequentialMultiply(StartValue, FinishValue);
	OperateValue();

	Operation = FAST_DIGIT;

	return Result;
}