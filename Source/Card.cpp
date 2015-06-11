#include "Card.h"


Card::Card(int Value, ::Suit Suit): Value(Value), Suit(Suit) {}


int Card::GetValue()
{
	return Value;
}


Suit Card::GetSuit()
{
	return Suit;
}
