#ifndef EMAILSMANAGER_H
#define EMAILSMANAGER_H

#include <list>
#include <iostream>
#include <cstdlib>
#include"EMail.h"

using namespace std;


class EmailsManager
{
public:
	EmailsManager();
	~EmailsManager();

	list<Email> OrderEmails(list<Email>& EmailList, string OrderSettings);

private:

	void AdminSettings(string OrderSettings, list<size_t>& SettingsSeparatorPos, list<size_t>& FlagSeparatorPos);
	void OrderByFlag(list<Email>&EmailList, list<Email>&OrderedEmails, string Flag, string SortingMethod);
	void OrderByDate(list<Email>&EmailList, string SortingMethod);
	//bool CompareYearL(const Email& m1, const Email& m2);
	//bool CompareMonthL(const Email& m1, const Email& m2);
	//bool CompareDayL(const Email& m1, const Email& m2);
	//bool CompareYearF(const Email& m1, const Email& m2);
	//bool CompareMonthF(const Email& m1, const Email& m2);
	//bool CompareDayF(const Email& m1, const Email& m2);

};

#endif