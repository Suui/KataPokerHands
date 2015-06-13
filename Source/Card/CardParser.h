#pragma once

#include "Card.h"


class CardParser
{
public:

	static Card Parse(char value, char suit);

	static int ParseValue(char value);

	static Suit ParseSuit(char suit);
};
