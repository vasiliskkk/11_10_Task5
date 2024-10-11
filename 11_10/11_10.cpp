﻿//5.Чтение и установка параметров курсора
#include <windows.h> 
#include <iostream> 
using namespace std; 
int main()
{
	char c;
	HANDLE hStdout; // дескриптор стандартного вывода 
	CONSOLE_CURSOR_INFO ссі; // информация о курсоре 
	// читаем дескриптор стандартного вывода 
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // читаем информацию о курсоре
	if (!SetConsoleCursorInfo(hStdout, &ссі))
		cout << "Get console cursor info failed." << endl;
	// выводим информацию о курсоре
	cout << "Size of cursor in procents of char= " << ссі.dwSize << endl;
	cout << "Visibility of cursor = " << ссі.bVisible << endl;
	// читаем новый размер курсора
	cout << "Input a new size of cursor (1-100): ";
	cin >> ссі.dwSize;
	// устанавливаем новый размер курсора
	if (!SetConsoleCursorInfo(hStdout, &ссі))
		cout << "set console cursor info failed." << endl; 
	cout << "Input any char to make the cursor invisible: ";
	cin >> c;
	// делаем курсор невидимым
	ссі.bVisible = FALSE;
	// устанавливаем невидимый курсор
	if (!SetConsoleCursorInfo(hStdout, &ссі))
		cout << "set console cursor info failed." << endl; 
	cout << "Input any char to make the cursor visible: ";
	cin >> c;
	// делаем курсор невидимым
	ссі.bVisible = TRUE;
	// устанавливаем видимый курсор
	if (!SetConsoleCursorInfo(hStdout, &ссі))
		cout << "set console cursor info failed." << endl;
	return 0;
}