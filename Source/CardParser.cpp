#include "CardParser.h"


Card CardParser::Parse(char Value, char Suit)
{
	return Card(ParseValue(Value), ParseSuit(Suit));
}

int CardParser::ParseValue(char Value)
{
	if (Value == 'T') return 10;
	if (Value == 'J') return 11;
	if (Value == 'Q') return 12;
	if (Value == 'K') return 13;
	if (Value == 'A') return 14;
	return Value - '0';
}


Suit CardParser::ParseSuit(char Suit)
{
	if (Suit == 'C') return CLUBS;
	if (Suit == 'D') return DIAMONDS;
	if (Suit == 'H') return HEARTS;
	return SPADES;
}