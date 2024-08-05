#pragma once
#include <iostream>
#include <memory>
#include "Payments.h"
#include "CardPayment.h"
#include "CashPayment.h"
#include "MBWAYPayment.h"

class ClientPayment
{

	private:
		std::unique_ptr<Payments> _Payment;
	 
	 
	public:
		ClientPayment() {}
		ClientPayment(std::unique_ptr<Payments> payment);
		~ClientPayment() {}
		
		void SelectMethodePayment(std::unique_ptr<Payments> payment);
		bool ProcessPayment(double clientPayment, double totalbill);
		double getTotalBill() const { return _Payment->getTotalBill(); }
		double getAmountPaid() const { return _Payment->getAmountPaid(); }
		double getMissingToPay() const { return _Payment->getMissingToPay(); }
		double TakeYourChange() const { return _Payment->TakeYourChange(); }
		void printPayment() const { return _Payment->printPayment(); }

		ClientPayment(ClientPayment&&) noexcept = default;
		ClientPayment& operator=(ClientPayment&&) noexcept = default;
};
