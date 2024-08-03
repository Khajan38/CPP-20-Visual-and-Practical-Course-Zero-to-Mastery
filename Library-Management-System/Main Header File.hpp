//Main Header File.hpp

/*OVERVIEW : 
This file serves as a central header and contains the main functionalities for the Library Management System, including the login mechanism and main menus for both members and directors. It provides functions for navigating between different sections of the application based on the user's role.

DEPENDENCIES : 
   -> Standard Libraries: <iostream>, <memory>
   -> Custom Header Files:
        * "Member Functions File.hpp"
        * "Display_Basics.hpp"
   -> GLOBAL VARIABLES
        * int Current_MemberId: A variable used to store the ID of the currently logged-in member.

FUNCTIONS : 
   -> char Login_Page(vector<unique_ptr<Member>> &Members):
        * Manages the login process for both members and directors.
        * Prompts the user to enter their Member ID, Name, and Password.
        * Validates the credentials against the list of members.
        * Returns 'M' for a member or 'D' for a director based on the login credentials.

   -> void Member_Menu(char Access_Type, vector<unique_ptr<Member>> &Members, vector<unique_ptr<Book>> &Books):
        * Provides a menu for library members with options to borrow books, return books, display borrowed books, view membership cards, or exit.
        * Calls appropriate functions based on the user's choice.

   -> void Director_Menu(char Access_Type, Library &L, vector<unique_ptr<Member>> &Members, vector<unique_ptr<Book>> &Books):
        * Provides a menu for library directors with options to display all books, display all members, add new books, delete books, add new members, delete members, or exit.
        * Manages the high-level operations of the library system, including adding and removing books and members.*/

#pragma once
#include <iostream>
#include <memory>
#include "Member Functions File.hpp"
#include "../Display_Basics.hpp"
using namespace std;

int Current_MemberId = 1325;

char Login_Page (vector <unique_ptr <Member>> &Members){
     //Checking if you are master or client
     int MemberId; string Name, Password;
     while (true){
          Header("LIBRARIAN'S HUB : LOGIN PAGE");
          cout<<"\nEnter your Member ID : "; cin>>MemberId;
          cin.ignore(INT_MAX, '\n');
          cout<<"Enter your Name : "; getline(cin, Name);
          cout<<"Enter Password : "; getline(cin, Password); 
          Member Check_Member (Name, MemberId);
          /*Password to open your Member Window is your Name with Initials matching in member list
          While for Director Window MemberId = 0, Name = {Your_Name} and Password is - "Librarian's Hub Director"*/
          for (auto & Mem : Members){
               if (MemberId == (Check_Member == *Mem)){
                    if (Password == Name){
                         cout<<endl<<padding("Fetching Permissions")<<"Fetching Permissions";
                         Bottom_Line(0); Current_MemberId = MemberId; 
                         return 'M';
                    }
                    else {
                         cout<<endl<<padding("Wrong Password Entered...")<<"Wrong Password Entered...";
                         cout<<endl; printline;
                         cout<<padding("Enter L to go to Login Again or any other key to exit : ")<<"Enter L to go to Login Again or any other key to exit : ";
                         cin>>Password; 
                         if (Password != "L") Exiting_Window(Exit_Parts);
                    }
               }
               else if (MemberId == 0 && Password == "Librarian's Hub Director"){
                    cout<<endl<<padding("Fetching Permissions")<<"Fetching Permissions";
                    Bottom_Line(0); return 'D';
               }
          }
          if (Password != "L"){
               cout<<endl<<padding("Wrong Information Entered...")<<"Wrong Information Entered..."<<endl; printline;
               cout<<padding("Enter L to go to Login Again or any other key to exit : ")<<"Enter L to go to Login Again or any other key to exit : ";
               cin>>Password; 
               if (Password != "L") Exiting_Window(Exit_Parts);
          }
     }
     return '\0';
}

void Member_Menu(char Access_Type, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books){
     while (true){
          vector <string> Menu_Items = {"LIBRARIAN'S HUB - MEMBER", "Borrow Books from Library", "Return Book to Library", "Display Borrowed Books", "See Membership Card", "Exit"};
          char menu_choice = Main_Menu(Menu_Items);
          switch (menu_choice){
               case 'A':
                    Borrow_Book(Access_Type, Members[Current_MemberId - 1326], Members, Books);
                    break;
               case 'B':
                    Return_Book(Members[Current_MemberId - 1326], Books);
                    break;
               case 'C':
                    Borrowed_Books(Members[Current_MemberId - 1326], Books);
                    Bottom_Line_2(Exit_Parts);
                    break;
               case 'D':
                    Membership_Card(Members[Current_MemberId - 1326]);
                    break;
               case 'E':
                    Exiting_Window(Exit_Parts);
                    break;
               default:
                    cout<<padding("Enter a valid request...")<<"Enter a valid request...";
                    sleep(2);
          }
     }
}

void Director_Menu(char Access_Type, Library &L, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books){
     while (true){
          vector <string> Menu_Items = {"LIBRARIAN'S HUB - DIRECTOR", "Display all Books", "Display all Members", "Add New Book to the Library", "Delete Book from Library", "Add new Member to the Library", "Delete Member from Library", "Exit"};
          char menu_choice = Main_Menu(Menu_Items);
          switch (menu_choice){
               case 'A':
                    L.DisplayBooks(Access_Type);
                    break;
               case 'B':
                    L.DisplayMembers(Access_Type);
                    break;
               case 'C':
                    L.AddBook();
                    break;
               case 'D':
                    L.RemoveBook(Access_Type);
                    break;
               case 'E':
                    L.AddMember();
                    break;
               case 'F':
                    L.RemoveMember(Access_Type);
                    break;
               case 'G':
                    Exiting_Window(Exit_Parts);
                    break;
               default:
                    cout<<padding("Enter a valid request...")<<"Enter a valid request...";
                    sleep(2);
          }
     }
}