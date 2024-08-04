//Mission 8 : Inventory System

/*OVERVIEW :  
This is the main file for the Library Management System. It serves as the entry point for the application, handling the login page to determine whether the user is a Library Director or a Library Member. Based on the user's role, it launches different operations that the Director or Member can perform.

DEPENDENCIES : 
   -> Standard Libraries: <iostream>
   -> Custom Header Files:
        * "Library-Management-System\Main Header File.hpp"
        * "Display_Basics.hpp"

FUNCTIONALITY : 
   ->Role Determination: The program begins by determining the user's role (Director or Member) through the Login_Page function.

   ->Menu Navigation:
        * Member: If the user is identified as a Member (Access_Type == 'M'), the Member_Menu function is called to provide member-specific operations.
        * Director: If the user is identified as a Director (Access_Type == 'D'), the Director_Menu function is called to provide director-specific operations.

   -> Library Object: An object of the Library class, L, is created to manage the members and books within the system.*/

#include <iostream>
#include "Library-Management-System\Main Header File.hpp"
#include "Display_Basics.hpp"
using namespace std;

int main(){
     //Checking if you are master or client
     Library L;
     char Access_Type = Login_Page(L.getMembers());
     if (Access_Type == 'M') Member_Menu (Access_Type, L.getMembers(), L.getBooks());
     else if (Access_Type == 'D') Director_Menu (Access_Type, L, L.getMembers(), L.getBooks());
     return 0;
}