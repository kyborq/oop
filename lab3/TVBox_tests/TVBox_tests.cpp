#define CATCH_CONFIG_MAIN
#include "../../catch/catch.hpp"

#include <iostream>
#include "../TVBox/CTVSet.h"

using namespace std;

SCENARIO("Create TV")
{
	CTVSet tv;
	
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetCurrentChannel() == 0);
}

SCENARIO("First turn on TV")
{
	CTVSet tv;	
	tv.TurnOn();

	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.GetCurrentChannel() == 1);
}

SCENARIO("First turn off TV")
{
	CTVSet tv;
	tv.TurnOn();
	tv.TurnOff();

	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetCurrentChannel() == 0);
}

SCENARIO("Select channel with TV off")
{
	CTVSet tv;
	tv.SelectChannel(15);

	CHECK(tv.GetCurrentChannel() == 0);
}

SCENARIO("Select channel with TV on")
{
	CTVSet tv;
	tv.TurnOn();

	tv.SelectChannel(2);
	CHECK(tv.GetCurrentChannel() == 2);
	
	tv.SelectChannel(15);
	CHECK(tv.GetCurrentChannel() == 15);

	tv.SelectChannel(142);
	CHECK(tv.GetCurrentChannel() == 15);

	tv.SelectChannel(0);
	CHECK(tv.GetCurrentChannel() == 15);
}

SCENARIO("Get channel number")
{
	CTVSet tv;

	tv.TurnOn();
	tv.SelectChannel(78);
	CHECK(tv.GetCurrentChannel() == 78);

	tv.TurnOff();
	CHECK(tv.GetCurrentChannel() == 0);

	tv.TurnOn();
	CHECK(tv.GetCurrentChannel() == 78);
}