#pragma once

#include "../Card/Card.h"
#include <vector>


enum Color
{
	BLACK,
	WHITE
};


enum Play
{
	HIGH_CARD,
	ONE_PAIR,
	TWO_PAIR,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};


class Hand
{
	Color color;
	Play play;
	std::vector<Card> cards;

public:

	Hand(Color Color, std::vector<Card> cards);

	Color Color() const;

	Play Play();

	std::vector<Card> GetCards();
};
