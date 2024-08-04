//Additional Missions : Contact Diary

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