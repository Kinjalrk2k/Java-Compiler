#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include "menu_creator.cpp"
#define size 256

using namespace std;

int main()
{
    position str;
	str.x=1;
	str.y=2;

	int no_items=6;
	char menu_items[no_items][260]={"Create New JAVA Project","Set FileName","Compile","Run","Edit in Notepad","Exit"};
	int menu_id;

	while(1)
    {
        system("cls");

        cout<<"LIGHT-WEIGHT JAVA COMPILER";

        menu_id=menu(str, menu_items, no_items);

        switch(menu_id)
        {
        case 0:
            {
                fstream f;
                f.open("filename.txt", ios::out | ios::trunc);
                char appname[size];

                cout<<endl<<"Enter New FileName: ";
                cin>>appname;

                f<<appname;

                cout<<endl<<"New JAVA Project created successfully";

                f.close();
            }
            break;

        case 1:
            {
                fstream f;
                f.open("filename.txt", ios::out | ios::trunc);
                char appname[size];

                cout<<endl<<"Enter New FileName: ";
                cin>>appname;

                f<<appname;

                cout<<endl<<"New FileName set successfully";

                f.close();
            }
            break;

        case 2:
            {
                cout<<endl<<"Compiling Processes initiated..."<<endl<<endl;
                char appname[size];

                fstream f;
                f.open("filename.txt");
                f>>appname;

                system("set path=C:\\Program Files\\Java\\jdk-10.0.1\bin;");
                char compile[size]="javac ";

                strcat(appname, ".java");
                strcat(compile, appname);

                system(compile);

                f.close();

                cout<<endl<<"Compiling Processes ended... Press RETURN to continue...";
                _getch();

            }
            break;

        case 3:
            {
                cout<<endl;
                cout<<"Running:"<<endl<<endl;

                char appname[256];

                fstream f;
                f.open("filename.txt");
                f>>appname;

                system("set path=C:\\Program Files\\Java\\jdk-10.0.1\bin;");
                char compile[256]="java ";

                strcat(compile, appname);

                system(compile);

                f.close();

                cout<<endl<<"Program ended... Press RETURN to continue...";
                _getch();
            }
            break;

        case 4:
            {
                char appname[size];

                fstream f;
                f.open("filename.txt");
                f>>appname;

                char notepad[size]="notepad.exe ";

                strcat(appname, ".java");
                strcat(notepad, appname);

                system(notepad);

                f.close();
            }
            break;

        case 5:
            exit(0);

        }
    }

}
