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

	SECTION("Number of cards in hand equals 5")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.GetCards().size() == 5);
	}

	SECTION("Cards are parsed correcly")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		std::vector<Card> Cards = { Card(2, HEARTS),
					   Card(3, DIAMONDS),
					   Card(5, SPADES),
					   Card(9, CLUBS),
					   Card(13, DIAMONDS)};

		REQUIRE(Hand.GetCards().size() == Cards.size());
		for (unsigned int i = 0; i < Cards.size(); ++i)
		{
			CHECK(Cards.at(i).GetValue() == Hand.GetCards().at(i).GetValue());
			CHECK(Cards.at(i).GetSuit() == Hand.GetCards().at(i).GetSuit());
		}
	}
}