//Mission 4 : Bank Management System

#include <iostream>
#include <thread>
#include  <chrono>
using namespace std;

#define line cout<<endl<<"====================================================================================================================================="<<endl<<endl
#define sleep(timed) this_thread::sleep_for (chrono::seconds(timed))
#define clear_screen system("cls")

void Exiting_Window (void);

void Header (string Heading){
     clear_screen; line;
     cout<<"\b\t\t\t\t\t\t"<<Heading<<endl; line;
}

void Bottom_Line (int page){
     if (page == 1){
          line;
          cout<<"\t\t\t\t\t\t     Initiating your request...";
          sleep(2);
          return;
     }
     else if (page == 2){
          line;
          char menu_choice;
          cout<<"\t\t\t\t\t  Enter M to go to Main Menu or any other key to exit : ";
          cin>>menu_choice;
          if (menu_choice != 'M') Exiting_Window();
          return;
     }
     else if (page == 3) {cout<<"\n"; line; sleep(page);}
}

int Main_Menu (void){
     Header("     BANK MANAGER : MAIN MENU");
     cout<<"\n\t\t\t\t\t\tA. Deposit Money\
     \n\t\t\t\t\t\tB. Withdraw Money\
     \n\t\t\t\t\t\tC. Check Bank Balance\
     \n\t\t\t\t\t\tD. Exit\
     \n\nEnter your choice : ";
     char choice; cin>>choice;
     if (choice >= 'A' && choice <= 'D') Bottom_Line(1);
     return choice;
}

void Exiting_Window (void){
     Header("     BANK MANAGER : EXIT WINDOW");
     cout<<"\n\t\t\t\t\t\t\t     Thank You!"
          <<"\n\t\t\t\t\t\t for using Bank Management System..."
          <<"\n\n\n\t\t\t\t\t\t       WE WILL WAIT FOR YOU!..."<<endl;
     Bottom_Line(3);
     system("cls");
     exit(0);
}

int main(){
     float Balance {1000.0};
     while (true){
          char choice = Main_Menu();
          switch (choice){
               case 'A':{
                    Header("    BANK MANAGER : DEPOSIT WINDOW");
                    float Deposit_Amount {0};
                    cout<<"\nEnter Amount to be Deposited (in Rupeees) : ";
                    cin>>Deposit_Amount;
                    if (Deposit_Amount > 0){
                         Balance += Deposit_Amount;
                         cout<<"\n\t\t\t\t\t\t\t     Deposited..." <<endl;
                    }
                    else 
                         cout<<"\n\t\t\t\t\t\t      Invalid Deposit amount..."<<endl;
                    Bottom_Line(2);
                    break;
               }
               case 'B':{
                    Header("   BANK MANAGER : WITHDRAW WINDOW");
                    float Withdraw_Amount {0};
                    cout<<"\nEnter Amount to be Withdrawn (in Rupeees) : ";
                    cin>>Withdraw_Amount;
                    if (Withdraw_Amount > 0 && Withdraw_Amount <= Balance){
                         Balance += Withdraw_Amount;
                         cout<<"\n\t\t\t\t\t\t\tWithdraw Successful..." <<endl;
                    }
                    else 
                         if (Withdraw_Amount > Balance)
                              cout<<"\n\t\t\t\t\t\t       Insufficient Balance..."<<endl;
                         else 
                              cout<<"\n\t\t\t\t\t\t        Enter valid amount..."<<endl;
                    Bottom_Line(2);
                    break;
               }
               case 'C':
                    Header("   BANK MANAGER : WITHDRAW WINDOW");
                    cout<<"\n\t\t\t\t\t            Fetching the Tasks Details...";
                    sleep(2);
                    cout<<"\n\nYou Current Balance is : "<<Balance<<endl;
                    Bottom_Line(2);
                    break;
               case 'D':
                    Exiting_Window();
               default:
                    cout<<"\t\t\t\t\t\t      Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}