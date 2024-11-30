#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int main()
{
	const int size_i = 3;
	const int size_j = 4;
	int arr[size_i][size_j];

	int sum_of_row_col = 0;
	int sum_of_row = 0;
	int sum_of_col = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 99);

	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			arr[i][j] = dist(rd);
			sum_of_row_col += arr[i][j];
		}
	}

	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (arr[i][j] < 10 && arr[i][j] >= 0)
			{
				cout << " ";
			}

			cout << arr[i][j];
			sum_of_row += arr[i][j];

			cout << "   ";
		}

		cout << "|   " << sum_of_row << endl;

		sum_of_row = 0;
	}

	for (int i = 0; i <= 27; i++)
	{
		cout << '-';
	}

	cout << endl;

	for (int j = 0; j < size_j; j++)
	{
		for (int i = 0; i < size_i; i++)
		{
			sum_of_col += arr[i][j];
		}

		cout << sum_of_col << "  ";
		sum_of_col = 0;
	}

	cout << " |   " << sum_of_row_col << endl;

	_getch();
	return 0;
}