#include"EmailsManager.h"

EmailsManager::EmailsManager()
{
}

EmailsManager::~EmailsManager()
{
}

list<Email>
EmailsManager::OrderEmails(list<Email>& EmailList, string OrderSettings)
{
	list <size_t> SettingsSeparatorPos;
	list <size_t> FlagSeparatorPos;
	list <Email> OrderedEmails;

	AdminSettings(OrderSettings, SettingsSeparatorPos, FlagSeparatorPos);

	list<size_t>::iterator it = SettingsSeparatorPos.begin();
	list<size_t>::iterator it2 = FlagSeparatorPos.begin();

	/*for (auto n : FlagSeparatorPos)
	{
		cout << n << endl;
		cout << (*it) << endl;
		cout << (*it2) << endl;
	}*/

	for (int i = 0; i <= SettingsSeparatorPos.size(); i++)
	{
		if (i == 0)
			OrderByFlag(EmailList, OrderedEmails, OrderSettings.substr(0, *it2), OrderSettings.substr((*it2) + 1, 4));
		else
			OrderByFlag(EmailList, OrderedEmails, OrderSettings.substr(*it+1, *it2 - (*it+1)), OrderSettings.substr(*it2+1, 4));


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
		pos = OrderSettings.find('|',pos);

		if (pos != string::npos)
			SettingsSeparatorPos.push_back(pos);

	} while (pos++ != string::npos);

	size_t pos1 = 0;
	do
	{
		pos1 = OrderSettings.find('-', pos1);

		if (pos1 != string::npos)
			FlagSeparatorPos.push_back(pos1);

	} while (pos1++ != string::npos);
	
}

void
EmailsManager::OrderByFlag(list<Email>& EmailList, list<Email>& OrderedEmails, string Flag, string SortingMethod)
{
	cout << Flag << endl;
	cout << SortingMethod << endl;
	list<Email> TempList;

	for (list<Email>::iterator it = EmailList.begin(); it != EmailList.end(); it++)
	{
		string mailFlags = (*it).GetFlags();

		size_t pos = Flag.find('!');

		if (pos != string::npos)
		{
			if (mailFlags.find(Flag[pos + 1]) == string::npos && !(it->IsOrdened()))
			{
				TempList.push_back(*it);
				it->SetOrder();
			}
		}
		else if (mailFlags.find(Flag) != string::npos && !(it->IsOrdened()))
		{
			TempList.push_back(*it);
			it->SetOrder();
		}
	}

	//OrderByDate(TempList, SortingMethod);

	for (Email mail : TempList)
	{
		cout << mail.GetName() << endl;
	} 

	//OrderedEmails.merge(TempList);
}

bool comp(const Email& m1, const Email& m2)
{
	return (m1.GetYear() > m2.GetYear());
}

bool CompareMonthL(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())
		return (m1.GetMonth() > m2.GetMonth());
	else
		return false;
}

bool CompareDayL(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())
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

bool CompareYearF(const Email& m1, const Email& m2)
{
	return (m1.GetYear() < m2.GetYear());
}

bool CompareMonthF(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())
		return (m1.GetMonth() < m2.GetMonth());
	else
		return false;
}

bool CompareDayF(const Email& m1, const Email& m2)
{
	if (m1.GetYear() == m2.GetYear())
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

void
EmailsManager::OrderByDate(list<Email>& EmailList, string SortingMethod)
{
	if (SortingMethod.find("LIFO") != string::npos)
	{
		EmailList.sort(comp);
		EmailList.sort(CompareMonthL);
		EmailList.sort(CompareDayL);
	}
	else if (SortingMethod.find("FIFO") != string::npos)
	{
		EmailList.sort(CompareYearF);
		EmailList.sort(CompareMonthF);
		EmailList.sort(CompareDayF);
	}
}