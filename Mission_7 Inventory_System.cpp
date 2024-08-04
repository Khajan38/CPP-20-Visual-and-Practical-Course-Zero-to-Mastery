// Mission 7: Inventory System

/* OVERVIEW:
This C++ program simulates a basic inventory management system. It allows users to add products to the inventory, display the current inventory, and sell products from the inventory. The program uses dynamic memory management with smart pointers to handle product details.

DEPENDENCIES:
   -> Standard Libraries: <iostream>, <memory>, <format>
   -> Custom Header Files:
        * "Display_Basics.hpp"

VARIABLES:
   -> int ProductCount {0}
        * Keeps track of the number of products in the inventory.
   -> array <string, 2> Exit_Parts {"INVENTORY SYSTEM", "Inventory System"}
        * Used for the exit screen display.

FUNCTIONS:
   -> void AddProduct(vector <unique_ptr <string>> &Names, vector <unique_ptr <double>> &Prices, vector <unique_ptr <int>> &Quantities):
        * Prompts the user to enter product details (name, price, and quantity).
        * Creates unique pointers for each product detail and adds them to their respective vectors.
        * Increments the `ProductCount`.

   -> void DisplayInventory(vector <unique_ptr <string>> &Names, vector <unique_ptr <double>> &Prices, vector <unique_ptr <int>> &Quantities):
        * Displays the current inventory in a tabular format.
        * Shows product ID, name, price, and quantity.
        * Handles cases where the inventory is empty.

   -> void SellProduct(vector <unique_ptr <string>> &Names, vector <unique_ptr <double>> &Prices, vector <unique_ptr <int>> &Quantities):
        * Displays the inventory and prompts the user to select a product ID to sell.
        * Checks if the selected quantity is valid and available.
        * Updates the quantity of the sold product and removes it from the inventory if the quantity reaches zero.

WORKING :
   -> Main loop that displays the menu and handles user choices.
   -> Calls `AddProduct`, `DisplayInventory`, or `SellProduct` based on the user's choice.
   -> Provides options to exit the program.

TEMPLATES FOR ALL PAGES : Provided by "Display_Basics.hpp" which includes various function methods for Page Templates. These include:
   -> Headings: "Display_Basics.hpp -> Header()"
   -> Word Padding to center: "Display_Basics.hpp -> padding [] () {}"
   -> Footers and Bottom Lines: "Display_Basics.hpp -> Bottom_Line(), Bottom_Line_2()"
   -> Main Menus: "Display_Basics.hpp -> Main_Menu()"
   -> Exit Window: "Display_Basics.hpp -> Exiting_Window()"

USAGE : The user interacts with the program through a menu to:
   1. Add Product to Inventory: Input details of a new product to add to the inventory.
   2. Display Inventory Items: View the current list of products in the inventory.
   3. Sell Inventory Products: Sell a specified quantity of a product and update the inventory.
   4. Exit: Exit the program.*/

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