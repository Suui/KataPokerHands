#include "PlayParser.h"


Play PlayParser::Parse(std::vector<Card> Cards)
{
	if (CheckThreeOfAKind(Cards)) return THREE_OF_A_KIND;
	if (CheckTwoPair(Cards)) return TWO_PAIR;
	if (CheckOnePair(Cards)) return ONE_PAIR;
	if (CheckHighCard(Cards)) return HIGH_CARD;
}


bool PlayParser::CheckHighCard(std::vector<Card> Cards)
{
	return GetPairIndexFrom(0, Cards) == -1;
}


bool PlayParser::CheckOnePair(std::vector<Card> Cards)
{
	return GetPairIndexFrom(0, Cards) != -1;
}


bool PlayParser::CheckTwoPair(std::vector<Card> Cards)
{
	int FirstPair = GetPairIndexFrom(0, Cards);
	if (FirstPair == -1) return false;
	return GetPairIndexFrom(FirstPair, Cards) != -1;
}


bool PlayParser::CheckThreeOfAKind(std::vector<Card> Card)
{

}


int PlayParser::GetPairIndexFrom(int From, std::vector<Card> Cards)
{
	for (unsigned int i = From; i < Cards.size() - 1; ++i)
	{
		auto Compared = Cards.at(i);
		for (unsigned int j = i + 1; j < Cards.size(); ++j)
			if (Cards.at(j).GetValue() == Compared.GetValue()) return i;
	}
	return -1;
}