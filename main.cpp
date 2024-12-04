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

int _min(int arr[][5], int size)
{
	int number = arr[0][0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] < number)
			{
				number = arr[i][j];
			}
		}
	}

	return number;
}

int _max(int arr[][5], int size)
{
	int number = arr[0][0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] > number)
			{
				number = arr[i][j];
			}
		}
	}

	return number;
}

int main()
{
	const int size = 5;
	int arr[size][size];

	int sum = 0;
	double mean;
	int min_;
	int max_;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 99);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = dist(gen);
			sum += arr[i][j];
		}
	}
	
	mean = (double)sum / (size * size);
	min_ = _min(arr, size);

	max_ = _max(arr, size);
	min_ = _min(arr, size);

	cout << "The sum of all elements of the array: " << sum << endl;
	cout << "The mean of all elements of the array: " << mean << endl;
	cout << "The min element of the array: " << min_ << endl;
	cout << "The max element of the array: " << max_ << endl;

	cout << endl << endl << endl << "Array:" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(2) << arr[i][j];

			cout << "  ";
		}

		cout << endl;
	}

	_getch();
	return 0;
}