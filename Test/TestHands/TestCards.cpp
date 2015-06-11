#include "../TestRunner/catch.hpp"
#include "../../Source/HandBuilder.h"
#include "../../Source/Hand.h"

TEST_CASE("Testing Cards")
{
	SECTION("Hand Color")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.GetColor() == Color::BLACK);
	}
}