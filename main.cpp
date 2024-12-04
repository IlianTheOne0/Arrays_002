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
    cout << "|        TOP           |" << endl;
    cout << "|        RIGHT         |" << endl;
    cout << "|        BOTTOM        |" << endl;
    cout << "|        RIGHT         |" << endl;
    cout << "|        Exit          |" << endl;
    cout << "|                      |" << endl;
    cout << "#>--------------------<#" << endl;

    for (int i = 1; i <= 5; ++i) {
        gotoxy(9, y_coord);

        if (i == selected) {
            set_background_color(0x0A);
        }
        else {
            setcolor(7);
        }

        switch (i) {
        case 1: cout << "TOP"; break;
        case 2: cout << "RIGHT"; break;
        case 3: cout << "BOTTOM"; break;
        case 4: cout << "RIGHT"; break;
        case 5: cout << "Exit"; break;
        }

        y_coord++;
    }

    setcolor(7);
}

int main()
{
	const int size_x = 6;
	const int size_y = 4;
	int arr[size_y][size_x];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			arr[i][j] = dist(gen);
		}
	}

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cout << arr[i][j];

			cout << ' ';
		}

		cout << endl;
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



            switch (selected) {
                case 5:
                {
                    return 0;
                } break;
            }

            cout << endl << endl;
            system("pause");
            display_menu(selected);
            }
        }

	_getch();
	return 0;
}