#include "../TestRunner/catch.hpp"
#include "../../Source/Game/Game.h"


TEST_CASE("Testing Games")
{
	SECTION("Game with two High Cards")
	{
		Result Result = Game::Play("Black: 2H 3D 5S 9C KD  White: 2C 3H 4S 8C AH");
		CHECK(Result.Output() == "White wins. - with high card: Ace");
	}
}
