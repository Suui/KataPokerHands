#pragma once

#include "Hand.h"


class PlayParser
{
	std::vector<Card> cards;


public:

	Play Parse(std::vector<Card> cards);

	bool CheckOnePair();

	bool CheckTwoPair();

	bool CheckThreeOfAKind();

	bool CheckStraight();

	bool CheckFlush();

	bool CheckFullHouse();

	int GetTwoOfAKindCardValue(int ignoredCardValue = 0);

	int GetThreeOfAKindCardValue();
};
