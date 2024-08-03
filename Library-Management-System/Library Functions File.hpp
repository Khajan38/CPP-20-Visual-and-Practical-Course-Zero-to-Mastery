//Library Functions File.hpp

/*OVERVIEW : 
This file defines several functions for managing books and members in the Library Management System. The functions allow for adding, displaying, and removing books and members, as well as displaying tables of data.

DEPENDENCIES : 
   -> Standard Libraries: <iostream>, <format>
   -> Custom Header Files:
        * "Classes Declaration File.hpp"
        * "../Display_Basics.hpp"

CLASS MEMBER FUNCTIONS (Library) : 
   -> void AddBook(void):
        * Prompts the director to input details for a new book, including title, author, and publishing year.
        * Adds the book to the library's collection.

   -> void AddMember(void):
        * Prompts for the name of a new library member.
        * Assigns a unique ID and adds the member to the members list.

   -> void DisplayBooks(char Access_Type):
        * Displays a table of all books in the library.
        * The content of the table varies based on the access type ('M' for members, 'D' for directors).

   -> void DisplayMembers(char Access_Type):
        * Displays a table of all library members.
        * Accessible only by directors.

   -> void RemoveBook(char Access_Type):
        * Displays available books and prompts for a book ID to remove.
        * Ensures the book is available (not borrowed) before removal.

   -> void RemoveMember(char Access_Type):
        * Displays a list of members and prompts for a member ID to remove.
        * Ensures the member has no pending book issues before removal.

HELPER FUNCTIONS : 
   -> void Display_Table(char Access_Type, int count, string type, vector<unique_ptr<Member>> &Members, vector<unique_ptr<Book>> &Books):
        * function to display tables for books or members.
        * Adjusts formatting based on the type of data and access level.*/

#pragma once
#include <iostream>
#include "Classes Declaration File.hpp"
#include <format>
using namespace std;

void Library :: AddBook(void){ //Adding New Books
     Header("LIBRARIAN'S HUB : ADD BOOK");
     Books.push_back(make_unique <Book>());
     cin.ignore(INT_MAX, '\n');
     cout<<"\nEnter the Title of the Book : "; getline(cin,Books[book_count - 5844]->Title);
     cout<<"Enter the Author Name : "; getline(cin, Books[book_count - 5844]->Author);
     cout<<"Enter the Pusblishing Year : "; cin>>Books[book_count - 5844]->YearPublished;
     cout<<endl<<padding("Inserted Book Details in Database...")<<"Inserted Book Details in Database..."<<endl;
     Bottom_Line_2(Exit_Parts);
}

void Library :: AddMember(void){ //Adding new Members
     Header("LIBRARIAN'S HUB : ADD MEMBER");
     Members.push_back(make_unique <Member>());
     cin.ignore(INT_MAX, '\n');
     cout<<"\nEnter the Name of the Member : "; getline(cin, Members[member_count - 1326]->Name);
     Members[0]->MemberId = member_count;
     cout<<endl<<padding("Inserted Member Details in Database...")<<"Inserted Member Details in Database..."<<endl;
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
               Table_line = string(116, '-'); 
               text = format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|   {:<18}|", "ID", "TITLE", "AUTHOR", "YEAR PUBLISHED", "STATUS");
               Table_Row_padding = string(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
          }
     }
     cout<<endl<<endl<<Table_Row_padding<<Table_line<<endl
         <<Table_Row_padding<<text<<endl
         <<Table_Row_padding<<Table_line<<endl;
     if (type == "Members"){
          for (int i = 0; i < count - 1325; i++)
               cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|", Members[i]->MemberId, Members[i]->Name)<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
          cout<<"\nTotal no. of Members : "<<Library::member_count - 1325<<endl;
     }
     else if (type == "Books"){
          if (Access_Type == 'M'){
               for (int i = 0; i < count - 5843; i++)
                    if (Books[i]->Status == "Available")
                         cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", Books[i]->BookId, Books[i]->Title, Books[i]->Author, Books[i]->YearPublished)<<endl;      
               cout<<Table_Row_padding<<Table_line<<endl;
          }
          else {
               for (int i = 0; i < count - 5843; i++)
                    cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|   {:<18}|", Books[i]->BookId, Books[i]->Title, Books[i]->Author, Books[i]->YearPublished, Books[i]->BorrowId == 0 ? Books[i]->Status : Books[i]->Status + " by " + to_string(Books[i]->BorrowId))<<endl;       
               cout<<Table_Row_padding<<Table_line<<endl;
               cout<<"\nTotal no. of Books : "<<Library::book_count - 5843<<endl;
          }
     }
}

void Library :: DisplayBooks(char Access_Type){
     Header("LIBRARIAN'S HUB : DISPLAY BOOKS");
     Display_Table(Access_Type, book_count, "Books", Members, Books);
     Bottom_Line_2(Exit_Parts);
}

void Library :: DisplayMembers(char Access_Type){
     Header("LIBRARIAN'S HUB : DISPLAY MEMBERS");
     Display_Table(Access_Type, member_count, "Members", Members, Books);
     Bottom_Line_2(Exit_Parts);
}

void Library :: RemoveBook (char Access_Type){
     Header("LIBRARIAN'S HUB : REMOVE BOOK");
     Display_Table('M', book_count, "Books", Members, Books);
     int ReturnId;
     cout<<"\nEnter BookId : "; cin>>ReturnId;
     if (ReturnId <= Library::getbook_count()){
          if ((Books[ReturnId - 5844]->Status) == "Available"){
               cout<<endl<<padding("Deleted the Book...")<<"Deleted the Book..."<<endl;
               vector <unique_ptr <Book>> :: iterator itr = Books.begin();
               advance(itr, ReturnId - 5844);
               Books.erase(itr);
          }
          else 
               cout<<endl<<Books[ReturnId - 5844]->Status<<padding("Can't delete, as Book is Issued to " + to_string(Books[ReturnId - 5844]->BorrowId))<<"Can't delete, as Book is Issued to " + to_string(Books[ReturnId - 5844]->BorrowId)<<endl;
     }
     else cout<<endl<<padding("Enter valid Book ID...")<<"Enter valid Book ID..."<<endl;
     Bottom_Line_2(Exit_Parts);
}

void Library :: RemoveMember (char Access_Type){
     Header("LIBRARIAN'S HUB : REMOVE BOOK");
     Display_Table('M', member_count, "Members", Members, Books);
     int ReturnId;
     cout<<"\nEnter MemberId : "; cin>>ReturnId;
     if (ReturnId <= Library::getbook_count()){
          if (Members[ReturnId - 1325]->getBookId().size() != 0){
               cout<<endl<<padding("Deleted the Member...")<<"Deleted the Member..."<<endl;
               vector <unique_ptr <Member>> :: iterator itr = Members.begin();
               advance(itr, ReturnId - 1325);
               Members.erase(itr);
          }
          else 
               cout<<endl<<padding("Pending Issues, Can't delete Member...")<<"Pending Issues, Can't delete Member..."<<endl;
     }
     else cout<<endl<<padding("Enter valid Member ID...")<<"Enter valid Member ID..."<<endl;
     Bottom_Line_2(Exit_Parts);
}