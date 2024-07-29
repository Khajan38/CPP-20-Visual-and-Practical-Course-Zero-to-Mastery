//Mission 1 : Make a Total_Cost_Generator

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
