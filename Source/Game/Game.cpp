#include "Game.h"
#include "InputParser.h"
#include "../Hand/HandBuilder.h"


Game::Game() {}


Result Game::Play(std::string input)
{
	std::string blackHandInput, whiteHandInput;
	InputParser::RetreiveHandInputs(input, blackHandInput, whiteHandInput);
	blackHand = HandBuilder::build(blackHandInput);
	whiteHand = HandBuilder::build(whiteHandInput);
	
	return Result(blackHand, whiteHand);
}
