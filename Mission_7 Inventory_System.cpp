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
     cout<<endl<<padding("Pushing Data to our System...")<<"Pushing Data to our System..."<<endl;
     sleep(2);
     Bottom_Line_2(Exit_Parts);
}

void DisplayInventory (vector <unique_ptr <string>> &Names, vector <unique_ptr <double>> &Prices, vector <unique_ptr <int>> &Quantities){
     Header("INVENTORY SYSTEM : SHOW INVENTORY");
     cout<<endl<<padding("Fetching the Inventory Items...")<<"Fetching the Inventory Items..."<<endl;
     sleep(2);
     if (ProductCount == 0) cout<<endl<<padding("No Items in Inventory...")<<"No Items in Inventory..."<<endl;
     else{
          string Table_line (77, '-'), text = format("|   {:<5}|   {:<35}|   {:<9}|   {:<11}|", "ID", "NAMES", "PRICES", "QUANTITY"), Table_Row_padding (static_cast <int> ((consoleWidth - text.size())/2) , ' ');
          cout<<endl<<endl<<Table_Row_padding<<Table_line<<endl;
          cout <<Table_Row_padding<<text<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
          for (int i = 0; i < ProductCount; i++)
               cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<9}|   {:<11}|", i+1, *Names[i], *Prices[i], *Quantities[i])<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
     }
}

void SellProduct (vector <unique_ptr <string>> &Names, vector <unique_ptr <double>> &Prices, vector <unique_ptr <int>> &Quantities){
     Header("INVENTORY SYSTEM : SELL INVENTORY ITEM");
     DisplayInventory(Names, Prices, Quantities);
     if (ProductCount != 0){
          int ProductId = 0;
          cout<<"\nEnter ID of Product to sell : "; cin>>ProductId;
          if (ProductId > 0 && ProductId <= ProductCount){
               int Quantity;
               cout<<"Enter Quantity of "<<*Names[ProductId - 1]<<" to sell : ";
               cin>>Quantity;
               if (Quantity <= 0) cout<<endl<<padding("Quantity can't be negative...")<<"Quantity can't be negative..."<<endl;
               else if (Quantity > *Quantities[ProductId - 1]) cout<<endl<<padding("Not enough Stock available for the selected Product...")<<"Not enough Stock available for the selected Product..."<<endl;
               else {
                    cout<<endl<<padding("Sold "+ to_string(Quantity)+ " "+ *Names[ProductId - 1]+"s.")<<"Sold "+ to_string(Quantity)+ " "+ *Names[ProductId - 1]+"s."<<endl;
                    *Quantities[ProductId - 1] -= Quantity;
                    if (*Quantities[ProductId - 1] == 0){
                         Names.erase(Names.begin()+ ProductId - 1);
                         Prices.erase(Prices.begin()+ ProductId - 1); 
                         Quantities.erase(Quantities.begin()+ ProductId - 1);
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
          vector <string> Menu {"INVENTORY SYSTEM", "Add Product to Inventory", "Display Inventory Items", "Sell Inventory Products", "Exit"};
          char choice = Main_Menu(Menu);
          switch (choice){
               case 'A':
                    AddProduct(Names, Prices, Quantities);
                    break;
               case 'B':
                    DisplayInventory(Names, Prices, Quantities);
                    Bottom_Line_2(Exit_Parts);
                    break;
               case 'C':
                    SellProduct(Names, Prices, Quantities);
                    break;
               case 'D':{
                    array <string, 2> Exit_Parts {"BANK MANAGER", "Bank Management System"};
                    Exiting_Window(Exit_Parts);
                    break;
               }
               default:
                    cout<<padding("Enter a valid request...")<<"Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}