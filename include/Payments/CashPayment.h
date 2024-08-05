#pragma once
#include "Payments.h"

class CashPayment : public Payments
{
	public:
		CashPayment() {};
		~CashPayment();
		bool DoPayment(double clientPayment, double totalbill) override;
		void printPayment() const override;

};
