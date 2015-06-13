#include "../TestRunner/catch.hpp"
#include "../../Source/Hand/Hand.h"
#include "../../Source/Hand/HandBuilder.h"


TEST_CASE("Testing Hands")
{
	SECTION("High Card")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.Play() == HIGH_CARD);
	}

	SECTION("One Pair")
	{
		Hand Hand = HandBuilder::build("Black: 2H 2D 5S 9C KD");
		CHECK(Hand.Play() == ONE_PAIR);
	}

	SECTION("Two Pair")
	{
		Hand Hand = HandBuilder::build("Black: 2H 2D 5S 9C 5D");
		CHECK(Hand.Play() == TWO_PAIR);
	}

	SECTION("Three Of Kind")
	{
		Hand Hand = HandBuilder::build("Black: 2H 2D 5S 9C 2D");
		CHECK(Hand.Play() == THREE_OF_A_KIND);
	}

	SECTION("Straight")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 4S 5C 6D");
		CHECK(Hand.Play() == STRAIGHT);
	}
}