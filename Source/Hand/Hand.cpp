#include "Hand.h"
#include "../Card/Card.h"
#include "PlayParser.h"


Hand::Hand(::Color Color, std::vector<Card> cards)
{
	this->color = Color;
	this->cards = cards;
	this->play = PlayParser::Parse(cards);
}


Color Hand::Color() const
{
	return color;
}


Play Hand::Play()
{
	return play;
}


std::vector<Card> Hand::GetCards()
{
	return cards;
}
