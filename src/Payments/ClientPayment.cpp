#include "ClientPayment.h"


ClientPayment::ClientPayment(std::unique_ptr<Payments> payment) : _Payment(std::move(payment)) {}

void ClientPayment::SelectMethodePayment(std::unique_ptr<Payments> payment) { _Payment = std::move(payment); }

bool ClientPayment::ProcessPayment(double clientPayment, double totalbill)
{
	if (_Payment)
	{
		if (_Payment->DoPayment(clientPayment, totalbill)) { return true; }
    }
	return false;
}
