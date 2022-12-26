#include "Life.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<windows.h>
using namespace std;

Life::Life()
{
	for (int k = 0; k < a; k++) {
		for (int l = 0; l < b; l++) {
			life_array[k][l] = 0;
			life_next[k][l] = 0;
		}
	}
}

Life::~Life()
{
}

int Life::check_rule(int k, int l)
{

	int life_count = 0;

	for (int i = k - 1; i < k + 2; i++)
	{
		for (int j = l - 1; j < l + 2; j++) {
			life_count = life_count + life_array[i][j];
		}
	}
	life_count = life_count - life_array[k][l];

	if (life_count == 3 && life_array[k][l]==0)
	{
		life_next[k][l] = 1;
	}
	if ((life_count == 2 || life_count == 3) && life_array[k][l] == 1)
	{
		life_next[k][l] = 1;
	}
	if ((life_count < 2 || life_count > 3) && life_array[k][l]==1)
	{
		life_next[k][l] = 0;
	}

	return life_next[k][l];
}

void Life::print_life()
{
	for (int k = 1; k < a - 1; k++) {
		for (int l = 1; l < b - 1; l++) {
			if (life_array[k][l]==1)
			{
				cout << "+";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

void Life::generate_life()
{
	/*for (int k = 1; k < a - 1; k++) {
		for (int l = 1; l < b - 1; l++) {
			life_array[k][l] = rand()%2;
		}
	}*/
	int i = 3;
	int j = 3;
	life_array[i][j] = 1;
	life_array[i+1][j] = 1;
	life_array[i+2][j] = 1;
}



void Life::run_life()
{
	generate_life();
	print_life();
	Sleep(1000);
	system("cls");
	while (true)
	{
		for (int k = 1; k < a - 1; k++) {
			for (int l = 1; l < b - 1; l++) {
				check_rule(k,l);
			}
		}
		for (int i = 0; i < a + 1; i++)
		{
			for (int j = 0; j < b + 1; j++)
			{
				life_array[i][j] = life_next[i][j];
			}
		}
		print_life();
		Sleep(5);
		system("cls");
	}
}
