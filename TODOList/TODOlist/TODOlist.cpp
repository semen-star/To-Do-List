#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Functions.h"
using namespace std;

enum CHOICE {
   SEE_ALL_NOTES=1,
   ADD_NOTE,
   DELETE_ONE_NOTE,
   DELETE_ALL_NOTES,
   FIND_NOTE,
   EDIT,
   EXIT
};

int main()
{
    setlocale(LC_ALL, ""); 
    SetConsoleCP(1251);
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice = 0;
    cout << "Внимание! Дела хранятся в памяти.\n\nУ всех дел есть несколько критериев. Спасибо за использование.\n\nP.s. Автор приколист.";
    Sleep(5000);
    bool x = 1;
    int z=1;
    system("cls");
    while (x != 0) {
        system("cls");
        show_menu();
        cout << endl << "Сделайте выбор:";
        cin >> choice;
        if (choice == ADD_NOTE) {
            system("cls");
            add_note();
            cout << endl << endl;
            system("pause");
            system("cls");
        }
        else if (choice == SEE_ALL_NOTES) {
            system("cls");
            see_do();
            cout << endl << endl;
            system("pause");
            system("cls");
        }
        else if (choice == FIND_NOTE) {
            system("cls");
            string note_to_find;
            cout << "ВНИМАНИЕ! Введите только одно слово для поиска!"<<endl;
            getline(cin, note_to_find);
            cout << "Слово для поиска:";
            getline(cin, note_to_find);
            int n_found = 0;
            string* found_notes = find_one_note(note_to_find, n_found);
            if (found_notes)
            {
                cout << "Найденые заметки:"<<endl;
                for (int i = 0; i < n_found; i++) 
                    cout << found_notes[i] << endl;   
                delete[] found_notes;
                cout << endl;
            }
            else
                cout << "Извините, я не нашёл нужных заметок." << endl;

            system("pause");
        }
        else if (choice == DELETE_ONE_NOTE) {
            system("cls");
            int count = 0;
            string* all_notes_arr = all_notes(count);
            cout << "ВНИМАНИЕ! ВЫБИРАЙТЕ ПО ИМЕНИ ВАШЕ ДЕЛО И ВВОДИТЕ НОМЕР ИМЕНИ!!!" << endl;
            Sleep(3000);
            cout << "Выберите заметку для удаления:" << endl;
            for (int i = 0; i < count; i ++) {
                cout << "["<<i+1<<"]" << all_notes_arr[i] << endl;
            }
            cout << "Ввод:";
            int choice = 0;
            cin >> choice;
            choice -= 1;
            remove_one_note(all_notes_arr, count, choice);
            delete[] all_notes_arr;
            system("pause");
        }
        else if (choice == DELETE_ALL_NOTES) {
            system("cls");
            remove_all_notes();
            cout << "Все заметки удалены." << endl;
            system("pause");
            system("cls");
        }
        else if (choice == EDIT) {
            system("cls");
            editing();
            system("pause");
            system("cls");
        }
        else if (choice == EXIT) {
            cout << "Are you shure? All affairs SAVE!\nif you are sure, then enter 1. Or enter 0\n\nInput:";
            bool f = 0;
            cin >> f;
            if (f == 0) {
                continue;
            }
            else {
                x = 0;
            }
        }

        else {
            cout << "ERROR!";
            cout << endl;
            system("pause");
        }
        
        }
        {
            SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Good buy\n";
            SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            Sleep(2000);
        }
        //good buy to red color
        
        return 0;
    }