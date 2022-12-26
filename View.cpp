#include "View.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
#include"Life.h"

View::View(int a, int b)
{
	this->life = new Life(a, b);
}

View::~View()
{
}

void View::print_life()
{
	std::string buffer = "";
	for (int i = 0; i < life->get_a() + 2; i++)
	{
		//std::cout << "#";
		buffer += '#';
	}
	//std::cout << std::endl;
	buffer += '\n';
	for (int k = 0; k < life->get_a(); k++) {
		//std::cout << "#";
		buffer += '#';
		for (int l = 0; l < life->get_b(); l++) {
			if (life->get_life_array()[k][l] == 1)
			{
				//std::cout << "+";
				buffer += '+';
			}
			else
			{
				//std::cout << " ";
				buffer += ' ';
			}
		}
		//std::cout << "#" << std::endl;
		buffer += "#\n";
	}
	for (int i = 0; i < life->get_a() + 2; i++)
	{
		//std::cout << "#";
		buffer += '#';
	}
	//std::cout << std::endl;
	buffer += '\n';
	system("cls");
	std::cout << buffer;
}



void View::run_game()
{
	life->generate_life();
	print_life();
	Sleep(1000);
	while (true)
	{
		life->update();
		//system("cls");
		print_life();
		Sleep(15);

	}
}
