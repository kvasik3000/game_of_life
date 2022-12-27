#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
#include "Life.h"

class View
{
	Life* life;
	void print_life();
public:
	View(int a, int b, Rule* rule);
	/*View() : View(30, 40) {};*/
	~View();
	void run_game();

};

