#ifndef DIGITCHECKER_H
#define DIGITCHECKER_H

#include <string>
#include <iostream>

#define NOT_STARTED (-1)
#define SUBS_NUMBER (11)
#define MODULE_NUMBER (11)
#define START ("**************Digito Verificador Iniciado**************\n")
#define ORIGINAL_VALUE ("Valor original: ")
#define SWAP_OPERATION ("Inversion de numero: ")
#define SEQ_MULTIPLY_OPER ("Multiplicacion secuencial de digitos: ")
#define FINAL_OPER ("Modulo y Resta\n*******Si el resultado es 11 se mostrara un 0*******\n*******Si el resultado es 10 se mostrara un 1*******\n\nRESULTADO ->  ")
#define FAST_DIGIT ("Calculo Rapido - Digito verificador: ")
#define VALUE1 (11)
#define RESULT1 (0)
#define VALUE2 (10)
#define RESULT2 (1)
#define ASCII_TO_INT(x) ((x)-48)

class DigitChecker
{
public:
	//Constructor y destructor
	DigitChecker(unsigned long long int Value, bool ShowMessage = true);
	DigitChecker(const char * Value, bool ShowMessage = true);
	~DigitChecker() {};

	//Getters
	unsigned int GetResult(void) { return Result; }
	unsigned long long int	GetSequentialMultiplyValue(void) { return SequentialMultiplyValue; }
	std::string GetOriginalValue(void) { Operation = ORIGINAL_VALUE; return OriginalValue; }
	std::string GetSwapValue(void) { return SwappedValue; }
	std::string GetOperation(void) { return Operation; }

	//Setters
	void SetFinalValue(unsigned int Result) { this->Result = Result; }
	void SetSequentialMultiplyValue (unsigned long long int SequentialMultiplyValue) { this->SequentialMultiplyValue = SequentialMultiplyValue; }
	void SetOriginalValue(std::string OriginalValue) { this->OriginalValue = OriginalValue; }
	void SetSwapValue(std::string SwappedValue) { this->SwappedValue = SwappedValue; }
	void SetOperation(std::string Operation) { this->Operation = Operation; }

	//Metodos
	std::string SwapValue(void);
	unsigned long long int  SequentialMultiply(int StartValue, int FinishValue);
	unsigned int OperateValue(void);

	unsigned int CalculateDigit(int StartValue, int FinishValue);

private:

	unsigned int Result;
	unsigned long long int SequentialMultiplyValue;
	std::string OriginalValue;
	std::string SwappedValue;
	std::string Operation;

};

#endif
