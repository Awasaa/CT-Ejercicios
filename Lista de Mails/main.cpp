#include "EmailsManager.h"

//*******Ejercicio 3: Lista de Emails - Gonzalo Agustin Pintos*******
//Para ese problema cree dos clases: Email y EmailsManager. En un comienzo creo todos los Emails con sus respectivos datos y luego creo una
//lista con dichos Emails. Luego pasan al metodo OrderEmails que recibe como parametros la lista y las configuraciones de ordenamiento.

//1- Busco las posiciones de los caracteres que demarcan las separacion entre opciones y flags y creo un lista con las posiciones de esos caracteres
//2- Luego ordeno a los mails por flag y dentro de esos flags le aplico ordenamiento por fecha
//3- Por ultimo, uno las lista temporales a la lista "Ordened mails"

//Aclaraciones --> El codigo solo funciona correctamente si los mails poseen sus flags y su fecha en el formato que se presenta en este codigo, como asi
//				   asi tambien las opciones de ordenamiento especificados en "OrderSettings". Para generar un funcionamiento optimo se tendria que
//				   aplicar un parser a los datos ya mencionados

int main(void)
{
	list <Email> EmailList;

	Email m1("MailA", "A B", "01/02/15");		//Iniciliazo los mails
	Email m2("MailB", "A", "05/03/15");
	Email m3("MailC", "B", "06/04/15");
	Email m4("MailD", "A B", "08/09/15");
	Email m5("MailE", "C", "07/11/15");
	Email m6("MailF", "A C", "03/12/15");

	EmailList.push_back(m1);		//Creo una lista con los mails inicilizados
	EmailList.push_back(m2);
	EmailList.push_back(m3);
	EmailList.push_back(m4);
	EmailList.push_back(m5);
	EmailList.push_back(m6);

	EmailsManager EmailMang;	//Creo un objeto ordenador
	string OrderSettings = "B-LIFO|!C-FIFO|C-LIFO";	//Defino las opciones de ordenamiento

	EmailList = EmailMang.OrderEmails(EmailList, OrderSettings);	//Ordeno los Emails

	cout << "*****Lista de Email Ordenadas por: " + OrderSettings + '\n' << endl;

	for (Email mail : EmailList)		//Muestro los Emails
	{
		cout <<mail.GetName() << endl;
	}
	

	system("pause");	//pausa para visualizar los resultados

	return 0;
}

