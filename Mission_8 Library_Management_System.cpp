//Mission 8 : Inventory System

/*Main File for the whole Library Management System from where other Header Files and fucntion sare called. This contains the login page that tells weather you are a Library Director or a Library Member. Based on this it launches various operations that a Master or Member can perform.*/

#include <iostream>
#include "Library-Management-System\Main Header File.hpp"
#include "Display_Basics.hpp"
using namespace std;

int main(){
     //Checking if you are master or client
     Library L;
     char Access_Type = Login_Page(L.getMembers());
     if (Access_Type == 'M') Member_Menu (Access_Type, L.getMembers(), L.getBooks());
     else if (Access_Type == 'D') cout<<"Directors"<<Library::getmember_count(); Director_Menu ();
     return 0;
}