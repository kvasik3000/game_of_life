#include "View.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
#include"Life.h"
#include <conio.h>
#include <iomanip>

View::View(int a, int b, Rule* rule)
{
	this->life = new Life(a, b, rule);
}

View::~View()
{
	delete life;
}

void View::print_life()
{
	//
	//std::cout << name << std::endl;
	std::string name = "Game Of Life\n";
	std::string buffer = "";
	for (int i = 0; i < life->get_b() + 2; i++)
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
	for (int i = 0; i < life->get_b() + 2; i++)
	{
		//std::cout << "#";
		buffer += '#';
	}
	//std::cout << std::endl;
	buffer += '\n';
	system("cls");
	std::cout << std::setw(life->get_a());
	std::cout << name << std::endl;
	std::cout <<"Чтобы запустить игру, нажмите кнопку Enter" << std::endl;
	std::cout <<"Чтобы поставить игру на паузу, так же нажмите кнопку Enter" << std::endl;
	std::cout <<"Чтобы завершить игру окончательно, нажмите кнопку Esc\n" << std::endl;
	std::cout << buffer;
}



void View::run_game()
{
	life->generate_life();
	
	print_life();
	Sleep(1000);
	int count = 0;

	while (true)
	{
		
		if (_kbhit() && _getch() == 13) {

			while (true)
			{
				life->update();
				print_life();
				Sleep(5);
				if (_kbhit() && _getch() == 13) {
					std::cout << "number of iteration:" << count << std::endl;
					break;
				}
				
				count++;
				std::cout <<"number of iteration:" << count << std::endl;

			}
		}
		
		else if (_kbhit() && _getch() == 27) {
			exit(0);
		}
	}
}
