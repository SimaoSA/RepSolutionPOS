#pragma once
#include "SystemPOS.h"
#include "Payments.h"
#include <memory>


// ---- POS Payments
class SystemPOSPayments : public SystemPOS
{
	public:
		SystemPOSPayments();
		~SystemPOSPayments();
		void stateSystemPOS() override;	
};