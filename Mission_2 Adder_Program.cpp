//Mission 2 : Adding Input Integers

/*OVERVIEW : 
This simple C++ program takes three integers as input from the user and calculates their sum. It then displays the sum, formatted to two decimal places.

DEPENDENCIES :
   -> Standard Library Headers: <iostream>, <format>

VARIABLES: 
   -> int Num1, Num2, Num3
   -> double Sum

USER INPUT: Prompts the user to enter three integers, storing them in Num1, Num2, and Num3.

CALCULATIONS : Computes the sum of the three numbers using static_cast<double>(Num1) to ensure the result is stored as a double, allowing for decimal precision in the output.

OUTPUT : Uses the format function to output the sum in a formatted string, showing two decimal places for the sum. The output format is: "Sum of {Num1} + {Num2} + {Num3} = {Sum}".

USEAGE : When the program is executed, the user is prompted to enter three numbers. The program then outputs the sum of these numbers in a formatted message, ensuring the sum is displayed with two decimal places.*/

#include <iostream>
#include <format>
using namespace std;
int main(){
     int Num1, Num2, Num3;
     cout<<"\nEnter First Number : "; cin>>Num1;
     cout<<"Enter Second Number : "; cin>>Num2;
     cout<<"Enter Third Number : "; cin>>Num3;
     double Sum = static_cast <double> (Num1) + Num2 + Num3;
     cout<<endl<<format("Sum of {} + {} + {} = {:.2f}", Num1, Num2, Num3, Sum)<<endl;
     return 0;
}