#pragma once

#include "Hand.h"


class PlayParser
{

public:

	static Play Parse(std::vector<Card> cards);
	
	static bool CheckOnePair(std::vector<Card> cards);
	
	static bool CheckTwoPair(std::vector<Card> cards);

	static bool CheckThreeOfAKind(std::vector<Card> cards);

	static int GetPairIndexFrom(int From, std::vector<Card> cards);
};
