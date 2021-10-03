#pragma once

#ifndef __ExtendedWorkTicket__
#define __ExtendedWorkTicket__


#include "WorkTicket.h"

class ExtendedWorkTicket : public WorkTicket
{
private:
	bool m_isOpen;

public:
	/*bool SetIsOpen(bool isOpen);*/
	bool getOpenValue() const;

	ExtendedWorkTicket();

	ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, bool isOpen);

	bool SetWorkTicket(const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, bool isOpen);

	void ShowWorkTicket() const override;
	void CloseTicket();

	friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket);

	 
};
#endif
