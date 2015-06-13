#include "CardParser.h"


Card CardParser::Parse(char Value, char Suit)
{
	return Card(ParseValue(Value), ParseSuit(Suit));
}


int CardParser::ParseValue(char value)
{
	if (value == 'T') return 10;
	if (value == 'J') return 11;
	if (value == 'Q') return 12;
	if (value == 'K') return 13;
	if (value == 'A') return 14;
	return value - '0';
}


Suit CardParser::ParseSuit(char suit)
{
	if (suit == 'C') return CLUBS;
	if (suit == 'D') return DIAMONDS;
	if (suit == 'H') return HEARTS;
	return SPADES;
}
