#pragma once


const int a = 12;
const int b = 12;

class Life
{
	int life_array[a][b];
	int life_next[a][b];
	int check_rule(int k, int l);
	void print_life();
	void generate_life();


public:
	Life();
	~Life();

	void run_life();

};





