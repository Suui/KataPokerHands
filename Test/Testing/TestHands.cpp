#include "../TestRunner/catch.hpp"
#include "../../Source/Hand.h"
#include "../../Source/HandBuilder.h"


TEST_CASE("Testing Hands")
{
	SECTION("High Card")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.GetPlay() == HIGH_CARD);
	}

	SECTION("One Pair")
	{
		Hand Hand = HandBuilder::build("Black: 2H 2D 5S 9C KD");
		CHECK(Hand.GetPlay() == ONE_PAIR);
	}

	SECTION("Two Pair")
	{
		Hand Hand = HandBuilder::build("Black: 2H 2D 5S 9C 5D");
		CHECK(Hand.GetPlay() == TWO_PAIR);
	}
}