//Mission 5 : Quiz Master -> A Quiz Game

/* OVERVIEW :
This C++ program is a quiz game where users answer multiple-choice questions to earn points. It provides a set of questions with multiple-choice answers and evaluates the user's responses. The game continues until the user decides to exit or restart.

DEPENDENCIES :
   -> Standard Libraries: <iostream>, <string>
   -> Custom Header Files:
        * "Display_Basics.hpp"

VARIABLES :
   -> vector <string> Questions:
        * Contains a list of five quiz questions.
   -> vector <string> Answers:
        * Contains the correct answers to the quiz questions.
   -> array <vector <string>, 5> Choices:
        * Contains possible answers for each question.

FUNCTIONS :
   -> char Mission5_Bottom_Line(int page):
        * Displays different prompts based on the `page` argument.
        * Handles user input for restarting the quiz, continuing to the next question, or viewing results.
        * Returns a character to indicate the user's choice.

WORKING :
   -> Main game loop where the quiz starts.
   -> Displays questions and multiple-choice options.
   -> Evaluates user answers and updates the score.
   -> Handles options to restart or exit the game.
   -> Displays the final score and prompts for restart or exit.

TEMPLATES FOR ALL PAGES : Provided by "Display_Basics.hpp" which includes various function methods for Page Templates. These include:
   -> Headings: "Display_Basics.hpp -> Header()"
   -> Word Padding to center: "Display_Basics.hpp -> padding [] () {}"
   -> Footers and Bottom Lines: "Display_Basics.hpp -> Bottom_Line(), Bottom_Line_2()"
   -> Main Menus: "Display_Basics.hpp -> Main_Menu()"
   -> Exit Window: "Display_Basics.hpp -> Exiting_Window()"
   -> Entrance Window: "Display_Basics.hpp -> Entrance_Window()"

USAGE : The user interacts with the program through a series of quiz questions:
   1. Answer Questions: Choose from multiple-choice answers for each question.
   2. View Results: After answering all questions, view the total score.
   3. Restart or Exit: Choose to restart the quiz or exit the program.*/

#include <iostream>
#include "Display_Basics.hpp"
#include <string>
using namespace std;

char Mission5_Bottom_Line (int page){
     if (page == 1){
          printline;
          char restart_choice;
          cout<<"\t\t\t\t\t  Enter R to go to Restart or any other key to exit : ";
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
          return 'M';
     }
     return '\0';
}

vector <string> Questions {"Who invented Computer? ", "Which is the largest planet in our Solar System? ", "Which famous scientist developed the theory of General Relativity? ", "Which planet is known as the Red Planet? ", "Who invented C++ Programming Language? "};
vector <string> Answers {"Charles Babbage", "Jupiter", "Albert Einstein", "Mars", "Bjarne Stroustrup"};
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
               if (ChoiceNum > 0 && ChoiceNum < 5 && Choices[count - 1][ChoiceNum - 1] == Answers[count - 1]){
                    cout<<"\nYour answer was correct..."<<endl;
                    Marks += 10;
                    if (count < 5) Mission5_Bottom_Line(2);
                    else{restart_choice = Mission5_Bottom_Line(3);}
               }
               else if (ChoiceNum > 0 && ChoiceNum < 5){
                    cout<<"\nSorry Wrong Option Choosen. Correct Answer : "<<Answers[count - 1]<<endl;
                    if (count < 4) Mission5_Bottom_Line(2);
                    else {restart_choice = Mission5_Bottom_Line(3);}
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