#include "Card.h"


Card::Card(int value, ::Suit suit): value(value), suit(suit) {}


bool operator<(const Card& first, const Card& second)
{
	return first.value < second.value;
}


int Card::Value()
{
	return value;
}


Suit Card::Suit()
{
	return suit;
}
