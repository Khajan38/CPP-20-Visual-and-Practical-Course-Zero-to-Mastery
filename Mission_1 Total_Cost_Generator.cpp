//Mission 1 : Make a Total_Cost_Generator

/*OVERVIEW : 
This program calculates the total cost of an item purchase, including sales tax. The user is prompted to enter the quantity and price of an item, and the program computes the subtotal, sales tax, and total cost.

DEPENDENCIES :
   -> Standard Library Headers: <iostream>

CONSTANTS AND VARIABLES:
   -> float SALES_TAX_RATE {0.08}
   -> float Price
   -> int Quantity

USER INPUT : Prompts the user to enter the quantity and price of the items.

CALCULATIONS:
   -> Subtotal: Calculates the subtotal by multiplying the Quantity by the Price.
   -> Sales Tax: Calculates the sales tax by applying the SALES_TAX_RATE to the Subtotal.
   -> Total Cost: Calculates the total cost by adding the SalesTax to the Subtotal.

OUTPUT: Displays the calculated Subtotal, Sales Tax, and Total Cost to the user.

USEAGE : When the program runs, the user is prompted to enter the quantity and price of the items. The program then outputs the subtotal, sales tax, and total cost, providing a detailed breakdown of the costs.*/

#include <iostream>
using namespace std;
int main(){
     float SALES_TAX_RATE {0.08}, Price;
     int Quantity;
     std::cout<<"\nEnter the quantity : "; std::cin>>Quantity;
     cout<<"Enter the price : "; cin>>Price;
     auto Subtotal = Quantity * Price;
     float SalesTax = Subtotal * SALES_TAX_RATE;
     float TotalCost = Subtotal + SalesTax;
     cout<<"\nSubtotal : "<<Subtotal
         <<", Sales Tax : "<<SalesTax
         <<", Total Cost : "<<TotalCost<<endl;
     return 0;
}
