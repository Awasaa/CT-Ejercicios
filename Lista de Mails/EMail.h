#ifndef EMAIL_H
#define EMAIL_H

#include <string>

#define EMAIL_DATA (3)

using namespace std;

class Email
{
public:
	Email(string Name, string Flags, string Date) { this->Name = Name; 
													this->Flags = Flags; 
													Day = stoi(Date.substr(0, 2));
													Month = stoi(Date.substr(3, 2));
													Year = stoi(Date.substr(6, 2));
													Ordened = false;
												  }
	~Email() {}

	string GetName(void) { return Name; }
	int GetDay(void) const { return Day; }
	int GetMonth(void) const { return Month; }
	int GetYear(void) const { return Year; }
	string GetFlags(void) { return Flags; }
	bool IsOrdened(void) { return Ordened; }

	void SetName(string Name) { this->Name = Name; }
	void SetFlags(string Flags) { this->Flags = Flags; }
	void SetOrder(void) { Ordened = true; }
	void SetDate(string Date) {
								Day = stoi(Date.substr(0, 2));
								Month = stoi(Date.substr(3, 2));
								Year = stoi(Date.substr(6, 2));
							  }

private:

	string Name;
	string Flags;
	int Day;
	int Year;
	int Month;
	bool Ordened;

};

#endif 