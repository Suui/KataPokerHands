#include "../TestRunner/catch.hpp"
#include "../../Source/Game/Game.h"


SCENARIO("Testing Games")
{
	GIVEN("An input of two Highest Cards")
	{
		Result result = Game().Play("Black: 2H 3D 5S 9C KD  White: 2C 3H 4S 8C AH");
		CHECK(result.Winner().Color() == WHITE);
		CHECK(result.Winner().Play() == HIGH_CARD);
	}
	
}
