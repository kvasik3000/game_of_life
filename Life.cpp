#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include "Rule.h"
using namespace std;

Life::Life(int a, int b, Rule* rule)
{
	this->rule = rule;
	this->a = a;
	this->b = b;

	for (int k = 0; k < a; k++) {
		std::vector<int> r1, r2;
		for (int l = 0; l < b; l++) {
			r1.push_back(0);
			r2.push_back(0);
		}
		life_array.push_back(r1);
		life_next.push_back(r2);
	}
}


Life::~Life() {}

int Life::check_rule(int k, int l)
{
	int life_count = 0;

	for (int i = k - 1; i < k + 2; i++)
	{
		int i_i = i;
		for (int j = l - 1; j < l + 2; j++) {
			int j_j = j;
			if (i_i == -1)
			{
				i_i = a - 1;
			}
			else if (i_i >= a)
			{
				i_i = 0;
			}
			if (j_j >= b)
			{
				j_j = 0;
			}
			else if (j_j == -1)
			{
				j_j = b - 1;
			}
			life_count = life_count + life_array[i_i][j_j];
		}
	}
	life_count = life_count - life_array[k][l];

	std::vector<int> born = rule->get_born();
	std::vector<int> survive = rule->get_survive();

	for (int i = 0; i < born.size(); i++)
	{
		int n = born[i];
		if (life_count == n && life_array[k][l] == 0)
		{
			life_next[k][l] = 1;
			return life_next[k][l];
		}
	}
	for (int i = 0; i < survive.size(); i++)
	{
		int n = survive[i];
		if (life_count == n && life_array[k][l] == 1)
		{
			life_next[k][l] = 1;
			return life_next[k][l];
		}
	}
	life_next[k][l] = 0;

	return life_next[k][l];
}



