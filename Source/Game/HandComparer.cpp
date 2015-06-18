#include "HandComparer.h"
#include "../Hand/Hand.h"


Hand HandComparer::compare(Hand blackHand, Hand whiteHand)
{
	if (blackHand.Play() > whiteHand.Play()) return blackHand;
	if (blackHand.Play() < whiteHand.Play()) return whiteHand;
	return GetHandWithHighestValue(blackHand, whiteHand);
}


Hand HandComparer::GetHandWithHighestValue(Hand blackHand, Hand whiteHand)
{
	for (int i = 4; i >= 0; --i)
	{
		if (blackHand.GetCards()[i].Value() > whiteHand.GetCards()[i].Value()) return blackHand;
		if (blackHand.GetCards()[i].Value() < whiteHand.GetCards()[i].Value()) return whiteHand;
	}

	return blackHand;
}
