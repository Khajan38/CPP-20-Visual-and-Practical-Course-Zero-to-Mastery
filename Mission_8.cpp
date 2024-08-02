//Mission 8 : Inventory System

#include <iostream>
#include "Display_Basics.hpp"
using namespace std;

class Book{
     string Title, Author;
     int YearPublished;
     public :
          explicit Book (string Title, string Author, int YearPublished) : Title(Title), Author(Author), YearPublished(YearPublished){};
          //Getter Methods
};

class Member{
     string Name;
     int MemberId;
     public:
          Member (string Name, int MemberId) : Name(Name), MemberId(MemberId){};
          //Getter Methods
};

class Library{
     vector <Book> Books; 
     vector <Member> Members;
     3
}