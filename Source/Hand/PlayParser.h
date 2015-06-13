﻿#pragma once

#include "Hand.h"


class PlayParser
{
	std::vector<Card> cards;


public:

	Play Parse(std::vector<Card> cards);

	bool CheckOnePair();

	bool CheckTwoPair();

	bool CheckThreeOfAKind();

	int GetPairIndexFrom(int From);
};
