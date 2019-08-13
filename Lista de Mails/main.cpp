#include "EmailsManager.h"


int main(void)
{
	list <Email> EmailList;

	Email m1("MailA", "A B", "01/02/15");
	Email m2("MailB", "A", "05/03/15");
	Email m3("MailC", "B", "06/04/15");
	Email m4("MailD", "A B", "08/09/15");
	Email m5("MailE", "C", "07/11/15");
	Email m6("MailF", "A C", "03/12/15");

	//cout << m1.GetName() << m1.GetFlags() << m1.GetDate() << endl;
	//cout << m2.GetName() << m2.GetFlags() << m2.GetDate() << endl;
	cout << m6.GetName() << m6.GetFlags() << m6.GetDay() << m6.GetMonth() << m6.GetYear() <<endl;


	EmailList.push_back(m1);
	EmailList.push_back(m2);
	EmailList.push_back(m3);
	EmailList.push_back(m4);
	EmailList.push_back(m5);
	EmailList.push_back(m6);

	EmailsManager EmailMang;
	string OrderSettings = "B-FIFO|!C-LIFO|C-FIFO";

	EmailList = EmailMang.OrderEmails(EmailList, OrderSettings);
	

	system("pause");

	return 0;
}

