#pragma once
#include <string>
#include <iostream>
using namespace std;

void show_menu();//����� ����

void add_note();//���������� ����
void see_to_day();
void see_to_mounth();
void see_all_notes();
void see_priority_notes();
void see_do();//�������� ��� ����

string* find_one_note(string&note_to_find, int &n_count);//����� ����

string* all_notes(int &count);//���������� ��� �������� ������ ����

void remove_one_note(string* all_notes_arr, int &count,int& choice);//�������� ������ ����

void remove_all_notes();//�������� ���� ���

void editing();//�������������� ����