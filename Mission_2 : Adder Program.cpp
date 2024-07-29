//Mission 2 : Adding Input Integers

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
