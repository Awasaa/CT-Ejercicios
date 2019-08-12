#ifndef EMAIL_H
#define EMAIL_H

#include <string>

#define EMAIL_DATA (3)

using namespace std;

class Email
{
public:
	Email(string Name, string Flags, string Data) { this->Name = Name; this->Flags = Flags; this->Date = Date; }
	~Email() {}

	string GetName(void) { return Name; }
	string GetDate(void) { return Flags; }
	string GetFlags(void) { return Date; }

	void SetName(string Name) { this->Name = Name; }
	void SetDate(string Date) { this->Date = Date; }
	void SetFlags(string Flags) { this->Flags = Flags; }

private:

	string Name;
	string Flags;
	string Date;

};

#endif 