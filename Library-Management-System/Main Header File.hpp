/*A*/
#pragma once
#include <iostream>
#include <memory>
#include "Classes Declaration File.hpp"
#include "../Display_Basics.hpp"
using namespace std;

array <string, 2> Exit_Parts = {"LIBRARIAN'S HUB", "Librarian's Hub"};

char Login_Page (vector <unique_ptr <Member>> &Members){
     //Checking if you are master or client
     int MemberId; string Name, Password;
     Header("LIBRARIAN'S HUB : LOGIN PAGE");
     cout<<"\nEnter your Member ID : "; cin>>MemberId;
     cin.ignore(INT_MAX, '\n');
     cout<<"Enter your Name : "; getline(cin, Name);
     cin.ignore(INT_MAX, '\n');
     cout<<"Enter Password : "; getline(cin, Password); 
     Member Check_Member (Name, MemberId);
     /*Password to open your Member Window is your Name with Initials matching in member list
     While for Director Window MemberId = 0, Name = {Your_Name} and Password is - "Librarian's Hub Director"*/
     for (auto & Mem : Members){
          if (Check_Member == *Mem){ 
               if (Password == Name) return 'M';
               else {
                    cout<<endl<<padding("Wrong Password Entered...")<<"Wrong Password Entered...";
                    cout<<endl; printline;
                    cout<<padding("Enter L to go to Login Again or any other key to exit : ")<<"Enter L to go to Login Again or any other key to exit : ";
                    cin>>Password; 
                    if (Password != "L") Exiting_Window(Exit_Parts);
               }
          }
          else if (MemberId == 0 && Password == "Librarian's Hub Director") return 'D';
     }
     return 0;
}