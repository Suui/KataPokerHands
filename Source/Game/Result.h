#pragma once

#include <string>
#include "../Hand/Hand.h"


class Result
{
	Hand winner;
	std::string output;

public:

	Result();

	Result(Hand blackHand, Hand whiteHand);

	std::string Output();

	Hand Winner() const;
};
