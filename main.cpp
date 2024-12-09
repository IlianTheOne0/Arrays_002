#include <iostream>
#include <conio.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setfill;
using std::setw;

int main()
{
	const int size_x = 4;
	const int size_y = 3;
	int arr[size_y][size_x];
	
	int number;
	
	cout << "Enter the number: ";
	cin >> number;

	cout << endl;

	for (int i = 0; i < size_y; i++)
	{
		arr[i][0] = number;
		for (int j = 1; j < size_x; j++)
		{
			arr[i][j] = number * 2;
			number = number * 2;
		}
	}

	cout << "Array:" << endl;
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cout << setw(6) << arr[i][j];
		}

		cout << endl;
	}

	_getch();
	return 0;
}