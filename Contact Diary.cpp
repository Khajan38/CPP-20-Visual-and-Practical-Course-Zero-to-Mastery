//Additional Missions : Contact Diary

/*OVERVIEW : 
The Contact Diary program allows users to manage a list of contacts, including adding, displaying, searching, deleting, and inserting new contacts. The program uses a structure hello to store contact information, including the name and phone number. The list of contacts is maintained in an array named contact.

DEPENDENCIES :
   -> Standard Library Headers: <stdio.h>, <stdlib.h>
   -> Project-Specific Headers:
        * "Display_Basics.hpp"

GLOBAL VARIABLES :
   -> n: The number of contacts currently in the diary.
   -> contact: An array of hello structures to store contact details.
   -> Project-Specific Headers:
        * "Task-Management-System\Main Header File.hpp"
FUNCTIONS :
   -> void display(void) :
        * Displays the list of contacts.
        * Iterates over the contact array and prints each contact's name and phone number.

   -> void search(void) :
        * Searches for a contact by phone number.
        * Prompts the user to enter a phone number and checks if it exists in the contact array.

   -> void phn_delete(void) :
        * Deletes a contact by phone number.
        * Prompts the user to enter a phone number and removes the corresponding contact from the array if found.

   -> void input(void) :
        * Takes input for the initial set of contacts.
        * Prompts the user to enter the number of contacts and their details.

   -> void insert(void) :
        * Inserts a new contact into the diary.
        * Prompts the user to enter the new contact's name and phone number, adding it to the contact array.

   -> void out(void) :
        * Displays an exit message using the Exiting_Window function from the Display_Basics.hpp file.

WORKING :
   -> The main() function initializes the contact list by calling the input() function.
   -> It displays the contact list using the display() function.
   -> A loop provides a menu for the user to perform various operations (insertion, display, search, delete, exit).
   -> The user can repeat the operations until they choose to exit.

USEAGE : The program can be run in a console. It provides a simple text-based interface for managing a small list of contacts. The menu options are:
     A: Insert a new contact.
     B: Display all contacts.
     C: Search for a contact by phone number.
     D: Delete a contact by phone number.
     E: Exit the contact diary.
The user is prompted to enter their choice, and the corresponding function is executed. The program loops back to the main menu unless the user chooses to exit.*/

#include <stdio.h>
#include <stdlib.h>
#include "Display_Basics.hpp"

int n;
typedef struct {
     char name[50];
     unsigned long long int phoneno;
} hello;
hello contact[50];

void display(void){
     Header("YOUR CONTACT LIST");
     for (int i = 0; i < n; i++){
          printf("\nName of Contact %d : ", i + 1);
          puts(contact[i].name);
          printf("Phone number : ");
          printf("%llu\n", contact[i].phoneno);
     }
     std::cout<<endl<<padding("Press enter to continue...")<<"Press enter to continue...";
     getchar();
     scanf("[^\n]%s", "Hello");
}

void search(void){
     Header("SEARCHING WINDOW");
     unsigned long long int no;
     printf("\nEnter the number you want to search : ");
     scanf("%llu", &no);
     for (int i = 0; i < n; i++){
          if (no == contact[i].phoneno){
               printf("\nName of contact %d : ", i + 1);
               puts(contact[i].name);
               printf("Phone number : ");
               printf("%llu\n", contact[i].phoneno);
          }
     }
}

void phn_delete(void){
     Header("DELETION WINDOW");
     if (n == 0){
          std::cout<<endl<<endl<<padding("No Contacts left in Diary...")<<"No Contacts left in Diary...\n";
          return;
     }
     unsigned long long int no;
     hello temp;
     printf("\nEnter the number you want to delete : ");
     scanf("%llu", &no);
     for (int i = 0; i < n; i++){
          if (no == contact[i].phoneno){
               for (int j = i; j < n; j++) 
                    contact[j] = contact[j + 1];
               n--;
               std::cout<<endl<<endl<<padding("Contact Succesfully Deleted...")<<"Contact Succesfully Deleted...\n";
               return;
          }
     }
     std::cout<<endl<<endl<<padding("Contact Record Not Found...\n")<<"Contact Record Not Found...\n";
}

void input(void){
     Header("INPUT WINDOW");
     printf("\nEnter total contacts : ");
     scanf("%d", &n);
     for (int i = 0; i < n; i++){
          printf("\nEnter Name of Contact %d : ", i + 1);
          getchar();
          gets(contact[i].name);
          printf("Enter Phone number %d : ", i + 1);
          scanf("%llu", &contact[i].phoneno);
     }
}

void insert(void){
     Header("INSERTION WINDOW");
     printf("\nEnter name of Contact : ");
     getchar();
     gets(contact[n].name);
     printf("Enter Phone number : ");
     scanf("%llu", &contact[n].phoneno);
     n++;
     std::cout<<endl<<padding("Details Succesfully Inserted...")<<"Details Succesfully Inserted...\n";
}

void out(void){
     array <string, 2> Exit_Parts {"CONTACT DIARY", "Contact Diary"};
     Exiting_Window(Exit_Parts);
}

int main(){
     input();
     display();
     char repeat = 'y', choice;
     while (repeat == 'y'){
          vector <string> Menu_items {"CONTACT DIARY", "Insert Contact in Diary", "Display Contact Diary", "Search Contact in Diary", "Delete Contact in Diary", "Exit from the Diary"};
          choice = Main_Menu(Menu_items);
          switch (choice) {
               case 'A' : insert(); break;
               case 'B' : display(); break;
               case 'C' : search(); break;
               case 'D' : phn_delete(); break;
               case 'E' : out(); break;
               default : (printf("\nInvalid choice..."));
          }
          std::cout<<endl<<padding("Do you want to go back to Main Menu ? (y/n) : ")<<"Do you want to go back to Main Menu ? (y/n) : ";
          scanf(" %c", &repeat);
          if (repeat == 'n') out();
     }
     return 0;
}