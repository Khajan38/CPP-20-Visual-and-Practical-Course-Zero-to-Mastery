// Mission 6: Encryptify -> Encryptor - Decryptor

/* OVERVIEW :
This C++ program implements a simple encryption and decryption system. It allows users to encrypt and decrypt messages using predefined keys. The program provides a menu-driven interface for these operations and validates the input to ensure proper functionality.

DEPENDENCIES :
   -> Standard Libraries: <iostream>, <string>
   -> Custom Header Files:
        * "Display_Basics.hpp"

VARIABLES :
   -> string DecryptionKey:
        * Contains the set of characters used for decryption.
   -> string EncryptionKey:
        * Contains the corresponding encrypted characters used for encryption.

FUNCTIONS :
   -> string Encrypt_Message(string Encrypted_Message):
        * Encrypts the input message by replacing characters with their corresponding characters in the `EncryptionKey`.
        * If an invalid character is found, returns "Enter valid Message...".
        
   -> string Decrypt_Message(string Decrypted_Message):
        * Decrypts the input message by mapping characters from the `EncryptionKey` to the `DecryptionKey`.
        * If an invalid character is found, returns "Enter valid Message...".

WORKING :
   -> Main loop where users can choose to encrypt a message, decrypt a message, or exit.
   -> Provides prompts and handles user input for the chosen operation.
   -> Displays results of encryption and decryption processes.

TEMPLATES FOR ALL PAGES : Provided by "Display_Basics.hpp" which includes various function methods for Page Templates. These include:
   -> Headings: "Display_Basics.hpp -> Header()"
   -> Word Padding to center: "Display_Basics.hpp -> padding [] () {}"
   -> Footers and Bottom Lines: "Display_Basics.hpp -> Bottom_Line(), Bottom_Line_2()"
   -> Main Menus: "Display_Basics.hpp -> Main_Menu()"
   -> Exit Window: "Display_Basics.hpp -> Exiting_Window()"

USAGE : The user interacts with the program through a menu to:
   1. Encrypt a Message: Input a message to be encrypted. The message will be transformed using the `EncryptionKey`.
   2. Decrypt a Message: Input an encrypted message to be decrypted. The message will be transformed back using the `DecryptionKey`.
   3. Exit: Exit the program.*/

#include <iostream>
#include "Display_Basics.hpp"
using namespace std;

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
     array <string, 2> Exit_Parts {"ENCRYPTIFY", "Encryptify"};
     while (true){
          vector <string> Menu {"ENCRYPTIFY", "Encrypt a Message", "Decrypt a Message", "Exit"};
          char choice = Main_Menu(Menu);
          switch (choice){
               case 'A':{
                    Header("ENCRYPTIFY : ENCRYPTION WINDOW");
                    string Message, Encrypted_Message;
                    cout<<"\nEnter Message to be Encrypyted : ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin , Message);
                    Encrypted_Message = Encrypt_Message(Message);
                    cout<<endl<<endl<<padding("Running Encryption Process...")<<"Running Encryption Process..."<<endl<<endl<<endl;
                    sleep(2);
                    if (Encrypted_Message != "Enter valid Message..."){
                         cout<<"Encrypted Message : ";
                    }
                    cout<<Encrypted_Message <<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'B':{
                    Header("ENCRYPTIFY : DECRYPTION WINDOW");
                    string Message, Decrypted_Message;
                    cout<<"\nEnter Message to be Decrypyted : ";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin , Message);
                    Decrypted_Message = Decrypt_Message(Message);
                    cout<<endl<<endl<<padding("Running Decryption Process...")<<"Running Decryption Process..."<<endl<<endl<<endl;
                    sleep(2);
                    if (Decrypted_Message != "Enter valid Message..."){
                         cout<<"Decrypted Message : " ;
                    }
                    cout<<Decrypted_Message<<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'C':
                    Exiting_Window(Exit_Parts);
               default:
                    cout<<"\n\n\t\t\t\t\t\t      Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}