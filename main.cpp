#include <iostream>
#include <conio.h>
#include <random>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::setw;

int main()
{
	const int first_size_x = 10;
	const int first_size_y = 5;
	int first[first_size_y][first_size_x];
	
	const int second_size_x = 5;
	const int second_size_y = 5;
	int second[second_size_y][second_size_x];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	for (int i = 0; i < first_size_y; i++)
	{
		for (int j = 0; j < first_size_x; j++)
		{
			first[i][j] = dist(gen);
		}
	}

	for (int i = 0; i < second_size_y; i++)
	{
		for (int j = 0; j < second_size_x; j++)
		{
			second[i][j] = first[i][j * 2] + first[i][(j * 2) + 1];
		}
	}

	cout << "First array:" << endl;
	for (int i = 0; i < first_size_y; i++)
	{
		for (int j = 0; j < first_size_x; j++)
		{
			cout << setw(2) << first[i][j] << "  ";
		}

		cout << endl;
	}

	cout << endl;

	cout << "Second array:" << endl;
	for (int i = 0; i < second_size_y; i++)
	{
		for (int j = 0; j < second_size_x; j++)
		{
			cout << setw(2) << second[i][j] << "  ";
		}

		cout << endl;
	}

	_getch();
	return 0;
}