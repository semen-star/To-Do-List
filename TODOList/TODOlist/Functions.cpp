#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Functions.h"
using namespace std;

void show_menu() {
	std::cout << "[1] Вывод дел" << endl;
	std::cout << "[2] Добавить дело" << endl;
	std::cout << "[3] Удаление одного дела" << endl;
	std::cout << "[4] Удаление всех дел" << endl;
	std::cout << "[5] Поиск дел" << endl;
	std::cout << "[6] Редактирование дела" << endl;
	std::cout << "[7] Выход" << endl;
}//вывод меню
void see_do() {
	ifstream file_date("date.txt");
	cout << "Как выводить дела?:\n\n\t1.По времени[No Work!!]\n\t2.По приоритету\n\t3.Все дела\nInput:" << endl;
	int choice1 = 0;
	cin >> choice1;
	if (choice1 == 3)
	{
		system("cls");
		see_all_notes();
	}

	else if (choice1 == 2) {
		see_priority_notes();
	}
	
	else if (choice1 == 1) {
		system("cls");
		int now_day, now_mounth, now_year;
		cout << "Введите дату сейчас(Формат \"dd mm yyyy\"):";
		cin >> now_day >> now_mounth >> now_year;
		system("cls");
		cout << "Как по времени сделать вывод?:\n\n\t1.На день[unstable work]\n\t2.На неделю[unstable work]\n\t3.На месяц[unstable work]\n\t4.По времени чем ближе[does not work]." << endl;
		int choice2;
		cin >> choice2;
		if (choice2 == 1) {
			int day_to_see = now_day + 1;
			see_to_day(day_to_see, now_mounth, now_year);
		}
		else if (choice2 == 2) {
			int day_to_see = now_day + 7;
			see_to_day(day_to_see, now_mounth, now_year);
		}
		else if (choice2 == 3) {
			int mounth_to_see = now_mounth + 1;
			see_to_day(now_day, mounth_to_see, now_year);
		}
	}
}
void see_priority_notes() {
	system("cls");
	cout << "\t\tВсе дела по важности:" << endl;
	really_important();
	important();
	the_usual();
}
void really_important() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		return;
	}
	string note_name, date, opisaniye, priority;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (priority == "Очень важно")
			cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl;//TODO сделать вывод номера дела
	}
	file.close();
}
void important() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		return;
	}
	string note_name, date, opisaniye, priority;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (priority == "Важно")
			cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl;//TODO сделать вывод номера дела
	}
	file.close();
}
void the_usual() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		return;
	}
	string note_name, date, opisaniye, priority;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (priority == "Обычно")
			cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl;//TODO сделать вывод номера дела
	}
	file.close();
}
void see_to_day(int day, int mounth, int year) {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		return;
	}
	string note_name, date, opisaniye, priority;
	int note_day, note_mounth, note_year;
	cout << "     day: " << day << "     \tmounth: " << mounth << "    \t year: " << year << endl;
	cout << "\t\tВсе дела:" << endl;
	for (int i = 0; !file.eof(); i++){
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		note_day = date[0, 1];
		note_mounth = date[3, 4];
		note_year = date[6,7,8,9];
		if (note_name.empty())
			continue;
		cout << "note_day: " << note_day << "\tnote_mounth: " << note_mounth << "\tnote_year: " << note_year << endl;
		
		if (note_day <= day and note_mounth <= mounth and note_year <= year)
			cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl << endl;//TODO сделать вывод номера дела
	}
	cout << endl << endl << "Так выглядит ошибка в считывании даты из файла";
	file.close();
}
void see_all_notes() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		return;
	}
	string note_name,date,opisaniye,priority;
	cout << "\t\tВсе дела:" << endl;
	for (int i = 1;!file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		cout << '[' << i << ']' << endl << "\tИмя дела: " << note_name << endl << "\tПриоритет дела: " << priority << endl << "\tОписание дела: " << opisaniye << endl << "\tДата дела: " << date << endl;//TODO сделать вывод номера дела
	}

	file.close();
}//просмотр всех заметок в файле

void importance() {
	std::cout << "Выберите насколько важно это дело:\n\t1.Очень важно\n\t2.Важно\n\t3.Обычно\n\nОжидается выбор:";
}
	
