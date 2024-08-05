#pragma once
#include "Payments.h"

class MBWAYPayment : public Payments
{
	public:
		MBWAYPayment() {};
		~MBWAYPayment();
		bool DoPayment(double clientPayment, double totalbill) override;
		void printPayment() const override;

};
