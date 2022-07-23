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
	cout << "��� �������� ����?:\n\n\t1.�� �������\n\t2.�� ����������\n\t3.��� ����\nInput:" << endl;
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
		else if (choice2 == 2) {
			int mounth_to_see = now_mounth + 1;
			file_date  >> now_day >> mounth_to_see >> now_year;
			see_to_mounth(now_day, mounth_to_see, now_year);
		}
	}
}
void see_priority_notes() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		return;
	}

	string note_name, date, opisaniye, priority;
	cout << "\t\t��� ���� �� ��������:" << endl;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if(priority=="����� �����")
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}

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
	ifstream file_date("date.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		return;
	}
	string now_date;
	getline(file_date, now_date);
	string note_name, date, opisaniye, priority;
	cout << "\t\t��� ����:" << endl;
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if(date<=now_date)
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}

	file.close();
}
void see_to_mounth(int day, int mounth, int year) {
	ifstream file("notes.txt");
	ifstream file_date("date.txt");
	if (!file.is_open()) {
		cout << "������ � ������ � �������� ��������!";
		return;
	}
	string now_date;
	getline(file_date, now_date);
	string note_name, date, opisaniye, priority;
	cout << "\t\t��� ����:" << endl;
	string now_date;
	now_date = "day.mounth.year";//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 1; !file.eof(); i++)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty())
			continue;
		if (date <= now_date)
			cout << '[' << i << ']' << endl << "\t��� ����: " << note_name << endl << "\t��������� ����: " << priority << endl << "\t�������� ����: " << opisaniye << endl << "\t���� ����: " << date << endl;//TODO ������� ����� ������ ����
	}

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
	
	for (int i = 0; i < count; i++)
	{
		if (i==choice-1)
			continue;
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