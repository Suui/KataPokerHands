#pragma once


enum Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};


class Card
{
	int value;
	Suit suit;


public:

	Card(int value, Suit suit);

	int Value();

	Suit Suit();
};
