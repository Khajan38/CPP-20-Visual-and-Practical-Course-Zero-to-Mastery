//Main Header File.hpp

/*OVERVIEW : 
This file serves as a central header for the Task Management System. It defines the core structure for a task and includes necessary functionalities like the task counter and login mechanism. The file also includes the implementation of the Login_Window function, which manages user authentication.

DEPENDENCIES : 
   -> Standard Libraries: <iostream>, <string>, <thread>, <chrono>
   -> Custom Header Files:
        * "..\Display_Basics.hpp"

GLOBAL VARIABLES :
   -> int Task::count_Tasks: A static variable used to keep track of the total number of tasks.

STRUCTURES TASK:
   -> Attributes:
        * string Name: The name of the task.
        * string Description: A brief description of the task.
        * bool Completed: A flag indicating whether the task is completed.

   -> Constructors:
        * Task(string Name, string Description, bool Completed): Constructs a task with the given name, description, and completion status.
        * Task(string Name, string Description): Constructs a task with the given name and description, defaulting the completion status to false.

   -> Methods:
        * static void count_Task_inc(): Increments the task count.
        * bool operator==(const Task &other) const: Compares two tasks for equality based on their attributes.

   -> Destructor:
        * ~Task(): Decrements the task count upon destruction.

FUNCTIONS void Login_Window() :
   -> DESCRIPTION : 
        * Manages the login process for the Task Management System. 
        * The user is prompted to enter a password to gain access. 
        * The function provides three chances for correct entry, after which the system locks for a certain time before allowing retry.

   -> Parameters: None

   -> Returns: None
        
   -> Implementation Details:
        * Displays a welcome message and prompts the user for a password.
        * If the password is correct ("Task_Tracker"), the function proceeds.
        * If incorrect, the user is given a limited number of attempts. After exhausting the attempts, the system locks for an increasing amount of time with each set of incorrect entries.

USAGE : 
   -> This header file should be included in the main source file of the Task Management System to provide access to the Task structure and Login_Window function. It ensures that tasks are properly tracked and that user access is securely managed.*/

#pragma once //To include these headers only once if defined again in Main File

#include <iostream>
#include "..\Display_Basics.hpp"
using namespace std;

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

void Login_Window (void){
     int chances = 2, time_break = 5;
     string password = "Task_Management_System"; //Password = Task_Tracker
     while (true){
          Header("TASK TRACKER : TASK MANAGEMENT SYSTEM");
          cout<<endl<<padding("Welcome to TASK TRACKER: Simplifying Your Workflow, One Task at a Time!")<<"Welcome to TASK TRACKER: Simplifying Your Workflow, One Task at a Time!"<<endl;
          cout<<endl<<endl<<padding("Enter Password to continue : ")<<"Enter Password to continue : ";
          cin>>password;
          if (password == "Task_Tracker") break;
          cout<<endl<<endl<<padding("Wrong Password... You have " + to_string(chances)+" more chances left...")<<"Wrong Password... You have " + to_string(chances)+" more chances left...";
          if (chances != 0){
               cout<<"\n\n"; line;
               this_thread::sleep_for(chrono::seconds(1));
               chances--;
          }
          else {
               cout<<endl<<padding("App is locked for " + to_string(time_break) + " seconds...")<<"App is locked for " + to_string(time_break) + " seconds...";
               cout<<"\n\n"; line;
               this_thread::sleep_for(chrono::seconds(time_break));
               chances = 3;
               time_break += 5;
          }
     }
     Bottom_Line(0);
}