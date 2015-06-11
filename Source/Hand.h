#pragma once
#include "Card.h"
#include <vector>

enum Color
{
	BLACK,
	WHITE
};


enum Play
{
	HIGH_CARD
};


class Hand
{
	Color Color;
	Play Play;
	std::vector<Card> Cards;

public:

	Hand(::Color Color, std::vector<Card> Cards);

	::Color GetColor() const;
};
