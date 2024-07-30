//Mission 3 : Projectile Parameters Solver

#include <iostream>
#include  <math.h>
using namespace std;
int main(){
     double InitialVelocity, Angle, Time, Height, Distance, VelocityX, VelocityY;
     cout<<"\nEnter Initial Velocity of the Projectile (in m/sec) : "; cin>>InitialVelocity;
     cout<<"Enter the Angle of Projectile (in degrees) : "; cin>>Angle;
     cout<<"Enter the Time elapsed since lauch (in sec) : "; cin>>Time;
     cout<<"Enetr the Initial Height of Projectile above the ground (in m) : "; cin>>Height;
     VelocityY = (InitialVelocity * sin(Angle * 3.14 / 180)) + (9.81 * Time);
     VelocityX = InitialVelocity * cos(Angle * 3.14 /180);
     Distance = VelocityX * Time;
     Height += VelocityY * Time + (0.5 * 9.81 * pow(Time, 2));
     cout<<"\nThe Projectile has traveled "<<Distance<<" m horizonatlly."
         <<"\nThe Projectile has reached max "<<Height<<" above the ground at center of Projectile."
         <<"\nThe Projectile has a velocity of "<<VelocityX<<" m/sec in the horizontal direction and "
         <<VelocityY<<" m/sec in vertical direction at Center of Projectile."
         <<"\nThe Projectile has an average verlocity of "<<VelocityX<<" m/sec."
         <<"\nThe Final Velocity of projectile is "<<InitialVelocity<<" m/sec = ("<<VelocityX<<"i - "<<VelocityY<<"j) m/sec which is same in magnitude to Initial Velocity "<<InitialVelocity<<" m/sec = ("<<VelocityX<<"i + "<<VelocityY<<"j) m/sec but 180 phase change with respect to Y axis. "<<endl;
     return 0;
}