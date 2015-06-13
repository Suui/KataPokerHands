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
		Hand Hand = HandBuilder::build("Black: 4H 3D 6S 2C 5D");
		CHECK(Hand.Play() == STRAIGHT);
	}

	SECTION("Flush")
	{
		Hand Hand = HandBuilder::build("Black: TH 3H KH 2H 8H");
		CHECK(Hand.Play() == FLUSH);
	}

	SECTION("Full House")
	{
		Hand Hand = HandBuilder::build("Black: 7H AD 7C AH 7D");
		CHECK(Hand.Play() == FULL_HOUSE);
	}

	SECTION("Four of a Kind")
	{
		Hand Hand = HandBuilder::build("Black: 7H AD 7C 7S 7D");
		CHECK(Hand.Play() == FOUR_OF_A_KIND);
	}

	SECTION("Straight Flush")
	{
		Hand Hand = HandBuilder::build("Black: TH 7H 9H 8H 6H");
		CHECK(Hand.Play() == STRAIGHT_FLUSH);
	}
}
