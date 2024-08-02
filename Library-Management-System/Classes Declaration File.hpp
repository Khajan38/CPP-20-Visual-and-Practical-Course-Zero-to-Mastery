/*Contains Declarations of classes :
     -> Book : Title, Author and PublishingYear
     -> Member : MemberId, Name
     -> Library : 
          * Books - Vectors containing data of all books
          * Members - Vectors containing data of all members
          * book_count - For counting total no. of Books
          * member_count - For counting total no. of Members
*/

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
     friend void Display_Table(int count, string type, vector <unique_ptr <Member>> Members, vector <unique_ptr <Book>> Books);
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
               Members.push_back(make_unique <Member> ("Alan Smith", member_count+1));
               Members.push_back(make_unique <Member> ("Barry Williams", member_count+1));
               Members.push_back(make_unique <Member> ("Clarke Jhonson", member_count+1));
          }
          //Defined in Library Functions File.hpp
          void AddBook (void);
          void AddMember (void);
          void DisplayBooks (void);
          void DisplayMembers (void);
          vector <unique_ptr <Member>> &getMembers (void){return Members;}
};
int Library::book_count = 5843; //Static Member Initialization
int Library::member_count = 1325; //Static Member Initialization

class Book{
     string Title, Author;
     int YearPublished;
     string Status;
     friend void Library :: AddBook(void); //Let access to Title, Author and Year Published
     friend void Display_Table(int count, string type, vector <unique_ptr <Member>> Members, vector <unique_ptr <Book>> Books); //Let access to Title, Author and Year Published
     public :
          explicit Book (string Title, string Author, int YearPublished) : Title(Title), Author(Author), YearPublished(YearPublished), Status("Available"){Library::count_change("Book++");}; //Setting a Parameterized Constructor
          Book (void) : Status("Available"){Library::count_change("Book++");}; //Setting a Partially Blank Constructor
          ~ Book (void) {Library::count_change("Book--");}; //Modifying Destructors
};

class Member{
     string Name;
     int MemberId;
     vector <int> BookId{};
     friend void Library :: AddMember(void); //Let access to Name and Member ID
     friend void Display_Table(int count, string type, vector <unique_ptr <Member>> Members, vector <unique_ptr <Book>> Books);//Let access to Name and Member ID
     public:
          Member (string Name, int MemberId) : Name(Name), MemberId(MemberId){Library::count_change("Member++");}; //Setting a Parameterized Constructor
          Member (void){Library::count_change("Member++");}; //Setting a Blank Constructor
          ~ Member (void) {Library::count_change("Member--");}; //Modifying Destructors
          bool operator == (Member &other){
               if (this->MemberId == other.MemberId && this->Name == other.Name) return true;
               return false;
          }
};

void Display_Table(int count, string type, vector <unique_ptr <Member>> Members, vector <unique_ptr <Book>> Books);