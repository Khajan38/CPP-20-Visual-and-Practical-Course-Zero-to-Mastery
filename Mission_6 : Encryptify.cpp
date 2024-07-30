//Mission 6 : Encryptify -> Encryptor - Decryptor 

#include <iostream>
#include <string>
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
     Header("      ENCRYPTIFY : MAIN MENU");
     cout<<"\n\t\t\t\t\t\tA. Encrypt a Message\
     \n\t\t\t\t\t\tB. Decrypt a Message\
     \n\t\t\t\t\t\tC. Exit\
     \n\nEnter your choice : ";
     char choice; cin>>choice;
     if (choice >= 'A' && choice <= 'C') Bottom_Line(1);
     return choice;
}

void Exiting_Window (void){
     Header("    Encryptify : EXIT WINDOW");
     cout<<"\n\t\t\t\t\t\t\t     Thank You!"
          <<"\n\t\t\t\t\t                for using Encryptify..."
          <<"\n\n\n\t\t\t\t\t\t       WE WILL WAIT FOR YOU!..."<<endl;
     Bottom_Line(3);
     system("cls");
     exit(0);
}

string DecryptionKey = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
string EncryptionKey = "+_)(*!@#$p^:L>?<MVCADGYREW12hfbnm.;[]97543kl86qwerty%";

string Encrypt_Message (string Encrypted_Message){
     for (char & i : Encrypted_Message){
          if (i >= 'a' && i <= 'z') i = EncryptionKey[static_cast <int> (i) - 97];
          else if (i >= 'A' && i <= 'Z') i = EncryptionKey[static_cast <int> (i) - 65 + 26];
          else if (i == ' ') i = EncryptionKey[52];
          else {
               Encrypted_Message = "Enter valid Message...";
               break;
          }
     }
     return Encrypted_Message;
}

string Decrypt_Message (string Decrypted_Message){
     for (char & i : Decrypted_Message){
          bool found = false;
          for (int j = 0; j < EncryptionKey.size(); j++){
               if (i == EncryptionKey[j]){
                    i = DecryptionKey[j];
                    found = true;
                    break;
               }
          }
          if (found == false) {
               Decrypted_Message = "Enter valid Message...";
               return Decrypted_Message;
          }
     }
     return Decrypted_Message;
}

int main(){
     while (true){
          char choice = Main_Menu();
          switch (choice){
               case 'A':{
                    Header("    ENCRYPTIFY : ENCRYPTION WINDOW");
                    string Message, Encrypted_Message;
                    cout<<"\nEnter Message to be Encrypyted : ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin , Message);
                    Encrypted_Message = Encrypt_Message(Message);
                    cout<<"\n\n\t\t\t\t\t            Running Encryption Process..."<<endl<<endl<<endl;
                    sleep(2);
                    if (Encrypted_Message != "Enter valid Message..."){
                         cout<<"Encrypted Message : ";
                    }
                    cout<<Encrypted_Message <<endl;
                    Bottom_Line(2);
                    break;
               }
               case 'B':{
                    Header("    ENCRYPTIFY : DECRYPTION WINDOW");
                    string Message, Decrypted_Message;
                    cout<<"\nEnter Message to be Decrypyted : ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin , Message);
                    Decrypted_Message = Decrypt_Message(Message);
                    cout<<"\n\n\t\t\t\t\t            Running Decryption Process..."<<endl<<endl<<endl;
                    sleep(2);
                    if (Decrypted_Message != "Enter valid Message..."){
                         cout<<"Decrypted Message : " ;
                    }
                    cout<<Decrypted_Message<<endl;
                    Bottom_Line(2);
                    break;
               }
               case 'C':
                    Exiting_Window();
               default:
                    cout<<"\n\n\t\t\t\t\t\t      Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}