#include <string>
#include <sstream>
#include "CRemoteControl.h"

const std::string COMMAND_TURN_ON = "TurnOn";
const std::string COMMAND_TURN_OFF = "TurnOff";
const std::string COMMAND_INFO = "Info";
const std::string COMMAND_SELECT_CHANNEL = "SelectChannel";

CRemoteControl::CRemoteControl(CTVSet& tv, std::istream& input, std::ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
{
}

void CRemoteControl::HandleCommand()
{
	std::string command;
	getline(m_input, command);

	if (command == COMMAND_TURN_ON)
	{
		TurnOn();
		return;
	}
	if (command == COMMAND_TURN_OFF)
	{
		TurnOff();
		return;
	}
	if (command == COMMAND_INFO)
	{
		GetInfo();
		return;
	}
	if (command.find(COMMAND_SELECT_CHANNEL) != std::string::npos)
	{
		SelectChannel(command);
		return;
	}
}

void CRemoteControl::TurnOn()
{
	m_tv.TurnOn();
	m_output << "TV is on" << std::endl;
}

void CRemoteControl::TurnOff()
{
	m_tv.TurnOff();
	m_output << "TV is off" << std::endl;
}

void CRemoteControl::SelectChannel(std::string& command)
{
	int channelNumber = GetNumber(command);

	if (channelNumber == -1)
	{
		m_output << "Channel number contains invalid characters" << std::endl;
		return;
	}

	if (!m_tv.IsTurnedOn())
	{
		m_output << "TV is off" << std::endl;
		return;
	}

	m_tv.SelectChannel(channelNumber);
	m_output << "Channel number is " << m_tv.GetCurrentChannel() << std::endl;
}

void CRemoteControl::GetInfo()
{
	if (m_tv.IsTurnedOn())
	{
		m_output << "TV is on" << std::endl 
			<< "Channel number is " << m_tv.GetCurrentChannel() << std::endl;
	}
	else
	{
		m_output << "TV is off" << std::endl;
	}
}

int CRemoteControl::GetNumber(std::string& command)
{
	int channel = 0;

	std::string digits = "0123456789";
	for (int i = command.find(" ") + 1; i < command.length(); i++)
	{
		if ((command[i] < '0') || (command[i] > '9'))
		{
			return -1;
		}
		channel = static_cast<unsigned long long>(channel) * 10 + digits.find(command[i]);
	}

	return channel;
}
