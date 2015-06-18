#include "../TestRunner/catch.hpp"
#include "../../Source/Game/Game.h"


SCENARIO("Testing Games")
{
	GIVEN("An input of two High Cards")
	{
		Result result = Game().Play("Black: 2H 3D 5S 9C KD  White: 2C 3H 4S 8C AH");
		CHECK(result.Winner().Color() == WHITE);
		CHECK(result.Winner().Play() == HIGH_CARD);
	}
	
	GIVEN("An input of One Pair and a High Card")
	{
		Result result = Game().Play("Black: 2H 3D 5S 9C 2D  White: 2C 3H 4S 8C AH");
		CHECK(result.Winner().Color() == BLACK);
		CHECK(result.Winner().Play() == ONE_PAIR);
	}
}
