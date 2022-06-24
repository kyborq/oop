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
