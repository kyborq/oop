#include "CTVSet.h"

const int MAX_CHANNELS = 99;
const int MIN_CHANNELS = 1;

CTVSet::CTVSet()
{
}

bool CTVSet::IsTurnedOn()
{
	return m_isTurnedOn;
}

int CTVSet::GetCurrentChannel()
{
	return m_isTurnedOn ? m_channelNumber : 0;
}

void CTVSet::SelectChannel(int channelNumber)
{
	if (m_isTurnedOn && (channelNumber >= MIN_CHANNELS) && (channelNumber <= MAX_CHANNELS))
	{
		m_channelNumber = channelNumber;
	}
}

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
	if (m_channelNumber == 0)
	{
		m_channelNumber = 1;
	}
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
}