#include "InputParser.h"


void InputParser::RetreiveHandInputs(std::string input, std::string& firstHand, std::string& secondHand)
{
	int initialPos = input.find_first_of('B');
	firstHand = input.substr(initialPos, initialPos + 21);

	initialPos = input.find('W');
	secondHand = input.substr(initialPos, initialPos + 21);
}
