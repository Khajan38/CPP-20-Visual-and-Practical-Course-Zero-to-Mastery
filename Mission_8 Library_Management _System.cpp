//Mission 8 : Inventory System

/*Main File for the whole Library Management System from where other Header Files and fucntion sare called. This contains the login page that tells weather you are a Library Director or a Library Member. Based on this it launches various operations that a Master or Member can perform.*/

#include <iostream>
#include "Library-Management-System\Main Header File.hpp"
#include "Display_Basics.hpp"
using namespace std;

int main(){
     //Checking if you are master or client
     Library L;
     char c = Login_Page(L.getMembers());
     if (c == 'M') Member_Menu ();
     else if (c == 'D') Director_Menu ();
     return 0;
}