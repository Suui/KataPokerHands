#pragma once

#include "Card.h"


class CardParser
{
public:

	static Card Parse(char Value, char Suit);

	static int ParseValue(char Value);

	static Suit ParseSuit(char Suit);
};
