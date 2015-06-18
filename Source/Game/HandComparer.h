#pragma once

class Hand;


class HandComparer
{
	static Hand GetHandWithHighestValue(Hand blackHand, Hand whiteHand);

public:

	static Hand compare(Hand blackHand, Hand whiteHand);
};
