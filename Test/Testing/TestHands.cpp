#include "../TestRunner/catch.hpp"
#include "../../Source/Hand.h"
#include "../../Source/HandBuilder.h"


TEST_CASE("Testing Hands")
{
	SECTION("High Card")
	{
		Hand Hand = HandBuilder::build("Black: 2H 3D 5S 9C KD");
		CHECK(Hand.GetPlay() == HIGH_CARD);
	}
}