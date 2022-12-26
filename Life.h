#pragma once
#define X_line 10
#define Y_line 10

const int a = X_line + 2;
const int b = Y_line + 2;

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





