/*A*/
#pragma once
#include <iostream>
#include <memory>
#include "Function Header Files.hpp"
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
                    if (Password == Name){Bottom_Line(0); Current_MemberId = MemberId; return 'M';}
                    else {
                         cout<<endl<<padding("Wrong Password Entered...")<<"Wrong Password Entered...";
                         cout<<endl; printline;
                         cout<<padding("Enter L to go to Login Again or any other key to exit : ")<<"Enter L to go to Login Again or any other key to exit : ";
                         cin>>Password; 
                         if (Password != "L") Exiting_Window(Exit_Parts);
                    }
               }
               else if (MemberId == 0 && Password == "Librarian's Hub Director"){Bottom_Line(0); return 'D';}
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
     vector <string> Menu_Items = {"LIBRARIAN'S HUB - MEMBER", "Borrow Books from Library", "Return Book to Library", "Display Borrowed Books", "See Membership Card", "Exit"};
     while (true){   
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
void Director_Menu(void){}