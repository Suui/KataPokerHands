#pragma once

#include "Hand.h"


struct ValueAndQuantity
{
private:
	int value;
	int quantity;


public:

	ValueAndQuantity(int Value, int Quantity) : value(Value), quantity(Quantity) {}

	int Value() { return value; }

	int Quantity() { return quantity; }
};


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

	bool CheckFourOfAKind();

	ValueAndQuantity GetValueAndQuantityForTheMostRepeatedCard(int ignoredCardValue = 0);

	int GetTwoOfAKindCardValue(int ignoredCardValue = 0);

	int GetThreeOfAKindCardValue();
};
