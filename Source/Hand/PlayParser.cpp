﻿#include "PlayParser.h"
#include <algorithm>


Play PlayParser::Parse(std::vector<Card> cards)
{
	this->cards = cards;

	if (CheckFourOfAKind())		return FOUR_OF_A_KIND;
	if (CheckFullHouse())		return FULL_HOUSE;
	if (CheckFlush())			return FLUSH;
	if (CheckStraight())		return STRAIGHT;
	if (CheckThreeOfAKind())	return THREE_OF_A_KIND;
	if (CheckTwoPair())			return TWO_PAIR;
	if (CheckOnePair())			return ONE_PAIR;
								return HIGH_CARD;
}


bool PlayParser::CheckOnePair()
{
	return GetTwoOfAKindCardValue() != -1;
}


bool PlayParser::CheckTwoPair()
{
	auto valueAndQuantity = GetValueAndQuantityForTheMostRepeatedCard();
	if (valueAndQuantity.Quantity() == 2) return GetValueAndQuantityForTheMostRepeatedCard(valueAndQuantity.Value()).Quantity() == 2;
	return false;
}


bool PlayParser::CheckThreeOfAKind()
{
	return GetValueAndQuantityForTheMostRepeatedCard().Quantity() == 3;
}


bool PlayParser::CheckStraight()
{
	sort(cards.begin(), cards.end());

	for (unsigned i = 1; i < cards.size(); ++i)
		if (cards[i].Value() - 1 != cards[i - 1].Value()) return false;

	return true;
}


bool PlayParser::CheckFlush()
{
	for (unsigned i = 1; i < cards.size(); ++i)
		if (cards[i].Suit() != cards[i - 1].Suit()) return false;

	return true;
}


bool PlayParser::CheckFullHouse()
{
	auto valueAndQuantity = GetValueAndQuantityForTheMostRepeatedCard();
	if (valueAndQuantity.Quantity() == 3) return GetValueAndQuantityForTheMostRepeatedCard(valueAndQuantity.Value()).Quantity() == 2;
	return false;
}


bool PlayParser::CheckFourOfAKind()
{
	return GetValueAndQuantityForTheMostRepeatedCard().Quantity() == 4;
}


ValueAndQuantity PlayParser::GetValueAndQuantityForTheMostRepeatedCard(int ignoredCardValue)
{
	unsigned quantity = 1, maxQuantity = 1, value = 0;
	for (unsigned i = 0; i < cards.size() - 1; ++i)
	{
		auto Compared = cards[i];
		for (unsigned j = i + 1; j < cards.size(); ++j)
			if (cards[j].Value() != ignoredCardValue && cards[j].Value() == Compared.Value()) ++quantity;
		if (quantity > maxQuantity)
		{
			value = cards[i].Value();
			maxQuantity = quantity;
		}
		quantity = 1;
	}
	return ValueAndQuantity(value, maxQuantity);
}


int PlayParser::GetTwoOfAKindCardValue(int ignoredCardValue)
{
	for (unsigned i = 0; i < cards.size() - 1; ++i)
	{
		auto Compared = cards[i];
		for (unsigned j = i + 1; j < cards.size(); ++j)
			if (cards[j].Value() != ignoredCardValue && cards[j].Value() == Compared.Value()) return Compared.Value();
	}
	return -1;
}


int PlayParser::GetThreeOfAKindCardValue()
{
	unsigned c = 0;
	for (unsigned i = 0; i < cards.size() - 1; ++i)
	{
		auto Compared = cards[i];
		for (unsigned j = i + 1; j < cards.size(); ++j)
			if (cards[j].Value() == Compared.Value()) c++;
		if (c == 2) return Compared.Value();
		c = 0;
	}
	return -1;
}
