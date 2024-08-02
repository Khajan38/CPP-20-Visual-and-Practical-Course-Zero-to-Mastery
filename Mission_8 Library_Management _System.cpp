//Mission 8 : Inventory System

#include <iostream>
#include <memory>
#include "Display_Basics.hpp"
using namespace std;

array <string, 2> Exit_Parts {"LIBRARIAN'S HUB", "Librarian's Hub"};
class Book; 
class Member;
class Library {
     vector <unique_ptr <Book>> Books; 
     vector <unique_ptr <Member>> Members;
     static int book_count, member_count; //Static Data Member for Books and Members
     public :
          static void count_change(string change_type){ //Static Data Function
               if (change_type == "Book++") book_count++;
               else if (change_type == "Book--") book_count--;
               else if (change_type == "Member++") member_count++;
               else member_count--;
          }
          void AddBook (void);
          void AddMember (void);
          void DisplayBooks (void);
          void DisplayMembers (void);
          void BorrowBook (void);
          void ReturnBook (void);
};
int Library::book_count = 0; //Static Member Initialization
int Library::member_count = 0; //Static Member Initialization

class Book{
     string Title, Author;
     int YearPublished;
     friend void Library :: AddBook(void); //Let access to Title, Author and Year Published
     friend void Library :: DisplayBooks (void); //Let access to Title, Author and Year Published
     public :
          explicit Book (string Title, string Author, int YearPublished) : Title(Title), Author(Author), YearPublished(YearPublished){Library::count_change("Book++");}; //Setting a Parameterized Constructor
          Book (void) {Library::count_change("Book++");}; //Setting a Blank Constructor
          ~ Book (void) {Library::count_change("Book--");}; //Modifying Destructors
          //Getter Methods
};

class Member{
     string Name;
     int MemberId;
     friend void Library :: AddMember(void); //Let access to Name and Member ID
     friend void Library :: DisplayMembers (void); //Let access to Name and Member ID
     public:
          Member (string Name, int MemberId) : Name(Name), MemberId(MemberId){Library::count_change("Member++");}; //Setting a Parameterized Constructor
          Member (void) {Library::count_change("Member++");}; //Setting a Blank Constructor
          ~ Member (void) {Library::count_change("Member--");}; //Modifying Destructors
          //Getter Methods
};

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
     cout<<"Enter Member ID : "; cin>>Members[0]->MemberId;
     Bottom_Line_2(Exit_Parts);
}

void Library :: DisplayBooks(void){
     Header("LIBRARIAN'S HUB : DISPLAY BOOKS");
     cout<<endl<<padding("Fetching Details from Books Database...")<<"Fetching Details from Books Database..."<<endl;
     if (book_count == 0){
          cout<<endl<<endl<<padding("No Books currently available in Library...")<<"No Books currently available in Library..."<<endl;
          return;
     }
     for (int i = 0; i < book_count; i++){
          string Table_line (94, '-'), text = format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", "ID", "TITLE", "AUTHOR", "YEAR PUBLISHED"), Table_Row_padding (static_cast <int> ((consoleWidth - text.size())/2) , ' ');
          cout<<endl<<endl<<Table_Row_padding<<Table_line<<endl;
          cout <<Table_Row_padding<<text<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
          for (int i = 0; i < book_count; i++)
               cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|   {:<20}|   {:<17}|", i+1, Books[i]->Title, Books[i]->Author, Books[i]->YearPublished)<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
     }
     Bottom_Line_2(Exit_Parts);
}

void DisplayTable(int book_count, vector <unique_ptr <Member>> Members){
     cout<<endl<<padding("Fetching Details from Members Database...")<<"Fetching Details from Members Database..."<<endl;
     if (book_count == 0){
          cout<<endl<<endl<<padding("No Members currently present in Library...")<<"No Members currently present in Library..."<<endl;
          return;
     }
     for (int i = 0; i < book_count; i++){
          string Table_line (49, '-'), text = format("|   {:<5}|   {:<35}|", "ID", "NAME"), Table_Row_padding (static_cast <int> ((consoleWidth - text.size())/2) , ' ');
          cout<<endl<<endl<<Table_Row_padding<<Table_line<<endl;
          cout <<Table_Row_padding<<text<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
          for (int i = 0; i < book_count; i++)
               cout<<Table_Row_padding<<format("|   {:<5}|   {:<35}|", Members[i]->MemberId, Members[i]->Name)<<endl;
          cout<<Table_Row_padding<<Table_line<<endl;
     }
}

void Library :: DisplayMembers(void){
     Header("LIBRARIAN'S HUB : DISPLAY MEMBERS");
     DiaplayTable(book_count, Members);
     Bottom_Line_2(Exit_Parts);
}

void Library :: BorrowBook(void){
     
}