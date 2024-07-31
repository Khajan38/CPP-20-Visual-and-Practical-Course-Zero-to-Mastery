//Mission 5 : Quiz Master -> A Quiz Game

#include <iostream>
#include "Display_Basics.hpp"
#include <string>
using namespace std;

char Mission5_Bottom_Line (int page){
     if (page == 1){
          printline;
          char restart_choice;
          cout<<"\t\t\t\t\t  Enter R to go to Restart or any other key to exit : ";
          cin.ignore(INT_MAX, '\n');
          cin>>restart_choice;
          return restart_choice;
     }
     else if (page == 2){
          printline;
          cout<<"\t\t\t\t\t          Press any key to go to Next Question : ";
          cin.ignore(INT_MAX, '\n');
          cin.get();
          return '\0';
     }
     else if (page == 3){
          printline;
          cout<<"\t\t\t\t\t          Press any key to go to Result Window : ";
          cin.ignore(INT_MAX, '\n');
          cin.get();
          return '\0';
     }
     return '\0';
}

vector <string> Questions {"Who invented Computer? ", "Which is the largest planet in our Solar System? ", "Which famous scientist developed the theory of General Relativity? ", "Which planet is known as the Red Planet? ", "Who invented C++ Programming Language? "};
vector <string> Answers {"Charles Babbage", "Jupiter", "Albert Einstein", "Mars", "Bjarne Stroustrup "};
array <vector <string>, 5> Choices {
     vector <string> {"Steve Jobs", "James Gosling", "Charles Babbage", "Bill Gates"},
     vector <string> {"Earth", "Jupiter", "Neptune", "Saturn"},
     vector <string> {"Stephen Hawking", "Marie Curie", "Nikola Tesla", "Albert Einstein"},
     vector <string> {"Mars", "Mercury", "Jupiter", "Earth"},
     vector <string> {"Bjarne Stroustrup", "Dennis Riche", "James Gosling", "Guido van Rossum"}
};

int main(){
     int Marks {0};
     char restart_choice = 'M';
     array <string, 2> Exit_Parts {"QUIZ MASTER", "Quiz Master"};
     while (true){
          array <string, 3> Entrance_Parts {"QUIZ MASTER : TEST YOUR KNOWLEDGE", "Welcome to QUIZ MASTER: Sharpen Your Mind, One Question at a Time!", "Press any key to continue : "};
          Entrance_Window(restart_choice, Entrance_Parts);
          int count = 1, ChoiceNum = 0;
          for (vector <string> :: iterator itr_Q{Questions.begin()}; itr_Q != Questions.end(); itr_Q++, count++){
               Header("QUIZ MASTER : QUESTION " + to_string(count));
               cout<<endl<<*itr_Q<<endl<<endl; 
               int option_choice = 1;
               for (vector <string> :: iterator itr_A{Choices[count - 1].begin()}; itr_A != Choices[count-1].end(); itr_A++, option_choice++)
                    cout<<"\t"<<option_choice<<". "<<*itr_A<<endl;
               cout<<"\nEnter Your Answer : "; cin>>ChoiceNum;
               if (Choices[count - 1][ChoiceNum - 1] == Answers[count - 1]){
                    cout<<"\nYour answer was correct..."<<endl;
                    Marks += 10;
                    if (count < 5) Mission5_Bottom_Line(2);
                    else{Mission5_Bottom_Line(3); restart_choice = 'R';}
               }
               else if (ChoiceNum > 0 && ChoiceNum < 5){
                    cout<<"\nSorry Wrong Option Choosen. Correct Answer : "<<Answers[count - 1]<<endl;
                    if (count < 4) Mission5_Bottom_Line(2);
                    else Mission5_Bottom_Line(3);
               }
               else {
                    cout<<"\nOption Choosen out of Range..."<<endl;
                    restart_choice = Mission5_Bottom_Line(1);
                    if (restart_choice != 'R') Exiting_Window(Exit_Parts);
                    else break;
               }
          }
          if (restart_choice != 'R'){
               Header("QUIZ MASTER : RESULTS WINDOW");
               cout<<endl<<endl<<padding("Processing your Score...")<<"Processing your Score...";
               sleep(2);
               cout<<"\n\nYou have scored : "<<Marks<<"/50."<<endl;
               restart_choice = Mission5_Bottom_Line(1);
               if (restart_choice != 'R') Exiting_Window(Exit_Parts);
          }
     }
     return 0;
}