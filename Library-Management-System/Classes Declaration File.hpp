/*Contains Declarations of classes :
     -> Book : Title, Author and PublishingYear
     -> Member : MemberId, Name
     -> Library : 
          * Books - Vectors containing data of all books
          * Members - Vectors containing data of all members
          * book_count - For counting total no. of Books
          * member_count - For counting total no. of Members
*/
#pragma once
#include <iostream>
#include <memory>
#include "../Display_Basics.hpp"
using namespace std;

array <string, 2> Exit_Parts {"LIBRARIAN'S HUB", "Librarian's Hub"};
class Book; 
class Member;
class Library {
     vector <unique_ptr <Book>> Books; 
     vector <unique_ptr <Member>> Members;
     static int book_count, member_count; //Static Data Member for Books and Members
     friend void Display_Table(char Access_Type, int count, string type, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books);
     public :
          static void count_change(string change_type){ //Static Data Function
               if (change_type == "Book++") book_count++;
               else if (change_type == "Book--") book_count--;
               else if (change_type == "Member++") member_count++;
               else member_count--;
          }
          Library (){
               Books.push_back(make_unique <Book> ("Rich Dad Poor Dad", "Robert Kiyosaki", 1997));
               Books.push_back(make_unique <Book> ("Think and Grow Rich", "Napolean Hill", 1937));
               Books.push_back(make_unique <Book> ("A Brief History of Time", "Stephen Hawking", 1988));
               Books.push_back(make_unique <Book> ("Harry Potter", "J.K. Rowling", 1997));
               Books.push_back(make_unique <Book> ("The Da Vinci Code", "Dan Brown", 2003));
               Members.push_back(make_unique <Member> ("Alan Smith", 32));
               Members.push_back(make_unique <Member> ("Barry Williams", 25));
               Members.push_back(make_unique <Member> ("Clarke Jhonson", 28));
          }
          //Defined in Library Functions File.hpp
          void AddBook (void);
          void AddMember (void);
          void DisplayBooks (char Access_Type);
          void DisplayMembers (char Access_Type);
          vector <unique_ptr <Member>> &getMembers (void){return Members;}
          vector <unique_ptr <Book>> &getBooks (void){return Books;}
          static int getbook_count (void){return book_count;}
          static int getmember_count (void) {return member_count;}
};
int Library::book_count = 5843; //Static Member Initialization
int Library::member_count = 1325; //Static Member Initialization

class Book{
     string Title, Author;
     int YearPublished;
     friend void Library :: AddBook(void); //Let access to Title, Author and Year Published
     friend void Display_Table(char Access_Type, int count, string type, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books); //Let access to Title, Author and Year Published
     friend void Borrowed_Books(unique_ptr <Member> &Current_Member, vector <unique_ptr <Book>> &Books);
     public :
          int BookId, BorrowId; string Status;
          explicit Book (string Title, string Author, int YearPublished) : Title(Title), Author(Author), YearPublished(YearPublished), Status("Available"), BookId((Library::getbook_count()+1)), BorrowId(0) {Library::count_change("Book++");}; //Setting a Parameterized Constructor
          Book (void) : Status("Available"), BookId((Library::getbook_count()+1)), BorrowId(0){Library::count_change("Book++");}; //Setting a Partially Blank Constructor
          ~ Book (void) {Library::count_change("Book--");}; //Modifying Destructors
          void printBookData(void){
               cout<<"\nBook Title : "<<Title
                   <<"\tBook ID : "<<BookId
                   <<"\nAuthor : "<<Author
                   <<"\tPublishing Year : "<<YearPublished<<endl;
          }
};

class Member{
     string Name;
     int age;
     vector <int> BookId{};
     friend void Library :: AddMember(void); //Let access to Name and Member ID
     friend void Display_Table(char Access_Type, int count, string type, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books);//Let access to Name and Member ID
     friend void Membership_Card(unique_ptr <Member> &Current_Member);
     public:
          int MemberId;
          Member (string Name, int age) : Name(Name), age(age), MemberId((Library::getmember_count())+1){Library::count_change("Member++");}; //Setting a Parameterized Constructor
          Member (string Name) : Name(Name), MemberId((Library::getmember_count())+1) {Library::count_change("Member++");};
          Member (void) : MemberId((Library::getmember_count())+1) {Library::count_change("Member++");}; //Setting a Blank Constructor
          ~ Member (void) {Library::count_change("Member--");}; //Modifying Destructors
          int operator == (Member &other){
               if (this->Name == other.Name) return other.MemberId;
               return INT_MIN;
          }
          void BorrowBook(int BorrowId){BookId.push_back(BorrowId);}
          bool ReturnBook(int ReturnId){
               bool returned = false;
               for (int Book : BookId) 
                    if (Book = ReturnId){
                         BookId.erase(static_cast <vector <int> :: iterator> (&Book));
                         returned = true;
                    }
               return returned;
          }
          void printMemberData(void){
               cout<<"\nMember Name : "<<Name
                   <<"\tAge : "<<age
                   <<"\tMember Id : "<<MemberId<<endl;
          }
          vector <int> getBookId(void){return BookId;}
};

void Display_Table(char Access_Type, int count, string type, vector <unique_ptr <Member>> &Members, vector <unique_ptr <Book>> &Books);
void Borrowed_Books(unique_ptr <Member> &Current_Member, vector <unique_ptr <Book>> &Books);
void Membership_Card(unique_ptr <Member> &Current_Member);