#include "PlayParser.h"


Play PlayParser::Parse(std::vector<Card> Cards)
{
	if (CheckTwoPair(Cards)) return TWO_PAIR;
	if (CheckOnePair(Cards)) return ONE_PAIR;
	if (CheckHighCard(Cards)) return HIGH_CARD;
}


bool PlayParser::CheckHighCard(std::vector<Card> Cards)
{
	return !HasPair(Cards);
}


bool PlayParser::CheckOnePair(std::vector<Card> Cards)
{
	return HasPair(Cards);
}


bool PlayParser::CheckTwoPair(std::vector<Card> Cards)
{
	return false;
}


bool PlayParser::HasPair(std::vector<Card> Cards)
{
	for (unsigned int i = 0; i < Cards.size() - 1; ++i)
	{
		auto Compared = Cards.at(i);
		for (unsigned int j = i + 1; j < Cards.size(); ++j)
			if (Cards.at(j).GetValue() == Compared.GetValue()) return true;
	}
	return false;
}