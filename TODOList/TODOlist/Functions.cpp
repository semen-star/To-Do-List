#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void show_menu() {
	cout << "[1] �������� ���� ���" << endl;
	cout << "[2] �������� ����" << endl;
	cout << "[3] �������� ������ ����" << endl;
	cout << "[4] �������� ���� ���" << endl;
	cout << "[5] ����� ���" << endl;
	cout << "[6] ����� ��� �� ���������� development stage" << endl;
	cout << "[7] ����� ��� �� ���� development stage" << endl;
	cout << "[8] �����" << endl;
}//����� ����
void importance() {
	cout << "�������� ��������� ����� ��� ����:\n\t1.����� �����\n\t2.�����\n\t3.������\n\n��������� �����:";
}
	
void add_note() {
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "ERROR!! File isn't open!";
		exit(EXIT_FAILURE);
	}
	{
		
		string note_name;
		getline(cin, note_name);
		cout << "������� �������� ����:";
		getline(cin, note_name);
		file << note_name << endl;
	}//name note
	{
		cout << endl;
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
		cout << "������� �������� ����:";
		getline(cin, description);
		file << description << endl;
	}//note description
	{
		unsigned int day=-5;
		unsigned int mounth=-5;
		int year=0;
		while (day < 31 and day>0 and mounth > 0 and mounth < 12) {
			cout << "������� ����(������:\"dd mm yyyy\"):";
			cin >> day >> mounth >> year;
		}
		file<<day<< " "<<mounth<<" " << year << endl;
	}//date

	file.close();
	cout <<endl<<"���� ���� ��������� �������!"<<endl;
}//���������� �������

void see_all_notes() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "��������� �� ����� ������� �����."<<endl;
		return;
	}
	string note_name,date,opisaniye,priority;
	cout << "\t\t��� ����:" << endl;
	for (int i = 1;!file.eof(); i+3)
	{
		getline(file, note_name);
		getline(file, priority);
		getline(file, opisaniye);
		getline(file, date);
		if (note_name.empty() and priority.empty() and opisaniye.empty() and date.empty())
			continue;
		cout << '[' << i << ']' << note_name << endl;
	}

	file.close();
}//�������� ���� ������� � �����

string* find_one_note(string& note_to_find, int& n_count) {
	ifstream file("notes.txt");
	if (!file.is_open())
	{
		cout<<"� ��� ��� �������. �������� ��!" << endl;
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
		cout << "���� �� ����� �������!"<<endl;
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
}//��� ������� ������ ������� ��� �������� ����� �� ���

void remove_one_note(string* all_notes_arr,int &count, int& choice) {
	ofstream file("notes.txt");
	if (!file.is_open())
	{
		cout << "������ ���� �� ����� ���� ������!";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < count; i++)
	{
		if (i==choice-1)
			continue;
		file << all_notes_arr[i] << endl;
	}

	file.close();
}//�������� ����� �������

void remove_all_notes() {
	fstream file("notes.txt", ios::out, ios::trunc);
	if (!file.is_open()) {
		cout << "������. ���� �� ������!";
		exit(EXIT_FAILURE);
	}
		
	file.close();
}//�������� ���� �������