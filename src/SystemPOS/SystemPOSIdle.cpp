#include "SystemPOSIdle.h"
#include "SystemPOSReady.h"
#include "RuntimeStatePOS.h"
#include <iostream>

// ---- POS Started
SystemPOSIdle::SystemPOSIdle() {}

SystemPOSIdle::~SystemPOSIdle() {}

void SystemPOSIdle::stateSystemPOS()
{
	std::cout << "\n State System POS: Idle " << std::endl;
}