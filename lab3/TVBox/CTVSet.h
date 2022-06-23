#pragma once
class CTVSet
{
public:
	CTVSet();

	bool IsTurnedOn();
	int GetCurrentChannel();

	void SelectChannel(int);
	void TurnOn();
	void TurnOff();
private:
	bool m_isTurnedOn = false;
	int m_channelNumber = 0;
};
