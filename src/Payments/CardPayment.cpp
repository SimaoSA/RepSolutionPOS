#include "CardPayment.h"


CardPayment::~CardPayment() {}

bool CardPayment::DoPayment(double clientPayment, double totalbill) 
{
	_TotalBill = totalbill;
	_ClientPayment = clientPayment;
	_TheChange = clientPayment - _TotalBill;
	if (_TheChange >= 0)
	{
		_AmountPaid = _TotalBill;
		return true;
	}
	else
	{
		_MissingToPay = _TheChange * (-1);
		_AmountPaid = clientPayment;
	}
	return false;
}


void CardPayment::printPayment() const
{
	std::cout << "Received: " << _ClientPayment << "  -> Card Payment : " << _AmountPaid << std::endl;
}