void Life::generate_life()
{
	while (true)
	{
		//if (!_kbhit()) continue;
		int key = _getch();
		//Glider - ������� 1 
		if (key == 49) {

			int i = 3;
			int j = 3;
			life_array[i][j] = 1;
			life_array[i + 1][j] = 1;
			life_array[i + 2][j] = 1;
			life_array[i + 2][j - 1] = 1;
			life_array[i + 1][j - 2] = 1;
			break;
		}
		else if (key == 50)
		{
			//random generate
			for (int k = 1; k < a - 1; k++) {
				for (int l = 1; l < b - 1; l++) {
					life_array[k][l] = rand() % 2;
				}
			}
			break;
		}
		else if (key == 51)
		{
			//Gosper glider gun
			int i = 14;
			int j = 1;
			life_array[i][j] = 1;
			life_array[i + 1][j] = 1;
			life_array[i + 1][j + 1] = 1;
			life_array[i][j + 1] = 1;
			life_array[i][j + 10] = 1;
			life_array[i - 1][j + 11] = 1;
			life_array[i - 2][j + 12] = 1;
			life_array[i - 2][j + 13] = 1;
			life_array[i + 1][j + 10] = 1;
			life_array[i + 1][j + 14] = 1;
			life_array[i + 1][j + 16] = 1;
			life_array[i][j + 16] = 1;
			life_array[i - 1][j + 15] = 1;
			life_array[i + 1][j + 17] = 1;//��������
			life_array[i][j + 20] = 1;
			life_array[i - 1][j + 20] = 1;
			life_array[i - 2][j + 20] = 1;
			life_array[i - 3][j + 22] = 1;
			life_array[i - 3][j + 24] = 1;
			life_array[i - 4][j + 24] = 1;
			life_array[i][j + 21] = 1;
			life_array[i + 1][j + 22] = 1;
			life_array[i + 1][j + 24] = 1;
			life_array[i - 1][j + 34] = 1;
			life_array[i - 2][j + 34] = 1;
			life_array[i + 2][j + 24] = 1;
			life_array[i - 1][j + 35] = 1;
			life_array[i - 2][j + 35] = 1;
			life_array[i - 1][j + 21] = 1;
			life_array[i - 2][j + 21] = 1;
			life_array[i + 2][j + 10] = 1;
			life_array[i + 3][j + 11] = 1;
			life_array[i + 4][j + 12] = 1;
			life_array[i + 4][j + 13] = 1;
			life_array[i + 3][j + 15] = 1;
			life_array[i + 2][j + 16] = 1;
			break;
		}
		else if (key == 52)
		{
			//Pulsar
			int i = this->a / 2;
			int j = this->b / 2;
			life_array[i - 1][j - 2] = 1;
			life_array[i - 1][j - 3] = 1;
			life_array[i - 1][j - 4] = 1;
			life_array[i - 2][j - 5] = 1;
			life_array[i - 3][j - 5] = 1;
			life_array[i - 3][j - 4] = 1;
			life_array[i - 3][j - 6] = 1;
			life_array[i - 4][j - 6] = 1;
			life_array[i - 2][j - 3] = 1;


			life_array[i - 1][j + 2] = 1;
			life_array[i - 1][j + 3] = 1;
			life_array[i - 1][j + 4] = 1;
			life_array[i - 2][j + 5] = 1;
			life_array[i - 3][j + 5] = 1;
			life_array[i - 3][j + 4] = 1;
			life_array[i - 3][j + 6] = 1;
			life_array[i - 4][j + 6] = 1;
			life_array[i - 2][j + 3] = 1;


			life_array[i - 2][j - 1] = 1;
			life_array[i - 3][j - 1] = 1;
			life_array[i - 4][j - 1] = 1;
			life_array[i - 5][j - 2] = 1;
			life_array[i - 5][j - 3] = 1;
			life_array[i - 4][j - 3] = 1;
			life_array[i - 6][j - 3] = 1;
			life_array[i - 6][j - 4] = 1;
			life_array[i - 3][j - 2] = 1;


			life_array[i - 2][j + 1] = 1;
			life_array[i - 3][j + 1] = 1;
			life_array[i - 4][j + 1] = 1;
			life_array[i - 5][j + 2] = 1;
			life_array[i - 5][j + 3] = 1;
			life_array[i - 4][j + 3] = 1;
			life_array[i - 6][j + 3] = 1;
			life_array[i - 6][j + 4] = 1;
			life_array[i - 3][j + 2] = 1;


			life_array[i + 1][j - 2] = 1;
			life_array[i + 1][j - 3] = 1;
			life_array[i + 1][j - 4] = 1;
			life_array[i + 2][j - 5] = 1;
			life_array[i + 3][j - 5] = 1;
			life_array[i + 3][j - 4] = 1;
			life_array[i + 3][j - 6] = 1;
			life_array[i + 4][j - 6] = 1;
			life_array[i + 2][j - 3] = 1;


			life_array[i + 1][j + 2] = 1;
			life_array[i + 1][j + 3] = 1;
			life_array[i + 1][j + 4] = 1;
			life_array[i + 2][j + 5] = 1;
			life_array[i + 3][j + 5] = 1;
			life_array[i + 3][j + 4] = 1;
			life_array[i + 3][j + 6] = 1;
			life_array[i + 4][j + 6] = 1;
			life_array[i + 2][j + 3] = 1;


			life_array[i + 2][j - 1] = 1;
			life_array[i + 3][j - 1] = 1;
			life_array[i + 4][j - 1] = 1;
			life_array[i + 5][j - 2] = 1;
			life_array[i + 5][j - 3] = 1;
			life_array[i + 4][j - 3] = 1;
			life_array[i + 6][j - 3] = 1;
			life_array[i + 6][j - 4] = 1;
			life_array[i + 3][j - 2] = 1;


			life_array[i + 2][j + 1] = 1;
			life_array[i + 3][j + 1] = 1;
			life_array[i + 4][j + 1] = 1;
			life_array[i + 5][j + 2] = 1;
			life_array[i + 5][j + 3] = 1;
			life_array[i + 4][j + 3] = 1;
			life_array[i + 6][j + 3] = 1;
			life_array[i + 6][j + 4] = 1;
			life_array[i + 3][j + 2] = 1;

			break;
		}
		else if (key == 53)
		{
			//Penta-decathlon
			int i = this->a / 2;
			int j = this->b / 2;
			life_array[i - 3][j] = 1;
			life_array[i - 3][j + 1] = 1;
			life_array[i - 3][j + 2] = 1;
			life_array[i - 3][j - 1] = 1;
			life_array[i - 3][j - 2] = 1;
			life_array[i - 4][j] = 1;
			life_array[i - 4][j - 1] = 1;
			life_array[i - 4][j + 1] = 1;
			life_array[i - 5][j] = 1;

			life_array[i + 4][j] = 1;
			life_array[i + 4][j + 1] = 1;
			life_array[i + 4][j + 2] = 1;
			life_array[i + 4][j - 1] = 1;
			life_array[i + 4][j - 2] = 1;
			life_array[i + 5][j] = 1;
			life_array[i + 5][j - 1] = 1;
			life_array[i + 5][j + 1] = 1;
			life_array[i + 6][j] = 1;

			break;
		}
		else if (key == 54) {

			//Light-weight spaceship
			int i = this->a / 2;
			int j = this->b / 2;
			life_array[i][j] = 1;
			life_array[i + 1][j] = 1;
			life_array[i + 2][j] = 1;
			life_array[i + 3][j - 1] = 1;
			life_array[i][j - 1] = 1;
			life_array[i][j - 2] = 1;
			life_array[i][j - 3] = 1;
			life_array[i + 1][j - 4] = 1;
			life_array[i + 3][j - 4] = 1;
			break;

		}
		else if (key == 55)
		{
			//double frame
			for (int i = 0; i < this->a; i++)
			{
				life_array[i][0] = 1;
				life_array[i][this->b - 1] = 1;
				life_array[i][1] = 1;
				life_array[i][this->b - 2] = 1;
			}
			for (int i = 1; i < this->b - 1; i++)
			{
				life_array[0][i] = 1;
				life_array[this->a - 1][i] = 1;
				life_array[1][i] = 1;
				life_array[this->a - 2][i] = 1;
			}

			break;
		}
		else if (key == 56)
		{
			//three trapezes
			int i = this->a / 2;
			int j = this->b / 2;

			life_array[i - 1][j] = 1;
			life_array[i + 1][j] = 1;
			life_array[i][j - 1] = 1;
			life_array[i][j + 1] = 1;

			life_array[i - 4][j] = 1;
			life_array[i + 4][j] = 1;
			life_array[i][j + 4] = 1;
			life_array[i][j - 4] = 1;

			life_array[i - 3][j - 1] = 1;
			life_array[i + 3][j - 1] = 1;
			life_array[i + 1][j - 3] = 1;
			life_array[i - 1][j + 3] = 1;

			life_array[i - 2][j - 2] = 1;
			life_array[i + 2][j - 2] = 1;
			life_array[i - 2][j + 2] = 1;
			life_array[i + 2][j + 2] = 1;

			life_array[i - 3][j + 1] = 1;
			life_array[i + 3][j + 1] = 1;
			life_array[i - 1][j - 3] = 1;
			life_array[i + 1][j + 3] = 1;

			life_array[i - 8][j] = 1;
			life_array[i + 8][j] = 1;
			life_array[i][j+ 8] = 1;
			life_array[i][j - 8] = 1;

			life_array[i - 6][j+2] = 1;
			life_array[i - 6][j-2] = 1;
			life_array[i + 6][j+2] = 1;
			life_array[i + 6][j-2] = 1;
			life_array[i+2][j + 6] = 1;
			life_array[i-2][j + 6] = 1;
			life_array[i+2][j - 6] = 1;
			life_array[i-2][j - 6] = 1;

			life_array[i - 7][j + 1] = 1;
			life_array[i - 7][j - 1] = 1;
			life_array[i + 7][j + 1] = 1;
			life_array[i + 7][j - 1] = 1;
			life_array[i + 1][j + 7] = 1;
			life_array[i - 1][j + 7] = 1;
			life_array[i + 1][j - 7] = 1;
			life_array[i - 1][j - 7] = 1;

			life_array[i - 5][j - 3] = 1;
			life_array[i + 5][j - 3] = 1;
			life_array[i + 3][j - 5] = 1;
			life_array[i - 3][j + 5] = 1;

			life_array[i - 4][j - 4] = 1;
			life_array[i + 4][j - 4] = 1;
			life_array[i - 4][j + 4] = 1;
			life_array[i + 4][j + 4] = 1;

			life_array[i - 5][j + 3] = 1;
			life_array[i + 5][j + 3] = 1;
			life_array[i - 3][j - 5] = 1;
			life_array[i + 3][j + 5] = 1;

			

			break;
		}

	}
}


std::vector<std::vector<int>> Life::get_life_array() {
	return life_array;
}

std::vector<std::vector<int>> Life::get_life_next()
{
	return life_next;
}

int Life::get_a()
{
	return a;
}

int Life::get_b()
{
	return b;
}

void Life::update()
{
	for (int k = 0; k < a; k++) {
		for (int l = 0; l < b; l++) {

			check_rule(k, l);
		}
	}
	life_array = life_next;
}
