#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
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
		int i_i = i;
		for (int j = l - 1; j < l + 2; j++) {
			int j_j = j;
			if (i_i == -1)
			{
				i_i = a-1;
			}
			if (i_i >= a)
			{
				i_i = 0;
			}
			if (j_j>=b)
			{
				j_j = 0;
			}
			if (j_j==-1)
			{
				j_j = b-1;
			}
			life_count = life_count + life_array[i_i][j_j];
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
	for (int i = 0; i < a+2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int k = 0; k < a; k++) {
		cout << "#";
		for (int l = 0; l < b; l++) {
			if (life_array[k][l]==1)
			{
				cout << "+";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "#"<<endl;
		
	}
	for (int i = 0; i < a + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
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
	life_array[i+2][j-1] = 1;
	life_array[i+1][j-2] = 1;
}



void Life::run_life()
{
	generate_life();
	print_life();
	Sleep(1000);
	//system("cls");
	while (true)
	{
		for (int k = 0; k < a ; k++) {
			for (int l = 0; l < b; l++) {
				check_rule(k,l);
			}
		}
		for (int i = 0; i < a ; i++)
		{
			for (int j = 0; j < b; j++)
			{
				life_array[i][j] = life_next[i][j];
				life_next[i][j] = 0;
			}
		}
		system("cls");
		print_life();
		Sleep(45);

	}
}
