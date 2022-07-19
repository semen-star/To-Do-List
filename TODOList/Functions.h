#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

void show_menu() {
	cout << "[1] Просмотр всех дел" << endl;
	cout << "[2] Добавить дело" << endl;
	cout << "[3] Удаление одного дела" << endl;
	cout << "[4] Удаление всех дел" << endl;
	cout << "[5] Поиск дел" << endl;
	cout << "[6] Вывод дел по приоритету" << endl;
	cout << "[7] Вывод дел по дате" << endl;
	cout << "[8] Выход" << endl;
}