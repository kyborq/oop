#pragma once

#include <iostream>
#include "CTVSet.h"

class CRemoteControl
{
public:
	CRemoteControl(CTVSet &tv, std::istream &input, std::ostream &output);
	void HandleCommand();
private:
	CTVSet &m_tv;
	std::istream& m_input;
	std::ostream& m_output;

	void TurnOn();
	void TurnOff();
	void SelectChannel(std::string& command);
	void GetInfo();

	int GetNumber(std::string& command);
};

