#pragma once
#include <vector>

class Rule
{
	std::vector<int>born;
	std::vector<int>survive;

public:
	Rule(std::vector<int>born, std::vector<int>survive);
	Rule();
	~Rule();

};

