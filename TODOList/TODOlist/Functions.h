#pragma once
#include <string>
#include <iostream>
using namespace std;

void show_menu();//Вывод меню

void add_note( string & new_note);//добавление заметки

void see_all_notes();//Показать все заметки

string* find_one_note(string&note_to_find, int &n_count);//найти заметку

string* all_notes(int &count);

void remove_one_note(string* all_notes_arr, int &count,int& choice);

void remove_all_notes();