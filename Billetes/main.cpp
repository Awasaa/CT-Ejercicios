#include "CashRegister.h"

//*******Ejercicio 2: Billetes - Gonzalo Agustin Pintos*******
//Para este ejercicio he creado una clase base "billete" y herede de los tipo de billetes que propone la consigna (1,5,10,etc).
//De esta manera el codigo gana escalabilidad,mantenimiento y modularizacion ya que cualquier cambio aplicable en un futuro a 
//cualquier billete no afecta a los demas ni al comportamiento del codigo. Luego cree una clase representando a la "caja registradora"
//que almacena la cantidad de billetes, informacionn del ultimo pago y su estado actual.

//1- El programa comienza creando un objeto cuyo constructor son la cantidad de billetes de cada valor ordenados ascendentemente(1,5,10,20,50,100)
//2- Luego muestra al usuario el estado actual mediante "GetCashRegisterInfo" antes y despues de realizar el pago para visualizar el cambio
//3- El metodo MakeTransaction tiene como parametro el monto de la transaccion y realiza la operacion de manera descendente (del billete de mas
//   valor al de menos valor) siempre y cuando exista la cantidad minima del respectivo billete en la caja. Este metodo podria haberse implementado
//   mediante una FSM, aunque debido a la cantidad de billetes y su aplicacion concreta a este problema opte por una opcion mas intuitiva y simple

//Aclaraciones ---> GetEachBilletAmount y GetTotalMoney son getters adicionales que pueden ser llamados autonomamente para aumentar la
//					testeabilidad del programa (igualmente son llamados por "GetCashRegisterInfo")

int main(void)
{
	CashRegister CReg1(0,0,3,0,1,2);

	std::cout << CReg1.GetCashRegisterInfo() << std::endl;	//Obtengo la informacion actual del objeto

	std::cout << CReg1.MakeTransaction(70) << std::endl;	//Realizo la transaccion (el argumento es el monto)

	std::cout << CReg1.GetCashRegisterInfo() << std::endl; //Obtengo la informacion luego de realizar la transaccion


	system("pause"); //Pausa para visualizar los datos

	return 0;
}