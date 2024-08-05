#pragma once

// ---- Design Pattern -> State Method
class SystemPOS
{
	public:
		virtual ~SystemPOS() {}
		virtual void stateSystemPOS() = 0;
};
