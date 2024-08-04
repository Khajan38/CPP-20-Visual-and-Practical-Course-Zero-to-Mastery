//Mission 4 : Bank Management System

/*OVERVIEW : 
This C++ program simulates a simple bank management system where users can deposit money, withdraw money, check their bank balance, or exit the system. It manages a single account with an initial balance and provides basic banking operations.

DEPENDENCIES : 
   -> Standard Libraries: <iostream>
   -> Custom Header Files:
        * "Display_Basics.hpp"

VARIABLES:
   -> float Balance {1000.0}
   -> array <string, 2> Exit_Parts {"BANK MANAGER", "Bank Management System"}
   -> vector <string> Menu {"BANK MANAGER : MAIN MENU", "Deposit Money", "Withdraw Money", "Check Bank Balance", "Exit"};

TEMPLATES FOR ALL PAGES : Provided by "Display_Basics.hpp" which includes various function methods for Page Templates. These include-
  -> Headings : "Display_Basics.hpp -> Header()"
  -> Word Padding to center : "Display_Basics.hpp -> padding [] () {}"
  -> Footers and Bottom Lines : "Display_Basics.hpp -> Bottom_Line(), Bottom_Line_2()"
  -> Main Menus : "Display_Basics.hpp -> Main_Menu()"
  -> Exit Window : "Display_Basics.hpp -> Exiting_Window()"

MENU CHOICES :
   -> Deposit Money (Case 'A') :
        * Displays the deposit window and prompts for an amount to deposit.
        * Validates and processes the deposit, updating the balance accordingly.
        * Displays success or error messages based on input.

   -> Withdraw Money (Case 'B') :
        * Displays the withdrawal window and prompts for an amount to withdraw.
        * Validates the withdrawal amount and checks for sufficient balance.
        * Updates the balance and displays appropriate messages.

   -> Check Balance (Case 'C') :
        * Displays the current balance of the account.
        * Exit (Case 'D'):

   -> Calls Exiting_Window(Exit_Parts) : 
        * to handle exit operations and terminate the program.

USEAGE : The user interacts with the program through a menu to:
   1. Deposit Money: Input the amount to deposit into the account.
   2. Withdraw Money: Input the amount to withdraw from the account, ensuring sufficient balance.
   3. Check Bank Balance: View the current balance of the account.
   4. Exit: Exit the program.*/

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