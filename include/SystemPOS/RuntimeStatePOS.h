#pragma once
#include <memory>
#include "SystemPOS.h"
#include "SystemPOSItems.h"
#include "SystemPOSIdle.h"
#include "SystemPOSReady.h"
#include "SystemPOSPayments.h"

class RuntimeStatePOS
{
	private:
		std::unique_ptr<SystemPOS> _currentStatePOS;

	public:
		RuntimeStatePOS(std::unique_ptr<SystemPOS> initialSystemPOS);
		~RuntimeStatePOS();

		void setStateSytemPOS(std::unique_ptr<SystemPOS> stateSystemPOS);
		SystemPOS& getRuntimeStatePOS() const;
};



