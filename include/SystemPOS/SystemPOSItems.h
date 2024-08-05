#pragma once
#include "SystemPOS.h"


// ---- POS Items
class SystemPOSItems : public SystemPOS
{
	public:
		SystemPOSItems();
		~SystemPOSItems();
		void stateSystemPOS() override;
};