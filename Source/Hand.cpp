#include "Hand.h"


Hand::Hand(::Color Color, std::vector<Card> Cards)
{
	this->Color = Color;
	this->Cards = Cards;
}

::Color Hand::GetColor() const
{
	return Color;
}

std::vector<Card> Hand::GetCards()
{
	return Cards;
}