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
	int Value;
	Suit Suit;


public:

	Card(int Value, ::Suit Suit);

	int GetValue();

	::Suit GetSuit();
};
