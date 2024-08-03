#pragma once
#include <iostream>
#include "Classes Declaration File.hpp"
#include "Library Functions File.hpp"
#include <format>

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
               cout<<endl<<padding("To the Member  : ");
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
               cout<<endl<<padding("From the Member  : ");
               Current_Member->printMemberData();
               Current_Member->BorrowBook(ReturnId);
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
     Bottom_Line_2(Exit_Parts);
}

void Membership_Card(unique_ptr <Member> &Current_Member){
     Header("LIBRARIAN'S HUB : MEMBERSHIP CARD");
     cout<<endl<<padding("Fetching Card Details...")<<"Fetching Card Details..."<<endl<<endl;
     string Table_line = string(50, '-'), gap(48, ' '), Table_Row_padding = string(static_cast <int> ((consoleWidth - Table_line.size())/2) , ' ');
     string text1 = Current_Member->Name + "\t\t DIRECTOR", text2 = "Your Signature \t\t\t\t Director's Signature";
     string sign_paddingWidth1(static_cast <int> ((48 - text1.size())/2) , ' '),  sign_paddingWidth2(static_cast <int> ((48 - text2.size())/2) , ' ');
     cout<<Table_Row_padding<<Table_line<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<"\t       PREMIUM MEMBERSHIP CARD         \t"<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format(" Name : {:<40}", Current_Member->Name)<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format(" Age : {:<41}", Current_Member->age)<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<format(" Member ID : {:<35}", Current_Member->MemberId)<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<"|"<<sign_paddingWidth1<<text1<<sign_paddingWidth1<<"|"<<endl
         <<Table_Row_padding<<"|"<<sign_paddingWidth2<<text2<<sign_paddingWidth2<<"|"<<endl
         <<Table_Row_padding<<"|"<<gap<<"|"<<endl
         <<Table_Row_padding<<Table_line<<endl;
     Bottom_Line_2(Exit_Parts);
}