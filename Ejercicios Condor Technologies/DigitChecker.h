#ifndef DIGITCHECKER_H
#define DIGITCHECKER_H

//******************INCLUDES******************
#include <string>
#include <iostream>

//******************DEFINES******************
#define NOT_STARTED (-1)  //Valor para detectar un dato no escrito correctamente
#define SUBS_NUMBER (11)	// result = SUBS_NUMBER - value
#define MODULE_NUMBER (11)	//Modulo a aplicar
#define START ("**************Digito Verificador Iniciado**************\n")
#define ORIGINAL_VALUE ("Valor original: ")
#define SWAP_OPERATION ("Inversion de numero: ")
#define SEQ_MULTIPLY_OPER ("Multiplicacion secuencial de digitos: ")
#define FINAL_OPER ("Modulo y Resta\n*******Si el resultado es 11 se mostrara un 0*******\n*******Si el resultado es 10 se mostrara un 1*******\n\nRESULTADO ->  ")
#define FAST_DIGIT ("Calculo Rapido - Digito verificador: ")
#define VALUE1 (11)		//Valores de interes para el..
#define RESULT1 (0)
#define VALUE2 (10)
#define RESULT2 (1)		//.. ejercicio
#define ASCII_TO_INT(x) ((x)-48) //Covierte cada ascci de un int en un int


class DigitChecker
{
public:
	//Constructor y destructor
	DigitChecker(unsigned long long int Value, bool ShowMessage = true);
	DigitChecker(const char * Value, bool ShowMessage = true);	//Sobrecarga para iniciarlo con un c-string (preferentemente para linea de comandos)
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
	unsigned int OperateValue(void);	//Realiza el modulo y la resta segun se definen "SUBS_NUMBER" y "MODULE_NUMBER"
		
	unsigned int CalculateDigit(int StartValue, int FinishValue);

private:

	//Datos miembro para aumentar la testeabilidad en cada paso
	unsigned int Result;
	unsigned long long int SequentialMultiplyValue;
	std::string OriginalValue;
	std::string SwappedValue;
	std::string Operation;

};

#endif
