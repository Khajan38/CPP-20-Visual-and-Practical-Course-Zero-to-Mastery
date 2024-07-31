//Mission 7 : Inventory System

#include <iostream>
#include <memory>
#include <format>
#include "Display_Basics.hpp"
using namespace std;

int ProductCount {0};
array <string, 2> Exit_Parts {"INVENTORY SYSTEM", "Inventory System"};

void AddProduct (vector <unique_ptr <string>> &Names, vector <unique_ptr <double>> &Prices, vector <unique_ptr <int>> &Quantities){
     Header("INVENTORY SYSTEM : ADD TO INVENTORY");
     unique_ptr <string> Name {make_unique <string> ()};
     unique_ptr <double> Price {make_unique <double> ()};
     unique_ptr <int> Quantity {make_unique <int> ()};
     cout<<"\nEnter Product Name : "; cin>>*Name;
     cout<<"Enter Product Price  : "; cin>>*Price;
     cout<<"Enter Product Quantity : "; cin>>*Quantity;
     Names.push_back(move(Name));
     Prices.push_back(move(Price));
     Quantities.push_back(move(Quantity));
     ProductCount++;
     cout<<endl<<padding("Pushing Data to our System")<<"Pushing Data to our System"<<endl;
     sleep(2);
     Bottom_Line_2(Exit_Parts);
}

void DisplayInventory (vector <unique_ptr <string>> Names, vector <unique_ptr <double>> Prices, vector <unique_ptr <int>> Quantities){
     Header("INVENTORY SYSTEM : SHOW INVENTORY");
     cout<<endl<<padding("Fetching the Inventory Items...")<<"Fetching the Inventory Items..."<<endl;
     sleep(2); string Table_line (80, '-'); 
     if (ProductCount == 0) cout<<endl<<padding("No Items in Inventory...")<<"No Items in Inventory..."<<endl;
     else{
          cout<<endl<<Table_line<<endl;
          cout<<format("|   ID   |   {:<35}   |   PRICES   |   QUANTITY   |", "NAME")<<endl;
          cout<<Table_line<<endl<<endl;
          for (int i = 0; i < ProductCount; i++)
               cout<<format("|   {:<5}|   {:<35}   |   {:<9}|   {:<11}|", i+1, *Names[i], *Prices[i], *Quantities[i])<<endl;
          cout<<Table_line<<endl;
     }
     Bottom_Line_2(Exit_Parts);
}

void SellProduct (vector <unique_ptr <string>> Names, vector <unique_ptr <double>> Prices, vector <unique_ptr <int>> Quantities){
     Header("INVENTORY SYSTEM : SELL INVENTORY ITEM");
     DisplayInventory(Names, Prices, Quantities);
     if (ProductCount != 0){
          int ProductId = 0;
          cout<<"\nEnter ID of Product to sell : "; cin>>ProductId;
          if (ProductId > 0 && ProductId <= ProductCount){
               int Quantity;
               cout<<"Enter Quantity of "<<*Names[ProductCount - 1]<<"to sell : ";
               cin>>Quantity;
               if (Quantity <= 0) cout<<endl<<padding("Quantity can't be negative...")<<"Quantity can't be negative..."<<endl;
               else if (Quantity > *Quantities[ProductCount - 1]) cout<<endl<<padding("Not enough Stock available for the selected Product...")<<"Not enough Stock available for the selected Product..."<<endl;
               else {
                    cout<<endl<<padding("Sold "+ to_string(*Quantities[ProductCount - 1])+ " "+ *Names[ProductCount - 1]+"s.")<<"Sold "+ to_string(*Quantities[ProductCount - 1])+ " "+ *Names[ProductCount - 1]+"s."<<endl;
                    *Quantities[ProductCount - 1] -= Quantity;
                    if (Quantities[ProductCount - 1] == 0){
                         vector <string> :: iterator itr_Names {Names.begin()+3};
                         Names.erase(itr_Names);
                         ProductCount--;
                    }
               }
          }
          else
               cout<<endl<<padding("Enter Valid Product ID...")<<"Enter Valid Product ID..."<<endl;
     }
     Bottom_Line_2(Exit_Parts);
}

int main(){
     vector <unique_ptr <string>> Names ;
     vector <unique_ptr <double>> Prices; 
     vector <unique_ptr <int>> Quantities;
     while (true){
          vector <string> Menu {"INVENTORY SYSTEM : MAIN MENU", "Deposit Money", "Withdraw Money", "Check Bank Balance", "Exit"};
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