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


	friend bool operator < (const Card& first, const Card& second);

	int Value();

	Suit Suit();
};
