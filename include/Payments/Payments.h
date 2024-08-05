#pragma once
#include <iostream>

// ---- Design Pattern -> Strategy Method
class Payments
{
	protected:
		double _TotalBill;
		double _AmountPaid;
		double _MissingToPay;
		double _TheChange;
		double _ClientPayment;

		
	public:
		Payments() : _TotalBill(0.0), _AmountPaid(0.0), _MissingToPay(0.0), _TheChange(0.0) {}
		virtual ~Payments() {}
		virtual bool DoPayment(double clientPayment, double totalbill) = 0;
		double getTotalBill() const { return _TotalBill; }
		double getAmountPaid() const { return _AmountPaid; }
		double getMissingToPay() const { return _MissingToPay; }
		double TakeYourChange() const { return _TheChange; }
		virtual void printPayment() const = 0;
		

};

