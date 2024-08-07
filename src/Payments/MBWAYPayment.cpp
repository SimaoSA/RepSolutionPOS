#include "MBWAYPayment.h"


MBWAYPayment::~MBWAYPayment() {}

bool MBWAYPayment::DoPayment(double clientPayment, double totalbill)
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

void MBWAYPayment::printPayment() const
{
	std::cout << "Received: " << _ClientPayment << "  -> MBWAY Payment : " << _AmountPaid << std::endl;
}


