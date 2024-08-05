
#include "RuntimeStatePOS.h"


RuntimeStatePOS::RuntimeStatePOS(std::unique_ptr<SystemPOS> initialSystemPOS) : _currentStatePOS(std::move(initialSystemPOS)) {}

RuntimeStatePOS::~RuntimeStatePOS() {}

//Methodes
void RuntimeStatePOS::setStateSytemPOS(std::unique_ptr<SystemPOS> stateSystemPOS) { _currentStatePOS = std::move(stateSystemPOS); }


SystemPOS& RuntimeStatePOS::getRuntimeStatePOS() const { return *_currentStatePOS; }
