#pragma once //To include these headers only once if defined again in Main File

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

#define line cout<<endl<<"====================================================================================================================================="<<endl<<endl
#define sleep(timed) this_thread::sleep_for (chrono::seconds(timed))
#define clear_screen system("cls")

struct Task {
     string Name;
     string Description;
     bool Completed;
     static int count_Tasks; //To count total tasks
     explicit Task (string Name, string Description, bool Completed){
          this -> Name = Name;
          this -> Description = Description;
          this -> Completed = Completed;
          count_Task_inc();
     }
     explicit Task (string Name, string Description) : Name(Name), Description(Description){count_Task_inc();}
     static void count_Task_inc (void){count_Tasks++;}
     bool operator == (const Task &other) const{
          return (this->Name == other.Name && this->Description == other.Description && this->Completed == other.Completed);
     }
     ~Task (void){count_Tasks--;}
};
int Task ::count_Tasks = 0;

namespace Main_Functions{
     void Exiting_Window (void);
}

void Header (string Heading){
     clear_screen; line;
     cout<<"\b\t\t\t\t\t\t"<<Heading<<endl; line;
}

void Bottom_Line (int page){
     if (page == 1){
          line;
          cout<<"\t\t\t\t\t\t     Initiating your request...";
          sleep(2);
          return;
     }
     else if (page == 2){
          line;
          char menu_choice;
          cout<<"\t\t\t\t\t  Enter M to go to Main Menu or any other key to exit : ";
          cin>>menu_choice;
          if (menu_choice != 'M') Main_Functions::Exiting_Window();
          return;
     }
     else if (page == 0){
          cout<<"\n\n"; line;
          cout <<"\n\t\t\t\t\t\t\t     Continuing..." << std::endl;
          sleep(2);
     }
     else if (page == 3) {cout<<"\n"; line; sleep(page);}
}

namespace Main_Functions{

     void Entrance_Window (void){
          int chances = 2, time_break = 5;
          string password = "Task_Management_System"; //Password = Task_Tracker
          while (true){
               Header("TASK TRACKER : TASK MANAGEMENT SYSTEM");
               cout<<"\n\n\t\t\t       Welcome to TASK TRACKER: Simplifying Your Workflow, One Task at a Time!";
               cout<<"\n\n\n\t\t\t\t\t\t  Enter Password to continue : ";
               cin>>password;
               if (password == "Task_Tracker") break;
               cout<<"\n\n\t\t\t\t\t   Wrong Password... You have "<<chances<<" more chances left...";
               if (chances != 0){
                    cout<<"\n\n"; line;
                    this_thread::sleep_for(chrono::seconds(1));
                    chances--;
               }
               else {
                    cout<<"\n\t\t\t\t\t\t    App is locked for "<<time_break<<" seconds...";
                    cout<<"\n\n"; line;
                    this_thread::sleep_for(chrono::seconds(time_break));
                    chances = 3;
                    time_break += 5;
               }
          }
          Bottom_Line(0);
     }

     int Main_Menu (void){
          Header("      TASK TRACKER : MAIN MENU");
          cout<<"\n\t\t\t\t\t\t1. Add New Task\
          \n\t\t\t\t\t\t2. Arrange Active Tasks\
          \n\t\t\t\t\t\t3. Mark Task as Completed\
          \n\t\t\t\t\t\t4. Display Tasks Window\
          \n\t\t\t\t\t\t5. Delete Specific Task\
          \n\t\t\t\t\t\t6. Help and Feedback\
          \n\t\t\t\t\t\t7. Exit\
          \n\nEnter your choice : ";
          int choice; cin>>choice;
          if (choice >= 1 && choice <= 7) Bottom_Line(1);
          return choice;
     }
}

void Main_Functions::Exiting_Window (void){
     Header("      TASK TRACKER : EXIT WINDOW");
     cout<<"\n\t\t\t\t\t\t\t     Thank You!"
          <<"\n\t\t\t\t\t\t for using Task Management System..."
          <<"\n\n\n\t\t\t\t\t\t       WE WILL WAIT FOR YOU!..."<<endl;
     Bottom_Line(3);
     system("cls");
     exit(0);
}