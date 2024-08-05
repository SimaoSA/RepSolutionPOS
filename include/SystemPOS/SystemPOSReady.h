#pragma once
#include "SystemPOS.h"


// ---- POS Ready
class SystemPOSReady : public SystemPOS
{
	public:
		SystemPOSReady();
		~SystemPOSReady();
		void stateSystemPOS() override;	
};