#pragma once
#include <iostream>
#include "Classes Declaration File.hpp"
#include <format>
using namespace std;

void Library :: AddBook(void){ //Adding New Books
     Header("LIBRARIAN'S HUB : ADD BOOK");
     Books.push_back(make_unique <Book>());
     cout<<"\nEnter the Title of the Book : "; cin>>Books[0]->Title;
     cout<<"Enter the Author Name : "; cin>>Books[0]->Author;
     cout<<"Enter the Pusblishing Year : "; cin>>Books[0]->YearPublished;
     Bottom_Line_2(Exit_Parts);
}

void Library :: AddMember(void){ //Adding new Members
     Header("LIBRARIAN'S HUB : ADD MEMBER");
     Members.push_back(make_unique <Member>());
     cout<<"\nEnter the Name of the Member : "; cin>>Members[0]->Name;
     Members[0]->MemberId = member_count;
     Bottom_Line_2(Exit_Parts);
}

void Display_Table(char Access_Type, int count, string type, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books){
     cout<<endl<<padding("Fetching Details from "+ type + " Database...")<<"Fetching Details from "+ type + " Database..."<<endl;
     if (count == 0){
          cout<<endl<<endl<<padding("No "+ type + " currently present in Library...")<<"No "+ type + " currently present in Library..."<<endl;
          return;
     }
     string Table_line, text, Table_Row_padding;
     if (type == "Members") {
          Table_line = string(49, '-');
          text = format("|   {:<5}|   {:<35}|", "ID", "NAME");
          Table_Row_padding = string(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
     }
     else if (type == "Books"){
          if (Access_Type == 'M'){
               Table_line = string(94, '-'); 
               text = format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", "ID", "TITLE", "AUTHOR", "YEAR PUBLISHED");
               Table_Row_padding = string(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
          }
          else{
               Table_line = string(94, '-'); 
               text = format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|   {:<30}|", "ID", "TITLE", "AUTHOR", "YEAR PUBLISHED", "STATUS");
               Table_Row_padding = string(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
          }
     }
     cout<<endl<<endl<<Table_Row_padding<<Table_line<<endl
         <<Table_Row_padding<<text<<endl
         <<Table_Row_padding<<Table_line<<endl;
     if (type == "Members"){
          for (int i = 0; i < count; i++)
               cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|", Members[i]->MemberId, Members[i]->Name)<<endl;
     }
     else if (type == "Books"){
          if (Access_Type == 'M')
               for (int i = 0; i < count; i++)
                    if (Books[i]->Status == "Available")
                         cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", Books[i]->BookId, Books[i]->Title, Books[i]->Author, Books[i]->YearPublished)<<endl;
          else 
               cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|   {:<30}|", Books[i]->BookId, Books[i]->Title, Books[i]->Author, Books[i]->YearPublished, Books[i]->BorrowId == 0 ? Books[i]->Status : Books[i]->Status + " by " + to_string(Books[i]->BorrowId))<<endl;
          }
          
     cout<<Table_Row_padding<<Table_line<<endl;
}

void Library :: DisplayBooks(char Access_Type){
     Header("LIBRARIAN'S HUB : DISPLAY BOOKS");
     Display_Table(Access_Type, book_count, "Books", Members, Books);
     Bottom_Line_2(Exit_Parts);
}

void Library :: DisplayMembers(char Access_Type){
     Header("LIBRARIAN'S HUB : DISPLAY MEMBERS");
     Display_Table(Access_Type, book_count, "Members", Members, Books);
     Bottom_Line_2(Exit_Parts);
}