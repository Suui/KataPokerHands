#pragma once

#include "Result.h"
#include "../Hand/Hand.h"


class Game
{
	Hand blackHand;
	Hand whiteHand;

public:

	Game();
	
	Result Play(std::string input);
};
