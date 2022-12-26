#include "Rule.h"
#include <vector>

Rule::Rule(std::vector<int>born, std::vector<int>survive)
{
	this->born = born;
	this->survive = survive;
}

Rule::Rule()
{
	std::vector<int>born = { 3 };
	std::vector<int>survive = {2,3};
	this->born = born;
	this->survive = survive;
}


Rule::~Rule()
{
}

std::vector<int> Rule::get_born()
{
	return this->born;
}
std::vector<int> Rule::get_survive()
{
	return this->survive;
}





