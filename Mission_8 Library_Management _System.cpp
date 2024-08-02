//Mission 8 : Inventory System

#include <iostream>
#include <memory>
#include "Display_Basics.hpp"
using namespace std;

class Book; 
class Member;
class Library {
     vector <unique_ptr <Book>> Books; 
     vector <unique_ptr <Member>> Members;
     static int book_count, member_count; //Static Data Member
     public :
          static void count_change(string change_type){ //Static Data Function
               if (change_type == "Book++") book_count++;
               else if (change_type == "Book--") book_count--;
               else if (change_type == "Member++") member_count++;
               else member_count--;
          }
          void AddBook (void);
          void AddMember (void);
};
int Library::book_count = 0;
int Library::member_count = 0;

class Book{
     string Title, Author;
     int YearPublished;
     friend void Library :: AddBook(void);
     public :
          explicit Book (string Title, string Author, int YearPublished) : Title(Title), Author(Author), YearPublished(YearPublished){Library::count_change("Book++");}; //Setting a Parameterized Constructor
          Book (void) {Library::count_change("Book++");}; //Setting a Blank Constructor
          ~ Book (void) {Library::count_change("Book--");}; //Modifying Destructors
          //Getter Methods
};

class Member{
     string Name;
     int MemberId;
     friend void Library :: AddMember(void);
     public:
          Member (string Name, int MemberId) : Name(Name), MemberId(MemberId){Library::count_change("Member++");}; //Setting a Parameterized Constructor
          Member (void) {Library::count_change("Member++");}; //Setting a Blank Constructor
          ~ Member (void) {Library::count_change("Member--");}; //Modifying Destructors
          //Getter Methods
};

void Library :: AddMember(void){
     Books.push_back(make_shared <Book>());
     
}