#include "HandBuilder.h"
#include "Hand.h"
#include "../Card/CardParser.h"


Hand HandBuilder::build(std::string Input)
{
	auto Cards = std::vector<Card>();

	for (unsigned int i = 7; i < Input.length(); ++i)
	{
		Cards.push_back(CardParser::Parse(Input.at(i), Input.at(i + 1)));
		i += 2;
	}

	if (Input.at(0) == 'B') return Hand(BLACK, Cards);
	return Hand(WHITE, Cards);
}
