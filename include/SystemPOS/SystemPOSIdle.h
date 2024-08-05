#pragma once
#include "SystemPOS.h"


// ---- POS Started
class SystemPOSIdle : public SystemPOS
{
	public:
		SystemPOSIdle();
		~SystemPOSIdle();
		void stateSystemPOS() override;
};