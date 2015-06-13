#include "../TestRunner/catch.hpp"
#include "../../Source/Hand/Hand.h"
#include "../../Source/Hand/HandBuilder.h"
#include "../../Source/Card/Card.h"


TEST_CASE("Testing Cards")
{
	SECTION("Hand color is Black")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.Color() == Color::BLACK);
	}

	SECTION("Hand color is White")
	{
		Hand Hand = HandBuilder::build("White: 2C 3H 4S 8C AH");
		CHECK(Hand.Color() == Color::WHITE);
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
			CHECK(Cards.at(i).Value() == Hand.GetCards().at(i).Value());
			CHECK(Cards.at(i).Suit() == Hand.GetCards().at(i).Suit());
		}
	}
}