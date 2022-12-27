#include "View.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
#include"Life.h"
#include <conio.h>

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
	std::cout << buffer;
}



void View::run_game()
{
	/*std::cout << "dddddddddddddddddd" << std::endl;*/

	life->generate_life();
	print_life();
	Sleep(1000);
	int count = 0;
	while (true)
	{
		if (_kbhit() && _getch() == 13) {

			while (true)
			{
				/*char ch;*/

				life->update();
				//system("cls");
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
		if (_kbhit() && _getch() == 27) {
			exit(0);
		}
		
		
	}
	
	//while (true)
	//{
	//	/*char ch;*/

	//	life->update();
	//	//system("cls");
	//	print_life();
	//	Sleep(15);

	//}
}
