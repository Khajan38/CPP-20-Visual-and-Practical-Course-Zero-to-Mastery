//Mission 5 : Quiz Master -> A Quiz Game

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <thread>
#include  <chrono>
using namespace std;

#define line cout<<endl<<"====================================================================================================================================="<<endl<<endl
#define sleep(timed) this_thread::sleep_for (chrono::seconds(timed))
#define clear_screen system("cls")

void Exiting_Window (void);

void Header (string Heading){
     clear_screen; line;
     cout<<"\b\t\t\t\t\t\t"<<Heading<<endl; line;
}

char Bottom_Line (int page){
     if (page == 0){
          cout<<"\n\n"; line;
          cout <<"\n\t\t\t\t\t\t\t     Continuing..." << std::endl;
          sleep(2);
          return '\0';
     }
     else if (page == 1){
          line;
          char restart_choice;
          cout<<"\t\t\t\t\t  Enter R to go to Restart or any other key to exit : ";
          cin.ignore(INT_MAX, '\n');
          cin>>restart_choice;
          return restart_choice;
     }
     else if (page == 2){
          line;
          cout<<"\t\t\t\t\t          Press any key to go to Next Question : ";
          cin.ignore(INT_MAX, '\n');
          cin.get();
          return '\0';
     }
     else if (page == 5){
          line;
          cout<<"\t\t\t\t\t          Press any key to go to Result Window : ";
          cin.ignore(INT_MAX, '\n');
          cin.get();
          return '\0';
     }
     else if (page == 3) {cout<<"\n"; line; sleep(page); return '\0';}
     return '\0';
}
void Entrance_Window (char restart_choice){
     Header("QUIZ MASTER : TEST YOUR KNOWLEDGE");
     cout<<"\n\n\t\t\t         Welcome to QUIZ MASTER: Sharpen Your Mind, One Question at a Time!";
     cout<<"\n\n\n\t\t\t\t\t\t   Press any key to continue : ";
     if (restart_choice == 'R') cin.ignore(INT_MAX, '\n');
     cin.get();
     Bottom_Line(0);
}

void Exiting_Window (void){
     Header("    QUIZ MASTER : EXIT WINDOW");
     cout<<"\n\t\t\t\t\t\t\t     Thank You!"
          <<"\n\t\t\t\t\t              for playing QUIZ MASTER..."
          <<"\n\n\n\t\t\t\t\t\t       WE WILL WAIT FOR YOU!..."<<endl;
     Bottom_Line(3);
     system("cls");
     exit(0);
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
     while (true){
          Entrance_Window(restart_choice);
          int count = 1, ChoiceNum = 0;
          for (vector <string> :: iterator itr_Q{Questions.begin()}; itr_Q != Questions.end(); itr_Q++, count++){
               Header("      QUIZ MASTER : QUESTION " + count);
               cout<<endl<<*itr_Q<<endl<<endl; 
               int option_choice = 1;
               for (vector <string> :: iterator itr_A{Choices[count - 1].begin()}; itr_A != Choices[count-1].end(); itr_A++, option_choice++)
                    cout<<"\t"<<option_choice<<". "<<*itr_A<<endl;
               cout<<"\nEnter Your Answer : "; cin>>ChoiceNum;
               if (Choices[count - 1][ChoiceNum -1] == Answers[count - 1]){
                    cout<<"\nYour answer was correct..."<<endl;
                    Marks += 10;
                    if (count < 5) Bottom_Line(2);
                    else Bottom_Line(5);
               }
               else if (ChoiceNum > 0 && ChoiceNum < 5){
                    cout<<"\nSorry Wrong Option Choosen. Correct Answer : "<<Answers[count - 1]<<endl;
                    if (count < 4) Bottom_Line(2);
                    else Bottom_Line(5);
               }
               else {
                    cout<<"\nOption Choosen out of Range..."<<endl;
                    restart_choice = Bottom_Line(1);
                    if (restart_choice != 'R') Exiting_Window();
                    else break;
               }
          }
          if (restart_choice != 'R'){
               Header("    QUIZ MASTER : RESULTS WINDOW");
               cout<<"\n\t\t\t\t\t               Processing your Score...";
               sleep(2);
               cout<<"\n\nYou have scored : "<<Marks<<"/50."<<endl;
               restart_choice = Bottom_Line(1);
               if (restart_choice != 'R') Exiting_Window();
          }
     }
     return 0;
}