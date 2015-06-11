#include "PlayParser.h"


Play PlayParser::Parse(std::vector<Card> Cards)
{
	if (CheckHighCard(Cards)) return HIGH_CARD;
}


bool PlayParser::CheckHighCard(std::vector<Card> Cards)
{
	for (unsigned int i = 0; i < Cards.size(); ++i)
	{
		auto Compared = Cards.at(i);
		for (unsigned int j = 0; j < Cards.size(); ++j)
		{
			if (j == i) continue;
			if (Cards.at(j).GetValue() == Compared.GetValue()) return false;
		}
	}
	return true;
}