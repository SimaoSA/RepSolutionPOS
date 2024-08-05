#pragma once
#include "Payments.h"

class CardPayment : public Payments
{
	public:
		CardPayment() {};
		~CardPayment();
		bool DoPayment(double clientPayment, double totalbill) override;
		void printPayment() const override;

};
