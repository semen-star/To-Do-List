#pragma once
#include <string>
#include <iostream>
using namespace std;

void show_menu();//Вывод меню

void add_note();//добавление дела

void see_do();//Показать все дела

string* find_one_note(string&note_to_find, int &n_count);//найти дело

string* all_notes(int &count);//дополнение для удаления одного дела

void remove_one_note(string* all_notes_arr, int &count,int& choice);//удаление одного дела

void remove_all_notes();//удаление всех дел

void editing();//редактирование дела