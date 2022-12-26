#pragma once
#include<vector>
#include"Rule.h"

//const int a = 12;
//const int b = 12;

class Life
{
	Rule*rule;
	std::vector<std::vector<int>>life_array;
	std::vector<std::vector<int>>life_next;
	
	/*int life_array[a][b];
	int life_next[a][b];*/
	
	/*void print_life();*/
	
	int a;
	int b;

public:
	Life(int a, int b);
	Life() : Life(12, 12) {};
	~Life();
	void generate_life();
	int check_rule(int k, int l);
	/*void run_life();*/
	std::vector<std::vector<int>> get_life_array();
	std::vector<std::vector<int>> get_life_next();
	void update();
	int get_a();
	int get_b();

};





