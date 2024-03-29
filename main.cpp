#include "Life.h"
#include "Rule.h"
#include "View.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>



int main(int argc,char *argv[]) {
	//std::string name = "Game Of Life";
	//std::cout << name << std::endl;
	setlocale(LC_ALL, "Russian");
	std::string line ;
	std::string name_of_life ;
	//std::vector<std::string> v;
	std::string format;
	std::vector<int> b_int;
	std::vector<int> s_int;
	std::string cordin;
	std::string res;
	int len_of_y = 30;
	int len_of_x = 40;

	std::ifstream in("in_game.txt"); // �������� ���� ��� ������
	
	if (in.is_open())
	{
		getline(in, line);
		if (line == "#Life 1.06")
		
		{
			while (getline(in, line))
			{
				if (line[1] == 'N')
				{
					name_of_life.append(line.erase(0,3));
				}
				if (line[1] == 'R')
				{
					format = line;
					int count = 0;
					for (int i = 4; i < format.size(); i++)
					{
						if (format[i] != '/')
						{
							b_int.push_back(format[i] - '0');
						}
						else
						{
							count = i;
							break;
						}
					}
					for (int i = count + 2; i < format.size(); i++)
					{
						s_int.push_back(format[i] - '0');
					}

				}
				if (line[1] == 'S')
				{
					cordin = line.erase(0,3);
					int k = 0;

					while (cordin[k] != ' ')
					{
						res.push_back(cordin[k]);
						k++;
					}
					len_of_x = atoi(res.c_str());
					k += 1;
					res = "";
					while (isdigit(cordin[k]))
					{
						res.push_back(cordin[k]);
						k++;
					}
					len_of_y = atoi(res.c_str());

				}
				/*v.push_back(line);*/
			}
		}
		
	}
	
	in.close();
	std::cout << std::setw(len_of_x);
	std::cout << "############ Game Of Life ############" << std::endl;
	std::cout << "������� ����, ���� ������������� ����������� ������� � ������������� ����" << std::endl;
	std::cout << "� ������ ���� �� ������ ������ ��������� ����, ����� ��� �������, � ���������� ������� ��������" << std::endl;
	std::cout << "��� ������ ����� ����� ���������� ���������� ��������" << std::endl;
	std::cout << "1) Glider, ����� ��������� ��� ����, ����� �� ������� 1" << std::endl;
	std::cout << "2) Random field, ����� ��������� ��� ����, ����� �� ������� 2" << std::endl;
	std::cout << "3) Gosper glider gun, ����� ��������� ��� ����, ����� �� ������� 3" << std::endl;
	std::cout << "4) Pulsar, ����� ��������� ��� ����, ����� �� ������� 4" << std::endl;
	std::cout << "5) Penta-decathlon, ����� ��������� ��� ����, ����� �� ������� 5" << std::endl;
	std::cout << "6) Light-weight spaceship, ����� ��������� ��� ����, ����� �� ������� 6" << std::endl;
	std::cout << "7) double frame, ����� ��������� ��� ����, ����� �� ������� 7" << std::endl;
	std::cout << "8) three trapezes, ����� ��������� ��� ����, ����� �� ������� 8" << std::endl;


	
	
	Rule rule(b_int, s_int);
	
	View game(len_of_x, len_of_y, &rule);
	game.run_game();
	return 0;
}