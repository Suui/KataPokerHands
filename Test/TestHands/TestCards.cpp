#include "../TestRunner/catch.hpp"
#include "../../Source/HandBuilder.h"
#include "../../Source/Hand.h"

TEST_CASE("Testing Cards")
{
	SECTION("Hand Color is Black")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.GetColor() == Color::BLACK);
	}

	SECTION("Hand Color is White")
	{
		Hand Hand = HandBuilder::build("White: 2C 3H 4S 8C AH");
		CHECK(Hand.GetColor() == Color::WHITE);
	}
}