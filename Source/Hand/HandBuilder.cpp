#include "HandBuilder.h"
#include "Hand.h"
#include "../Card/CardParser.h"


Hand HandBuilder::build(std::string input)
{
	auto cards = std::vector<Card>();

	for (unsigned int i = 7; i < input.length(); ++i)
	{
		cards.push_back(CardParser::Parse(input.at(i), input.at(i + 1)));
		i += 2;
	}

	if (input.at(0) == 'B') return Hand(BLACK, cards);
	return Hand(WHITE, cards);
}
