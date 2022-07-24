#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Functions.h"
using namespace std;

void show_menu() {
	std::cout << "[1] ����� ���" << endl;
	std::cout << "[2] �������� ����" << endl;
	std::cout << "[3] �������� ������ ����" << endl;
	std::cout << "[4] �������� ���� ���" << endl;
	std::cout << "[5] ����� ���" << endl;
	std::cout << "[6] �������������� ����" << endl;
	std::cout << "[7] �����" << endl;
}//����� ����
void see_do() {
	ifstream file_date("date.txt");
	cout << "��� �������� ����?:\n\n\t1.�� �������[No Work!!]\n\t2.�� ����������\n\t3.��� ����\nInput:" << endl;
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
		cout << "������� ���� ������(������ \"dd mm yyyy\"):";
		cin >> now_day >> now_mounth >> now_year;
		system("cls");
		cout << "��� �� ������� ������� �����?:\n\n\t1.�� ����[unstable work]\n\t2.�� ������[unstable work]\n\t3.�� �����[unstable work]\n\t4.�� ������� ��� �����[does not work]." << endl;
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
	cout << "\t\t��� ���� �� ��������:" << endl;
	really_important();
	important();
	the_usual();
}
void really_important() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
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
		if (priority == "����� �����")
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}
	file.close();
}
void important() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
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
		if (priority == "�����")
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}
	file.close();
}
void the_usual() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
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
		if (priority == "������")
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}
	file.close();
}
void see_to_day(int day, int mounth, int year) {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		return;
	}
	string note_name, date, opisaniye, priority;
	int note_day, note_mounth, note_year;
	cout << "     day: " << day << "     \tmounth: " << mounth << "    \t year: " << year << endl;
	cout << "\t\t��� ����:" << endl;
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
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl << endl;//TODO ������� ����� ������ ����
	}
	cout << endl << endl << "��� �������� ������ � ���������� ���� �� �����";
	file.close();
}
void see_all_notes() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		return;
	}
	string note_name,date,opisaniye,priority;
	cout << "\t\t��� ����:" << endl;
	for (int i = 1;!file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}

	file.close();
}//�������� ���� ������� � �����

void importance() {
	std::cout << "�������� ��������� ����� ��� ����:\n\t1.����� �����\n\t2.�����\n\t3.������\n\n��������� �����:";
}
	
void add_note() {
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		exit(EXIT_FAILURE);
	}
	{
		
		string note_name;
		getline(cin, note_name);
		std::cout << "������� �������� ����:";
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
			priority = "����� �����";
		}
		else if (x == 2) {
			priority = "�����";
		}
		else if (x == 3) {
			priority = "������";
		}
		
		file << priority << endl;
	}//note priority
	{
		string description;
		
		getline(cin, description);
		std::cout << "������� �������� ����:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		int day=-5;
		int mounth=-5;
		int year=0;
		cout << "������� ����(������:\"dd mm yyyy\"):";
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
	std::cout << endl << "���� ���� ��������� �������!" << endl;
	//���������� �������
}

string* find_one_note(string& note_to_find, int& n_count) {
	ifstream file("notes.txt");
	if (!file.is_open())
	{
		cout << "������ � ������ � �������� ��������!";
		return nullptr;
	}
	string one_note;
	string* found_notes=nullptr;
	string* found_notes_tmp = nullptr;
	int count = 0;//���-�� �������� �������
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
}//����� ����� ������� ����� ����

string* all_notes(int &n_count) {
	string* all_notes = nullptr;
	string* all_notes_ptr = nullptr;
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
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
}//��� ������� ������ ������� ��� �������� ����� �� ���

void remove_one_note(string* all_notes_arr,int &count, int& choice) {
	ofstream file("notes.txt");
	if (!file.is_open())
	{
		cout << "������ � ������ � �������� ��������!";
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
}//�������� ����� �������

void remove_all_notes() {
	fstream file("notes.txt", ios::out, ios::trunc);
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!"; 
		exit(EXIT_FAILURE);
	}
		
	file.close();
	system("cls");
	cout << "���� �������!" << endl;
	Sleep(2000);
}//�������� ���� �������

void add_note_for_redact() {
	system("cls");
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		exit(EXIT_FAILURE);
	}
	{

		string note_name;
		getline(cin, note_name);
		std::cout << "������� ����� �������� ����:";
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
			priority = "����� �����";
		}
		else if (x == 2) {
			priority = "�����";
		}
		else if (x == 3) {
			priority = "������";
		}

		file << priority << endl;
	}//note priority
	{
		string description;

		getline(cin, description);
		std::cout << "������� �������� ����:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		int day = -5;
		int mounth = -5;
		int year = 0;

		std::cout << "������� ����(������:\"dd mm yyyy\"):";
		cin >> day >> mounth >> year;

		file << day << "." << mounth << "." << year << endl;
	}//date
	file.close();
	std::cout << endl << "���� ���� ������� ����������������!" << endl;
	//���������� �������
}

void editing() {
	{
		int count = 0;
		string* all_notes_arr = all_notes(count);
		cout << "��������! ��������� �� ����� ���� ���� � ������� ����� �����!!!" << endl;
		Sleep(3000);
		cout << "�������� ������� ��� ��������������:" << endl;
		for (int i = 0; i < count; i++) {
			cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
		}
		cout << "����:";
		int choice = 0;
		cin >> choice;
		choice -= 1;
		remove_one_note(all_notes_arr, count, choice);
		delete[] all_notes_arr;
	}
	add_note_for_redact();
}