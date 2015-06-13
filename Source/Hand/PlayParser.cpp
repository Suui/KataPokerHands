#include "PlayParser.h"


Play PlayParser::Parse(std::vector<Card> cards)
{
	this->cards = cards;

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
		if (c == 3) return true;
		c = 0;
	}
	return false;
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
