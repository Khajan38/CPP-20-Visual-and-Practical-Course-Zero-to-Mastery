//Classes Declaration File.hpp

/*OVERVIEW : 
This file declares the primary classes used in the Library Management System, including Book, Member, and Library. It also includes declarations for various helper functions. The Library class maintains collections of books and members and provides methods for manipulating these collections.

CLASSES : 
   -> Book:
       * Attributes:
          1. string Title: The title of the book..
          2. string Author: The author of the book.
          3. int YearPublished: The year the book was published.
          4. int BookId: A unique identifier for the book.
          5. int BorrowId: The ID of the member who borrowed the book, if any.
          6. string Status: The status of the book (e.g., "Available", "Borrowed").

       * Constructors:
          1. Book(string Title, string Author, int YearPublished): Parameterized constructor for initializing book details.
          2. Book(): Default constructor with minimal initialization.

       * Destructor:
          1. ~Book(): Adjusts the book count when a book is destroyed.

       * Methods:
          1. void printBookData(): Prints the book's data.

   -> Member:
       * Attributes:
          1. string Name: The name of the member.
          2. int age: The age of the member.
          3. int MemberId: A unique identifier for the member.
          4. vector<int> BookId: A list of book IDs borrowed by the member.

       * Constructors:
          1. Member(string Name, int age): Parameterized constructor for initializing member details.
          2. Member(string Name): Constructor for initializing with a name.
          3. Member(): Default constructor with minimal initialization.

       * Destructor:
          1. ~Member(): Adjusts the member count when a member is removed.

       * Methods:
          1. int operator==(Member &other): Overloads the equality operator to compare members by name.
          2. void BorrowBook(int BorrowId): Adds a borrowed book ID to the member's list.
          3. bool ReturnBook(int ReturnId): Removes a book ID from the member's list if it exists.
          4. void printMemberData(): Prints the member's data.
          5. vector<int> getBookId(): Returns the list of borrowed book IDs.

   -> Library:
       * Attributes:
          1. vector<unique_ptr<Book>> Books: A collection of books in the library.
          2. vector<unique_ptr<Member>> Members: A collection of members in the library.
          3. static int book_count: A static counter for the number of books.
          4. static int member_count: A static counter for the number of members.

       * Constructors:
          1. Library(): Constructor that initializes the library with some books and members.

       * Methods:
          1. static void count_change(string change_type): Static method for adjusting book and member counts.
          2. void AddBook(): Adds a new book to the library.
          3. void AddMember(): Adds a new member to the library.
          4. void DisplayBooks(char Access_Type): Displays a list of books.
          5. void DisplayMembers(char Access_Type): Displays a list of members.
          6. void RemoveBook(char Access_Type): Removes a book from the library.
          7. void RemoveMember(char Access_Type): Removes a member from the library.
          8. vector<unique_ptr<Member>> &getMembers(): Returns the list of members.
          9. vector<unique_ptr<Book>> &getBooks(): Returns the list of books.
          10. static int getbook_count(): Returns the total number of books.
          11. static int getmember_count(): Returns the total number of members.

HELPER FUNCTIONS : 
   -> void Display_Table(char Access_Type, int count, string type, vector<unique_ptr<Member>> &Members, vector<unique_ptr<Book>> &Books): Displays a table of either books or members.

   -> void Borrowed_Books(unique_ptr<Member> &Current_Member, vector<unique_ptr<Book>> &Books): Displays a list of books borrowed by a specific member.

   -> void Membership_Card(unique_ptr<Member> &Current_Member): Displays the membership card details for a specific member.*/

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
          Library ();
          //Defined in Library Functions File.hpp
          void AddBook (void);
          void AddMember (void);
          void DisplayBooks (char Access_Type);
          void DisplayMembers (char Access_Type);
          void RemoveBook (char Access_Type);
          void RemoveMember (char Access_Type);
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
               for (vector <int> :: iterator itr = BookId.begin(); itr != BookId.end(); itr++) 
                    if (*itr == ReturnId){
                         BookId.erase(itr);
                         returned = true; 
                         break;
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

Library:: Library (){
     Books.push_back(make_unique <Book> ("Rich Dad Poor Dad", "Robert Kiyosaki", 1997));
     Books.push_back(make_unique <Book> ("Think and Grow Rich", "Napolean Hill", 1937));
     Books.push_back(make_unique <Book> ("A Brief History of Time", "Stephen Hawking", 1988));
     Books.push_back(make_unique <Book> ("Harry Potter", "J.K. Rowling", 1997));
     Books.push_back(make_unique <Book> ("The Da Vinci Code", "Dan Brown", 2003));
     Books.push_back(make_unique <Book> ("To Kill a Mockingbird", "Harper Lee", 1960));
     Books.push_back(make_unique <Book> ("The Great Gatsby", "F. Scott Fitzgerald", 1925));
     Books.push_back(make_unique <Book> ("1984", "George Orwell", 1949));
     Books.push_back(make_unique <Book> ("Pride and Prejudice", "Jane Austen", 1813));
     Books.push_back(make_unique <Book> ("The Catcher in the Rye", "J.D. Salinger", 1951));
     Members.push_back(make_unique <Member> ("Alan Smith", 32));
     Members.push_back(make_unique <Member> ("Barry Williams", 25));
     Members.push_back(make_unique <Member> ("Cloe Jhonson", 28));
     Members.push_back(make_unique <Member> ("Dwayne Jones", 23));
     Members.push_back(make_unique <Member> ("Elle Rodriguez", 21));
     Books[2]->Status = "Borrowed";
     Books[2]->BorrowId = 1328;
     Members[3]->BorrowBook(5846);
     Books[4]->Status = "Borrowed";
     Books[4]->BorrowId = 1328;
     Members[3]->BorrowBook(5848);
     Books[7]->Status = "Borrowed";
     Books[7]->BorrowId = 1330;
     Members[3]->BorrowBook(5851);
}