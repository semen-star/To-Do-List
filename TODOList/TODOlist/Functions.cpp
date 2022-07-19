#include <iostream>
#include <fstream>
#include <string>
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
}//вывод меню

void add_note(string& new_note) {
	cout << new_note;
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "ERROR!! File isn't open!";
		exit(EXIT_FAILURE);
	}
	file << new_note << endl;

	file.close();
	cout <<endl<<"Ваша заметка добавлена успешно!"<<endl;
}//добавление заметок

void see_all_notes() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "Вы не добавили ни одной заметки. Программа не может сделать вывод."<<endl;
		return;
	}
	string one_note;
	cout << "\t\tВсе заметки:" << endl;
	for (int i = 1;!file.eof(); i++)
	{
		getline(file, one_note);
		if (one_note.empty())
			continue;
		cout << '[' << i << ']' << one_note << endl;
	}

	file.close();
}//просмотр всех заметок в файле

string* find_one_one(string& note_to_find, int& n_count) {
	ifstream file("notes.txt");
	if (!file.is_open())
	{
		cout<<"У вас нет заметок. Добавьте их!" << endl;
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
		cout << "Файл не имеет заметок!"<<endl;
		exit(EXIT_FAILURE);
	}
	string one_note;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.empty())
			continue;
		count++;
		all_notes_ptr = new string[count];
		for (int i = 0; i < count-1; i++)
			all_notes_ptr[i] = all_notes[i];
		all_notes_ptr[count - 1] = one_note;
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
		cout << "Ошибка файл не может быть открыт!";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < count; i++)
	{
		if (i==choice-1)
			continue;
		file << all_notes_arr[i] << endl;
	}

	file.close();
}//удаление одной заметки

void remove_all_notes() {
	fstream file("notes.txt", ios::out, ios::trunc);
	if (!file.is_open()) {
		cout << "Ошибка. Файл не открыт!";
		exit(EXIT_FAILURE);
	}
		
	file.close();
}//удаление всех заметок