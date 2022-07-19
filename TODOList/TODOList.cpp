#include <windows.h>
#include <iostream>
#include "Functions.h"
using namespace std;
int main(){
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Welcom to my programm.\nThis is TO DO LIST." << endl << endl;
    show_menu();
    bool x = 1;
    int choice;
    while (x != 0) {
        system("cls");
        show_menu();
        cout << endl<<"Input number to do:";
        cin >> choice;
        if (choice==1) {

        }
        else if (choice == 2) {
            
        }
        else if (choice == 3) {
            
        }
        else if (choice == 4) {
            
        }
        else if (choice == 5) {
            
        }
        else if (choice == 6) {
            
        }
        else if (choice == 7) {
            
        }
        else if (choice==8) {
            cout << "Are you shure? All do deletes!\nIf you shure input 1,else 0";
            bool f=0;
            if (f == 0) {

            }
            else {
                x = 0;
            }
            
        }
        else
            cout << "ERROR!";
        cout << endl;
        system("pause");
    }
    {
        SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Good buy\n";
        SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        Sleep(2000);
    }
    //good buy to red color


}
