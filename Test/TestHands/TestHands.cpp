#include "../TestRunner/catch.hpp"

TEST_CASE("Testing Hand Input")
{
	SECTION("High Card")
	{
		Result Result = HandChecker::check("Black: 2H 3D 5S 9C KD  White: 2C 3H 4S 8C AH");
		CHECK(Result.GetOutput() == "White wins. - with high card: Ace");
	}
}