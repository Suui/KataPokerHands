#include "Result.h"
#include "../Hand/Hand.h"
#include "HandComparer.h"


Result::Result() {}


Result::Result(Hand blackHand, Hand whiteHand)
{
	winner = HandComparer::compare(blackHand, whiteHand);
}


std::string Result::Output()
{
	return winner.Color() + " wins.";
}


Hand Result::Winner() const
{
	return winner;
}