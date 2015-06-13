#include "PlayParser.h"
#include <algorithm>


Play PlayParser::Parse(std::vector<Card> cards)
{
	this->cards = cards;

	if (CheckFlush()) return FLUSH;
	if (CheckStraight()) return STRAIGHT;
	if (CheckThreeOfAKind()) return THREE_OF_A_KIND;
	if (CheckTwoPair()) return TWO_PAIR;
	if (CheckOnePair()) return ONE_PAIR;
	return HIGH_CARD;
}


bool PlayParser::CheckOnePair()
{
	return GetPairIndexFrom(0) != -1;
}


bool PlayParser::CheckTwoPair()
{
	int FirstPair = GetPairIndexFrom(0);
	if (FirstPair == -1) return false;
	return GetPairIndexFrom(FirstPair) != -1;
}


bool PlayParser::CheckThreeOfAKind()
{
	unsigned c = 0;
	for (unsigned i = 0; i < cards.size() - 1; ++i)
	{
		auto Compared = cards.at(i);
		for (unsigned j = i + 1; j < cards.size(); ++j)
			if (cards[j].Value() == Compared.Value()) c++;
		if (c == 2) return true;
		c = 0;
	}
	return false;
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


int PlayParser::GetPairIndexFrom(int From)
{
	for (unsigned i = From; i < cards.size() - 1; ++i)
	{
		auto Compared = cards.at(i);
		for (unsigned j = i + 1; j < cards.size(); ++j)
			if (cards.at(j).Value() == Compared.Value()) return ++i;
	}
	return -1;
}
