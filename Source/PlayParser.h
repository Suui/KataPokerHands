#pragma once
#include "Hand.h"

class PlayParser
{

public:

	static Play Parse(std::vector<Card> Cards);
	
	static bool CheckHighCard(std::vector<Card> Cards);
};
