#include "DigitChecker.h"

//*******Ejercicio 1: Digito Verificador - Gonzalo Agustin Pintos*******
//En este ejercicio cree una clase que reune todos los metodos para obtener el digito verificador. DigitChecker tiene
//dos contructores, se puede iniciar con un long long int o un c-tring, de esta manera el objeto termina siendo mas 
//"flexible" y "abarcativo". Luego hay dos metodos de realizar las operaciones: paso a paso, llamando a cada metodo
//especifica para cada operacion, o mediante CalculateDigit(), que lo hace automaticamente. En ambos casos se deben 
//pasar como parametros la cota inferior y superior de la multiplicacion secuencial, caracteristica dada para hacer
//el objetvo mas universal y multiproposito.

int main(int argc, char *argv[])
{
	DigitChecker Checker1(201012341); //Objeto con constructor long long int
	//DigitChecker Checker1("201012341");  //Objeto con constructor c-string

	std::cout << Checker1.GetOperation() << Checker1.GetOriginalValue() << std::endl; //Muestro el valor de inicio en pantalla
	std::cout << Checker1.GetOperation() << Checker1.SwapValue() << std::endl;		  //Intercambio la posicion de dicho valor
	std::cout << Checker1.GetOperation() << Checker1.SequentialMultiply(2, 7) << std::endl;	//realizo la multiplicacion secuencial
	std::cout << Checker1.GetOperation() << Checker1.OperateValue() << std::endl;		//Le aplico el modulo, la resta y obtengo el digo verificador

	//Funcion automatizada
	//std::cout << Checker1.GetOperation() << Checker1.CalculateDigit(2,7) << std::endl;


	system("pause");

	return 0;
}