#ifndef EMAILSMANAGER_H
#define EMAILSMANAGER_H

#include <list>
#include"EMail.h"

using namespace std;


class EmailsManager
{
public:
	EmailsManager();
	~EmailsManager();

	void OrderEmails(list<Email> EmailList, string OrderSettings);

private:

};

#endif