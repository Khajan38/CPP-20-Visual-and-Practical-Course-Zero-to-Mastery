/*OVERVIEW : 
This file provides utility functions and macros for a console-based application, likely a menu-driven system, with functions for display formatting, menu navigation, and program flow control. It includes functionalities such as drawing lines, clearing the screen, and displaying headers and footers.

DEPENDENCIES :
   -> Standard Libraries: <iostream>, <vector>, <array>, <thread>, <chrono>
   -> Windows API: <windows.h>

MACROS AND LAMBDA FUNCTIONS : 
   -> printline: Macro to print a line of equal signs (=) based on the console width.
   -> sleep(timed): Macro to pause the execution for a specified number of seconds.
   -> clear_screen: Macro to clear the console screen.
   -> line: Lambda function that returns a string of equal signs based on the console width.
   -> padding(text): Lambda function to calculate padding for center-aligning text based on console width.

FUNCTIONS : 
   -> getConsoleWidth(): Returns the width of the console window in characters.

   -> Header(string Heading): Clears the screen and prints the provided heading text, centered, with a line above and below.

   -> Bottom_Line(int page): Prints different messages based on the page value. Used for transitions like "Continuing..." or "Initiating your request...".

   -> Bottom_Line_2(array<string, 2> &Exit_Parts): Provides an option to return to the main menu or exit the application. If the user chooses to exit, it calls Exiting_Window.

   -> Entrance_Window(char restart_choice, array<string, 3> &Entrance_Parts): Displays the entrance window with a header and the specified messages. It also waits for user input to proceed.

   -> Main_Menu(vector<string> &Menu_items): Displays a list of menu items and prompts the user to select one. Returns the user's choice.
   
   -> Exiting_Window(array<string, 2> &Exit_Parts): Displays a thank-you message and exits the application gracefully.*/

#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
#include <array>
#include <thread>
#include <chrono>
using namespace std;

int getConsoleWidth() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    return consoleInfo.dwSize.X;
}
int consoleWidth = getConsoleWidth();

auto line = [](){string line (consoleWidth, '='); return line;}; //lambda fucntion for line
#define printline cout<<endl<<line()<<endl<<endl
#define sleep(timed) this_thread::sleep_for (chrono::seconds(timed))
#define clear_screen system("cls")

auto padding = [](string text) {
     string paddingWidth(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
     return paddingWidth;
}; //lambda function for text padding

void Exiting_Window (array <string, 2> &Exit_Parts);

void Header (string Heading){
     clear_screen; printline;
     cout<<padding(Heading)<<Heading<<endl; printline;
}

void Bottom_Line (int page){
     if (page == 0){ //Necessary for Entrance Window
          cout<<"\n\n"; printline;
          cout <<padding("Continuing")<<"Continuing..."<<endl;
          sleep(2);
          return;
     }
     else if (page == 1){ //Necessary for Main_Menu
          printline;
          cout<<padding("Initiating your request...")<<"Initiating your request...";
          sleep(2);
          return;
     }
}
void Bottom_Line_2 (array <string, 2> &Exit_Parts){ //Necessary for Bottom of Page
     printline;
     char menu_choice;
     cout<<padding("Enter M to go to Main Menu or any other key to exit : ")<<"Enter M to go to Main Menu or any other key to exit : ";
     cin>>menu_choice;
     if (menu_choice != 'M') {
          array <string, 2> Exit_Parts {"BANK MANAGER", "Bank Management System"};
          Exiting_Window(Exit_Parts);
     }
     return;
}

void Entrance_Window (char restart_choice, array <string, 3> &Entrance_Parts){
     Header(Entrance_Parts[0]);
     cout<<endl<<endl<<padding(Entrance_Parts[1])<<Entrance_Parts[1]
         <<endl<<endl<<endl<<padding(Entrance_Parts[2])<<"\b\b\b\b"<<Entrance_Parts[2];
     if (restart_choice == 'R') cin.ignore(INT_MAX, '\n');
     cin.get();
     Bottom_Line(0);
}

int Main_Menu (vector <string> &Menu_items){
     Header(Menu_items[0] + ": MAIN MENU"); 
     Menu_items.erase(Menu_items.begin());
     string Menu_items_padding (50, ' '); char Menu_items_count = 'A';
     for (auto i : Menu_items){
          cout<<"\n"<<Menu_items_padding<<Menu_items_count<<". "<<i;
          Menu_items_count++;
     }
     cout<<"\n\nEnter your choice : ";
     char choice; cin>>choice;
     if (choice >= 'A' && choice < Menu_items_count) Bottom_Line(1);
     return choice;
}

void Exiting_Window (array <string, 2> &Exit_Parts){
     Header(Exit_Parts[0] + ": EXIT WINDOW");
     cout<<padding("Thank You!")<<"Thank You!"<<endl<<endl
         <<padding("for using "+Exit_Parts[1])<<"\bfor using "+Exit_Parts[1]+"..."<<endl<<endl<<endl
         <<padding("WE WILL WAIT FOR YOU!...")<<"WE WILL WAIT FOR YOU!..."<<endl<<endl;
     printline; sleep(3);
     system("cls");
     exit(0);
}