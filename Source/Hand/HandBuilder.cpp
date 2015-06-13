#include "HandBuilder.h"
#include "Hand.h"
#include "../Card/CardParser.h"


Hand HandBuilder::build(std::string input)
{
	auto Cards = std::vector<Card>();

	for (unsigned int i = 7; i < input.length(); ++i)
	{
		Cards.push_back(CardParser::Parse(input.at(i), input.at(i + 1)));
		i += 2;
	}

	if (input.at(0) == 'B') return Hand(BLACK, Cards);
	return Hand(WHITE, Cards);
}
