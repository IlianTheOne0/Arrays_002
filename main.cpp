#include <iostream>
#include <conio.h>
#include <random>
#include <iomanip>
#include <Windows.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::setw;


void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(output, pos);
}

void setcolor(unsigned short color) {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(con, color);
}

void set_background_color(unsigned short color) {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(con, (color << 4) | 0x0F);
}

void display_menu(int selected) {
    int y_coord = 2;

    system("cls");

    cout << "#>-------<MENU>-------<#" << endl;
    cout << "|                      |" << endl;
    cout << "|         UP           |" << endl;
    cout << "|         RIGHT        |" << endl;
    cout << "|         DOWN         |" << endl;
    cout << "|         LEFT         |" << endl;
    cout << "|         EXIT         |" << endl;
    cout << "|                      |" << endl;
    cout << "#>--------------------<#" << endl;

    for (int i = 1; i <= 5; i++) {
        gotoxy(10, y_coord);

        if (i == selected) {
            set_background_color(0x0A);
        }
        else {
            setcolor(7);
        }

        switch (i) {
            case 1: cout << "UP"; break;
            case 2: cout << "RIGHT"; break;
            case 3: cout << "DOWN"; break;
            case 4: cout << "LEFT"; break;
            case 5: cout << "EXIT"; break;
        }

        y_coord++;
    }

    setcolor(7);
}


int _output(int arr[][6], int size_x, int size_y)
{
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            cout << setw(2) << arr[i][j];

            cout << ' ';
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}

int _up(int arr[][6], int size_x, int size_y, int number_of_shifts)
{
    for (int shifts = 0; shifts < number_of_shifts; shifts++) {
        for (int j = 0; j < size_x; j++) {
            int temp = arr[0][j];

            for (int i = 0; i < size_y - 1; i++) {
                arr[i][j] = arr[i + 1][j];
            }
            
            arr[size_y - 1][j] = temp;
        }
    }

    return 0;
}

int _down(int arr[][6], int size_x, int size_y, int number_of_shifts)
{
    for (int shifts = 0; shifts < number_of_shifts; shifts++) {
        for (int j = 0; j < size_x; j++) {
            int temp = arr[size_y - 1][j];

            for (int i = size_y - 1; i > 0; i--) {
                arr[i][j] = arr[i - 1][j];
            }

            arr[0][j] = temp;
        }
    }

    return 0;
}

int _left(int arr[][6], int size_x, int size_y, int number_of_shifts)
{
    return 0;
}

int _right(int arr[][6], int size_x, int size_y, int number_of_shifts)
{
    return 0;
}


int main()
{
	const int size_x = 6;
	const int size_y = 4;
	int arr[size_y][size_x];

    int number_of_shifts;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			arr[i][j] = dist(gen);
		}
	}

    int selected = 1;
    display_menu(selected);

    while (true)
    {
        char choice = _getch();

        if (choice == -32) {
            choice = _getch();

            switch (choice) {
            case 72:
                if (selected > 1) selected--;
                break;

            case 80:
                if (selected < 5) selected++;
                break;
            }
            display_menu(selected);
        }
        else if (choice == 13) {
            system("cls");

            if (selected != 5)
            {
                cout << "Enter the number of shifts: ";
                cin >> number_of_shifts;

                cout << endl << endl << "Before: " << endl;
                _output(arr, size_x, size_y);
            }

            switch (selected) {
                case 1: _up(arr, size_x, size_y, number_of_shifts); break;
                case 2: _right(arr, size_x, size_y, number_of_shifts); break;
                case 3: _down(arr, size_x, size_y, number_of_shifts);  break;
                case 4: _left(arr, size_x, size_y, number_of_shifts); break;
                case 5: return 0; break;
            }

            if (selected != 5)
            {
                cout << "After: " << endl;
                _output(arr, size_x, size_y);
            }

            cout << endl << endl;
            system("pause");
            display_menu(selected);
            }
        }

	_getch();
	return 0;
}