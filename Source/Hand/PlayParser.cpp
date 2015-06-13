#include "PlayParser.h"


Play PlayParser::Parse(std::vector<Card> cards)
{
	if (CheckThreeOfAKind(cards)) return THREE_OF_A_KIND;
	if (CheckTwoPair(cards)) return TWO_PAIR;
	if (CheckOnePair(cards)) return ONE_PAIR;
	return HIGH_CARD;
}


bool PlayParser::CheckOnePair(std::vector<Card> cards)
{
	return GetPairIndexFrom(0, cards) != -1;
}


bool PlayParser::CheckTwoPair(std::vector<Card> cards)
{
	int FirstPair = GetPairIndexFrom(0, cards);
	if (FirstPair == -1) return false;
	return GetPairIndexFrom(FirstPair, cards) != -1;
}


bool PlayParser::CheckThreeOfAKind(std::vector<Card> cards)
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


int PlayParser::GetPairIndexFrom(int From, std::vector<Card> cards)
{
	for (unsigned i = From; i < cards.size() - 1; ++i)
	{
		auto Compared = cards.at(i);
		for (unsigned j = i + 1; j < cards.size(); ++j)
			if (cards.at(j).Value() == Compared.Value()) return ++i;
	}
	return -1;
}
