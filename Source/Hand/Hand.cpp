#include "Hand.h"
#include "../Card/Card.h"
#include "PlayParser.h"


Hand::Hand(::Color Color, std::vector<Card> Cards)
{
	this->Color = Color;
	this->Cards = Cards;
	this->Play = PlayParser::Parse(Cards);
}


Color Hand::GetColor() const
{
	return Color;
}


Play Hand::GetPlay()
{
	return Play;
}


std::vector<Card> Hand::GetCards()
{
	return Cards;
}