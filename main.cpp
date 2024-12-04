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
using std::setfill;
using std::setw;

int main()
{
	const int size_x = 4;
	const int size_y = 3;
	int arr[size_y][size_x];

	unsigned long long sum_of_row = 0;
	unsigned long long sum_of_col = 0;
	unsigned long long sum_of_all = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 15);

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			arr[i][j] = dist(rd);
			sum_of_all += arr[i][j];
		}
	}





	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cout << setfill(' ') << setw(2) << arr[i][j] << "  ";

			sum_of_row += arr[i][j];
		}

		cout << " |   " << sum_of_row << endl;
		sum_of_row = 0;
	}


	for (int i = 0; i < 25; i++)
	{
		cout << "-";
	}
	cout << endl;


	for (int j = 0; j < size_x; j++)
	{
		for (int i = 0; i < size_y; i++)
		{

			sum_of_col += arr[i][j];
		}

		cout << setfill(' ') << setw(2) << sum_of_col << "  ";
		sum_of_col = 0;
	}


	cout << " |   " << sum_of_all << endl;
	

	cout << endl;





	_getch();
	return 0;
}