void add_note() {
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	{
		
		string note_name;
		getline(cin, note_name);
		std::cout << "Введите название дела:";
		getline(cin, note_name);
		file << note_name << endl;
	}//name note
	{
		std::cout << endl;
		importance();
		int x = 0;
		cin >> x;
		string priority;
		
		if (x == 1) {
			priority = "Очень важно";
		}
		else if (x == 2) {
			priority = "Важно";
		}
		else if (x == 3) {
			priority = "Обычно";
		}
		
		file << priority << endl;
	}//note priority
	{
		string description;
		
		getline(cin, description);
		std::cout << "Введите описание дела:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		int day=-5;
		int mounth=-5;
		int year=0;
		cout << "Введите дату(формат:\"dd mm yyyy\"):";
		cin >> day >> mounth >> year;
		if (day < 10 or mounth<10) {
			string redact_day,redact_mounth;
			if (day == 1)
				redact_day = "01";
			else if (day == 2)
				redact_day = "02";
			else if (day == 3)
				redact_day = "03";
			else if (day == 4)
				redact_day = "04";
			else if (day == 5)
				redact_day = "05";
			else if (day == 6)
				redact_day = "06";
			else if (day == 7)
				redact_day = "07";
			else if (day == 8)
				redact_day = "08";
			else if (day == 9)
				redact_day = "09";
			else if (day == 10)
				redact_day = "10";
			else
				redact_day = day;

			if (mounth == 1)
				redact_mounth = "01";
			else if (mounth == 2)
				redact_mounth = "02";
			else if (mounth == 3)
				redact_mounth = "03";
			else if (mounth == 4)
				redact_mounth = "04";
			else if (mounth == 5)
				redact_mounth = "05";
			else if (mounth == 6)
				redact_mounth = "06";
			else if (mounth == 7)
				redact_mounth = "07";
			else if (mounth == 8)
				redact_mounth = "08";
			else if (mounth == 9)
				redact_mounth = "09";
			else if (mounth == 10)
				redact_mounth = "10";
			else
				redact_mounth = mounth;

			file << redact_day << "." << redact_mounth << "." << year << endl;
		}
		else
			file<<day<< "."<<mounth<<"." << year << endl;
		}//date
		file.close();
	std::cout << endl << "Ваше дело добавлена успешно!" << endl;
	//добавление заметок
}

string* find_one_note(string& note_to_find, int& n_count) {
	ifstream file("notes.txt");
	if (!file.is_open())
	{
		cout << "Ошибка в работе с файловой системой!";
		return nullptr;
	}
	string one_note;
	string* found_notes=nullptr;
	string* found_notes_tmp = nullptr;
	int count = 0;//кол-во найденых заметок
	while (!file.eof())
	{
		getline(file, one_note);
		if (one_note.find(note_to_find)!=-1)
		{
			count++;
			found_notes_tmp = new string[count];
			for (int i = 0; i < count-1; i++)
				found_notes_tmp[i] = found_notes[i];
			found_notes_tmp[count - 1] = one_note;
			delete[] found_notes;
			found_notes = found_notes_tmp;
			found_notes_tmp = nullptr;
		}
	}


	file.close();
	n_count = count;
	return found_notes;
}//поиск одной заметки среди всех

string* all_notes(int &n_count) {
	string* all_notes = nullptr;
	string* all_notes_ptr = nullptr;
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	string note_name;
	int count = 0;
	while (!file.eof()) {
		getline(file, note_name);
		if (note_name.empty())
			continue;
		count++;
		all_notes_ptr = new string[count];
		for (int i = 0; i < count-1; i++)
			all_notes_ptr[i] = all_notes[i];
		all_notes_ptr[count - 1] = note_name;
		delete[] all_notes;
		all_notes = all_notes_ptr;
		all_notes_ptr = nullptr;
	}

	file.close();
	n_count = count;
	return all_notes;
}//доп функция вывода заметок для удаления одной из них

void remove_one_note(string* all_notes_arr,int &count, int& choice) {
	ofstream file("notes.txt");
	if (!file.is_open())
	{
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < count; i++){
		if (i == choice)
			continue;
		if (i == choice + 1)
			continue;
		if (i == choice + 2)
			continue;
		if (i == choice + 3)
			continue;
		file << all_notes_arr[i] << endl;
	}
	
	file.close();
}//удаление одной заметки

void remove_all_notes() {
	fstream file("notes.txt", ios::out, ios::trunc);
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!"; 
		exit(EXIT_FAILURE);
	}
		
	file.close();
	system("cls");
	cout << "Дела удалены!" << endl;
	Sleep(2000);
}//удаление всех заметок

void add_note_for_redact() {
	system("cls");
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "Ошибка в работе с файловой системой!";
		exit(EXIT_FAILURE);
	}
	{

		string note_name;
		getline(cin, note_name);
		std::cout << "Введите новое название дела:";
		getline(cin, note_name);
		file << note_name << endl;
	}//name note
	{
		std::cout << endl;
		importance();
		int x = 0;
		cin >> x;
		string priority;

		if (x == 1) {
			priority = "Очень важно";
		}
		else if (x == 2) {
			priority = "Важно";
		}
		else if (x == 3) {
			priority = "Обычно";
		}

		file << priority << endl;
	}//note priority
	{
		string description;

		getline(cin, description);
		std::cout << "Введите описание дела:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		int day = -5;
		int mounth = -5;
		int year = 0;

		std::cout << "Введите дату(формат:\"dd mm yyyy\"):";
		cin >> day >> mounth >> year;

		file << day << "." << mounth << "." << year << endl;
	}//date
	file.close();
	std::cout << endl << "Ваше дело успешно отредактированно!" << endl;
	//добавление заметок
}

void editing() {
	{
		int count = 0;
		string* all_notes_arr = all_notes(count);
		cout << "ВНИМАНИЕ! ВЫБИРАЙТЕ ПО ИМЕНИ ВАШЕ ДЕЛО И ВВОДИТЕ НОМЕР ИМЕНИ!!!" << endl;
		Sleep(3000);
		cout << "Выберите заметку для редактирования:" << endl;
		for (int i = 0; i < count; i++) {
			cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
		}
		cout << "Ввод:";
		int choice = 0;
		cin >> choice;
		choice -= 1;
		remove_one_note(all_notes_arr, count, choice);
		delete[] all_notes_arr;
	}
	add_note_for_redact();
}