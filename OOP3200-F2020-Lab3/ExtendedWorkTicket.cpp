

#include "ExtendedWorkTicket.h"

bool ExtendedWorkTicket::getOpenValue() const
{
	return m_isOpen;
}

ExtendedWorkTicket::ExtendedWorkTicket()
{ /*
	GetTicketNumber();
	GetClientId();
	GetDate();
	GetDescription();*/
	SetTicketNumber(0);
	SetClientId("");
	SetDate(1 ,1, 2000);
	SetDescription("");

	m_isOpen = true;
}

ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const string& client_id, const int month, const int day,
	const int year, const string& description, bool isOpen)
{
	SetTicketNumber(ticket_number);
	SetClientId(client_id);
	SetDate(day, month, year);
	SetDescription(description);
	m_isOpen = isOpen;
}

//bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const string& client_id, const int month, const int day,
//	const int year, const string& description, bool isOpen)
//{
//}


bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, bool isOpen)
{

	WorkTicket ticket12;

	ticket12.SetWorkTicket(ticket_number, client_id, month, day, year, description);
	bool valid = true;
	// check numeric parameters
	if (ticket_number < 0 || year < 2000 || year > 2099)
		valid = false;
	// check string parameters     
	else if (client_id.length() < 1 || description.length() < 1)
		valid = false;
	else
	{
		try
		{
		//	 sets the date (may throw an exception even if rules are met)
			ticket12.SetTicketNumber(ticket_number);
			ticket12.SetDate(day, month, year);
			ticket12.SetClientId(client_id);
			ticket12.SetDescription(description);

		}
		catch (exception)
		{
			valid = false;
		}

	}
	return  valid;
}

void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();

	cout << "Ticket: " << getOpenValue();

}

void ExtendedWorkTicket::CloseTicket()
{
	m_isOpen = false;
}

ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
	out << (WorkTicket)ticket;
	out << "Ticket is ";

	return  out;
}
