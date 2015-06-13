#include "Card.h"


Card::Card(int value, ::Suit suit): value(value), suit(suit) {}


int Card::Value()
{
	return value;
}


Suit Card::Suit()
{
	return suit;
}
