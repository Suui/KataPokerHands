#pragma once

#include "Hand.h"


class PlayParser
{

public:

	static Play Parse(std::vector<Card> Cards);
	
	static bool CheckOnePair(std::vector<Card> Cards);
	
	static bool CheckTwoPair(std::vector<Card> Cards);

	static bool CheckThreeOfAKind(std::vector<Card> Cards);

	static int GetPairIndexFrom(int From, std::vector<Card> Cards);
};
