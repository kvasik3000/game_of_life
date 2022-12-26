#pragma once
#include<vector>

//const int a = 12;
//const int b = 12;

class Life
{
	std::vector<std::vector<int>>life_array;
	std::vector<std::vector<int>>life_next;
	
	/*int life_array[a][b];
	int life_next[a][b];*/
	int check_rule(int k, int l);
	void print_life();
	void generate_life();
	int a;
	int b;

public:
	Life(int a, int b);
	~Life();

	void run_life();

};





