//Member Functions File.hpp

/*OVERVIEW : 
This file contains the core functionalities for managing book borrowing and returning, displaying borrowed books, and generating a membership card within the Library Management System. It includes operations that a library member can perform, such as borrowing books, returning them, viewing borrowed books, and accessing their membership card details.

DEPENDENCIES : 
   -> Standard Libraries: <iostream>, <format>, <cctype>
   -> Custom Header Files:
        * "Classes Declaration File.hpp"
        * "Library Functions File.hpp"

FUNCTIONS : 
   -> Borrow_Book(char Access_Type, unique_ptr<Member> &Current_Member, vector<unique_ptr<Member>> &Members, vector<unique_ptr<Book>> &Books): 
        * Displays a header for borrowing books and lists available books.
        * Prompts the user to enter a Book ID to borrow.
        * If the book is available, updates the book's status to "Borrowed" and associates it with the current member.

   -> Return_Book(unique_ptr<Member> &Current_Member, vector<unique_ptr<Book>> &Books):
        * Displays a header for returning books.
        * Prompts the user to enter a Book ID to return.
        * Updates the book's status to "Returned" and disassociates it from the member if the book was previously borrowed by the member.

   -> Borrowed_Books(unique_ptr<Member> &Current_Member, vector<unique_ptr<Book>> &Books):
        * Displays a list of books currently borrowed by the member.
        * Shows details such as ID, title, author, and year published for each borrowed book.
     
   -> Membership_Card(unique_ptr<Member> &Current_Member):
        * Displays the member's membership card details, including name, age, and member ID.
        * Formats the card as a visually appealing block with fields like "Name," "Age," and "Member ID," along with placeholders for the member's and director's signatures.
*/

#pragma once
#include <iostream>
#include "Classes Declaration File.hpp"
#include "Library Functions File.hpp"
#include <format>
#include <cctype>
using namespace std;

void Borrow_Book (char Access_Type, unique_ptr <Member> &Current_Member, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books){
     Header("LIBRARIAN'S HUB : BORROW BOOK");
     Display_Table(Access_Type, Library::getbook_count(), "Books", Members, Books);
     int BorrowId;
     cout<<"\nEnter BookId : "; cin>>BorrowId;
     if (BorrowId <= Library::getbook_count()){
          if (Books[BorrowId - 5844]->Status == "Available"){
               cout<<endl<<padding("Issued the Book...")<<"Issued the Book : "<<endl;
               Books[BorrowId - 5844]->Status = "Borrowed";
               Books[BorrowId - 5844]->BorrowId = Current_Member->MemberId;
               Books[BorrowId - 5844]->printBookData();
               cout<<endl<<padding("To the Member  : ")<<"To the Member  : "<<endl;
               Current_Member->printMemberData();
               Current_Member->BorrowBook(BorrowId);
          }
          else 
               cout<<endl<<padding("Book is not available...")<<"Book is not available..."<<endl;
     }
     else cout<<endl<<padding("Enter valid Book ID...")<<"Enter valid Book ID..."<<endl;
     Bottom_Line_2(Exit_Parts);
}

void Return_Book (unique_ptr <Member> &Current_Member, vector <unique_ptr <Book>> &Books){
     Header("LIBRARIAN'S HUB : RETURN BOOK");
     int ReturnId;
     cout<<"\nEnter BookId : "; cin>>ReturnId;
     if (ReturnId <= Library::getbook_count()){
          if (Current_Member->ReturnBook(ReturnId)){
               cout<<endl<<padding("Returned the Book...")<<"Returned the Book : "<<endl;
               Books[ReturnId - 5844]->Status = "Returned";
               Books[ReturnId - 5844]->BorrowId = 0;
               Books[ReturnId - 5844]->printBookData();
               cout<<endl<<padding("From the Member  : ")<<"From the Member  : "<<endl;
               Current_Member->printMemberData();
          }
          else 
               cout<<endl<<padding("Book was not previously Issued by you...")<<"Book was not previously Issued by you..."<<endl;
     }
     else cout<<endl<<padding("Enter valid Book ID...")<<"Enter valid Book ID..."<<endl;
     Bottom_Line_2(Exit_Parts);
}

void Borrowed_Books(unique_ptr <Member> &Current_Member, vector <unique_ptr <Book>> &Books){
     Header("LIBRARIAN'S HUB : DISPLAY BOOKS");
     cout<<endl<<padding("Fetching Details from Books Database...")<<"Fetching Details from Books Database..."<<endl;
     vector <int> BookId = Current_Member->getBookId();
     if (BookId.size() == 0){
          cout<<endl<<endl<<padding("No Books has been currently Borrowed by you")<<"No Books has been currently Borrowed by you"<<endl;
          cout<<endl<<padding("Start Learning earlier than Others")<<"Start Learning earlier than Others"<<endl;
          cout<<padding("Borrow new Books...")<<"Borrow new Books..."<<endl;
          return;
     }
     string Table_line = string(94, '-'), text = format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", "ID", "TITLE", "AUTHOR", "YEAR PUBLISHED"), Table_Row_padding = string(static_cast <int> ((consoleWidth - text.size())/2) , ' ');
     cout<<endl<<endl<<Table_Row_padding<<Table_line<<endl
         <<Table_Row_padding<<text<<endl
         <<Table_Row_padding<<Table_line<<endl;
     for (int i : BookId)
          cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", Books[i - 5844]->BookId, Books[i - 5844]->Title, Books[i - 5844]->Author, Books[i - 5844]->YearPublished)<<endl;
     cout<<Table_Row_padding<<Table_line<<endl;
     cout<<"\nTotal no. of Books Borrowed : "<<BookId.size()<<endl;
}

void Membership_Card(unique_ptr <Member> &Current_Member){
     Header("LIBRARIAN'S HUB : MEMBERSHIP CARD");
     cout<<endl<<padding("Fetching Card Details...")<<"Fetching Card Details..."<<endl<<endl;
     string Table_line = string(60, '-'), gap(58, ' '), Table_Row_padding = string(static_cast <int> ((consoleWidth - Table_line.size())/2) , ' ');
     cout<<Table_Row_padding<<Table_line<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format("{:<18}PREMIUM MEMBERSHIP CARD{:<17}", " ", " ")<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format(" Name : {:<50}", Current_Member->Name)<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format(" Age : {:<51}", Current_Member->age)<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format(" Member ID : {:<45}", Current_Member->MemberId)<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"| "<<format("   {:<10}\t\t\t      DIRECTOR         |", (Current_Member->Name.length() > 10)? Current_Member->Name : (Current_Member->Name).substr(0,10))<<endl
         <<Table_Row_padding<<"|    Your Signature \t\tDirector's Signature   |"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<Table_line<<endl;
     Bottom_Line_2(Exit_Parts);
}