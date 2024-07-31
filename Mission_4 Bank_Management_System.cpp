//Mission 4 : Bank Management System

#include <iostream>
#include "Display_Basics.hpp"
using namespace std;

int main(){
     float Balance {1000.0};
     array <string, 2> Exit_Parts {"BANK MANAGER", "Bank Management System"};
     while (true){
          vector <string> Menu {"BANK MANAGER : MAIN MENU", "Deposit Money", "Withdraw Money", "Check Bank Balance", "Exit"};
          char choice = Main_Menu(Menu);
          switch (choice){
               case 'A':{
                    Header("BANK MANAGER : DEPOSIT WINDOW");
                    float Deposit_Amount {0};
                    cout<<"\nEnter Amount to be Deposited (in Rupeees) : ";
                    cin>>Deposit_Amount;
                    if (Deposit_Amount > 0){
                         Balance += Deposit_Amount;
                         cout<<padding("Deposited...")<<"Deposited..."<<endl;
                    }
                    else 
                         cout<<padding("Invalid Deposit amount...")<<"Invalid Deposit amount..."<<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'B':{
                    Header("BANK MANAGER : WITHDRAW WINDOW");
                    float Withdraw_Amount {0};
                    cout<<"\nEnter Amount to be Withdrawn (in Rupeees) : ";
                    cin>>Withdraw_Amount;
                    if (Withdraw_Amount > 0 && Withdraw_Amount <= Balance){
                         Balance += Withdraw_Amount;
                         cout<<padding("Withdraw Successful...")<<"Withdraw Successful..."<<endl;
                    }
                    else 
                         if (Withdraw_Amount > Balance)
                              cout<<padding("Insufficient Balance...")<<"Insufficient Balance..."<<endl;
                         else 
                              cout<<padding("Enter valid amount...")<<"Enter valid amount..."<<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'C':
                    Header("BANK MANAGER : WITHDRAW WINDOW");
                    cout<<padding("Fetching the Tasks Details...")<<"Fetching the Tasks Details...";
                    sleep(2);
                    cout<<"\n\nYou Current Balance is : "<<Balance<<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               case 'D':{
                    array <string, 2> Exit_Parts {"BANK MANAGER", "Bank Management System"};
                    Exiting_Window(Exit_Parts);
               }
               default:
                    cout<<padding("Enter a valid request...")<<"Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}