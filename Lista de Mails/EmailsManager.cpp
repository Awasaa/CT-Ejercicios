#include"EmailsManager.h"

static bool CompareYearL(const Email& m1, const Email& m2);			//Funciones para comparar las fechas de los Emails...
static bool CompareMonthL(const Email& m1, const Email& m2);
static bool CompareDayL(const Email& m1, const Email& m2);
static bool CompareYearF(const Email& m1, const Email& m2);
static bool CompareMonthF(const Email& m1, const Email& m2);
static bool CompareDayF(const Email& m1, const Email& m2);			//.. con list.sort()



list<Email>
EmailsManager::OrderEmails(list<Email>& EmailList, string OrderSettings)
{
	list <size_t> SettingsSeparatorPos;	//posicion de los separadores de las configuracion '|'
	list <size_t> FlagSeparatorPos;		//Posicion de los separadores de Flag y modo de ordenamiento '-'
	list <Email> OrderedEmails;

	AdminSettings(OrderSettings, SettingsSeparatorPos, FlagSeparatorPos);	//Encuentro las posiciones de '|' y '-'

	list<size_t>::iterator it = SettingsSeparatorPos.begin();	//creo los iteradores al principio de las listas
	list<size_t>::iterator it2 = FlagSeparatorPos.begin();

	for (int i = 0; i <= SettingsSeparatorPos.size(); i++)
	{
		if (i == 0)	//Si es la primera iteracion del for corto a la string desde 0
			OrderByFlag(EmailList, OrderedEmails, OrderSettings.substr(0, *it2), OrderSettings.substr((*it2) + 1, 4));
		else       //Sino, desde la posicion del ultimo separador de opcion (*it+1)
			OrderByFlag(EmailList, OrderedEmails, OrderSettings.substr(*it+1, *it2 - (*it+1)), OrderSettings.substr(*it2+1, 4));

		//Condicionles para verificar si estoy en el final de un string (es ese caso no aumento dicho iterador)
		if (it != --SettingsSeparatorPos.end() && i > 0)
			it++;
		if (it2 != --FlagSeparatorPos.end())
			it2++;
	}

	EmailList = OrderedEmails;

	return EmailList;	
}


void
EmailsManager::AdminSettings(string OrderSettings, list <size_t>& SettingsSeparatorPos, list <size_t>& FlagSeparatorPos)
{
	size_t pos = 0;
	do
	{
		pos = OrderSettings.find('|',pos);	//busco el caraceter '|'

		if (pos != string::npos)	//Si lo encuentro entonces pongo su valor en la lista
			SettingsSeparatorPos.push_back(pos);

	} while (pos++ != string::npos);

	size_t pos1 = 0;
	do
	{
		pos1 = OrderSettings.find('-', pos1);	//busco la posicion de '-'

		if (pos1 != string::npos)	//si lo encuentro pongo la posicion en la lista correspondiente
			FlagSeparatorPos.push_back(pos1);

	} while (pos1++ != string::npos);
	
}

void
EmailsManager::OrderByFlag(list<Email>& EmailList, list<Email>& OrderedEmails, string Flag, string SortingMethod)
{
	list<Email> TempList;	//Lista temporal

	for (list<Email>::iterator it = EmailList.begin(); it != EmailList.end(); it++)
	{
		string mailFlags = (*it).GetFlags();	//Obtengo los flags del Email

		size_t pos = Flag.find('!');	//Si contiene '!' busco por ausencia de caracter en el flag

		if (pos != string::npos)
		{
			if (mailFlags.find(Flag[pos + 1]) == string::npos && !(it->IsOrdened())) //Abro el Email siempre y cuando no este marcado como abierto
			{
				TempList.push_back(*it);
				it->SetOrder();
			}
		}
		else if (mailFlags.find(Flag) != string::npos && !(it->IsOrdened())) //Busco por coincidencia con el flag siempre y cuando no este marcado como abierto
		{
			TempList.push_back(*it);
			it->SetOrder();
		}
	}

	OrderByDate(TempList, SortingMethod);	//Ordeno la lista temporal con los flags por fecha segun su metodo de ordenamiento

	OrderedEmails.insert(OrderedEmails.end(),TempList.begin(),TempList.end());	//Creo la lista definitiva
}

void
EmailsManager::OrderByDate(list<Email>& EmailList, string SortingMethod)
{
	if (SortingMethod.find("LIFO") != string::npos)		//Ordenamiento LIFO
	{
		EmailList.sort(CompareYearL);		//Lo ordeno por año
		EmailList.sort(CompareMonthL);		//Lo ordeno por mes
		EmailList.sort(CompareDayL);		//Lo ordeno por dia
	}
	else if (SortingMethod.find("FIFO") != string::npos)	//Ordenamiento FIFO
	{
		EmailList.sort(CompareYearF);		//Lo ordeno por año
		EmailList.sort(CompareMonthF);		//Lo ordeno por mes
		EmailList.sort(CompareDayF);		//Lo ordeno por dia
	}
}



static bool CompareYearL(const Email& m1, const Email& m2)
{
	return (m1.GetYear() > m2.GetYear());
}

static bool CompareMonthL(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())	//Me aseguro que el año sea igual para no cambiar la posicion relativa
		return (m1.GetMonth() > m2.GetMonth());
	else
		return false;
}

static bool CompareDayL(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear()) //Me aseguro que el año y el mes sean iguales para no cambiar la posicion relativa
	{
		if (m1.GetMonth() == m2.GetMonth())
		{
			return (m1.GetDay() > m2.GetDay());
		}
		else
			return false;
	}
	else
		return false;
}

static bool CompareYearF(const Email& m1, const Email& m2)
{
	return (m1.GetYear() < m2.GetYear());
}

static bool CompareMonthF(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())	//Me aseguro que el año sea igual para no cambiar la posicion relativa
		return (m1.GetMonth() < m2.GetMonth());
	else
		return false;
}

static bool CompareDayF(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())	//Me aseguro que el año y el mes sean iguales para no cambiar la posicion relativa
	{
		if (m1.GetMonth() == m2.GetMonth())
		{
			return (m1.GetDay() < m2.GetDay());
		}
		else
			return false;
	}
	else
		return false;
}
