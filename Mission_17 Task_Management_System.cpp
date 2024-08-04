//Mission_17 Task_Management_System.cpp

/*OVERVIEW : 
This C++ program serves as a Task Management System that allows users to manage tasks by adding new tasks, arranging active tasks, marking tasks as complete, displaying tasks, deleting tasks, and accessing help and feedback. It uses various C++ Standard Library containers such as list, map, and vector for efficient data management.

DEPENDENCIES :
   -> Standard Library Headers: <iostream>, <memory>, <array>, <vector>, <list>, <map>
   -> Project-Specific Headers:
        * "Task-Management-System\Main Header File.hpp"
        * "Task-Management-System\Function Header File.hpp"
        * "Task-Management-System\Display_Functions\Display Header File.hpp"
        * "Display_Basics.hpp"

GLOBAL VARIABLES : 
   -> list<Task> Tasks: A list storing all tasks.
   -> map<int, Task *> TaskMap: Maps task IDs to task objects.
   -> list<Task>::iterator Completed_Id: Iterator marking the beginning of completed tasks in the Tasks list.
   -> array<string, 2> Exit_Parts: Stores strings used for exit messages.

FUNCTIONS:
   -> char Main_Menu(const vector<string>& Menu_items)
        * Displays the main menu and returns the user's choice.
        * Options include adding new tasks, arranging tasks, marking tasks as completed, displaying tasks, deleting tasks, and accessing help and feedback.

   -> int Add_Task(unique_ptr<string> Name, unique_ptr<string> Description, list<Task>& Tasks, list<Task>::iterator& Completed_Id, map<int, Task*>& TaskMap)
        * Adds a new task with the given name and description.
        * Updates the Tasks list and TaskMap with the new task and returns the task ID.

   -> int Active_Task_List(const list<Task>& Tasks, list<Task>::iterator& Completed_Id)
        * Displays the list of active tasks and prompts the user to select a task ID.

   -> void Arrange_Active_Tasks(const string& Priority, list<Task>& Tasks, map<int, Task*>& TaskMap, list<Task>::iterator& Completed_Id)
        * Rearranges the active tasks based on the specified priority order.

   -> int Marking_Completed(int* taskId, map<int, Task*>& TaskMap, list<Task>& Tasks, list<Task>::iterator& Completed_Id)
        * Marks a task as completed by moving it to the completed section of the Tasks list and updating the task ID.

   -> void Display_Menu(const list<Task>& Tasks, list<Task>::iterator& Completed_Id)
        * Displays the tasks based on their status (active or completed).

   -> void Delete_Task(int taskId, list<Task>& Tasks, map<int, Task*>& TaskMap, list<Task>::iterator& Completed_Id)
        * Deletes a specific task from the Tasks list and TaskMap based on the provided task ID.

   -> void Exiting_Window(const array<string, 2>& Exit_Parts)
        * Displays the exit message and gracefully shuts down the program.

   -> void Bottom_Line_2(const array<string, 2>& Exit_Parts)
        * Displays a bottom line with exit parts for consistent UI.

USAGE : 
To run the Task Management System, compile and execute the Mission_17 Task_Management_System.cpp file. The program will guide the user through various task management functionalities, allowing them to interact with tasks through a menu-driven interface.*/

#include <iostream>
//Using Header File since Modules are still developing in gcc and creating problems in compilation
#include "Task-Management-System\Main Header File.hpp"
#include "Task-Management-System\Function Header File.hpp"
#include "Task-Management-System\Display_Functions\Display Header File.hpp"
#include "Display_Basics.hpp"
#include <memory>

using namespace std;

int main(){
     char menu_choice {'A'};
     char program_choice {'M'};
     list <Task> Tasks; //Stores all Tasks
     map <int, Task *> TaskMap; //TaskMap maps Tasks with their TaskId (their position in Tasks list)
     list <Task> :: iterator Completed_Id {Tasks.begin()}; //Iterator to index where Completed Tasks start in Tasks
     Login_Window();
     array <string, 2> Exit_Parts {"TASK TRACKER", "Task Tracker"};
     while (program_choice == 'M'){
          vector <string> Menu_items {"TASK TRACKER", "Add New Task", "Arrange Active Tasks", "Mark Task as Completed", "Display Tasks Window", "Delete Specific Task", "Help and Feedback", "Exit"};
          menu_choice = Main_Menu(Menu_items);
          switch (menu_choice){
               case 'A':{
                    Header("TASK TRACKER : ADD TASK WINDOW");
                    unique_ptr <string> Name{make_unique <string>()};
                    unique_ptr <string> Description{make_unique <string>()};
                    //getline is used to input text with white spaces also
                    cin.ignore(INT_MAX, '\n'); //To remove input buffer
                    cout<<"\nEnter Task : "; getline(cin, *Name);
                    cout<<"\nEnter Description : "; getline(cin, *Description);
                    int taskID = Add_Task(move(Name), move(Description), Tasks, Completed_Id, TaskMap);
                    //move() with unique pointer let us transfer the ownership of unique_ptr to fucntion ptrs
                    cout<<" Task added successfully with ID : "<<taskID<<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'B':{
                    Header("TASK TRACKER : ARRANGE TASK"); cout<<endl;
                    int taskId = Active_Task_List(Tasks, Completed_Id);
                    if (taskId){
                         string Priority = "";
                         cout<<"\nEnter Priority of tasks as (2-3-1-4...) : ";
                         cin>>Priority;
                         if (Priority.size() == 2*(taskId) - 1)
                              Arrange_Active_Tasks(Priority, Tasks, TaskMap, Completed_Id);
                         else 
                              cout<<"\nInvalid Input Entered..."<<endl;
                    }
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'C':{
                    Header("TASK TRACKER : MARK TASK COMPLETE");
                    int taskId = -1;
                    cout<<"\nEnter Task ID : ";
                    cin>>taskId;
                    int TaskId = Marking_Completed(& taskId, TaskMap, Tasks, Completed_Id);
                    if (TaskId == Task::count_Tasks) cout<<" Task with Id : "<<taskId<<" marked completed successfully with new ID : "<<TaskId<<endl;
                    else cout<<" Task with ID : "<<taskId<<" not found in Active Tasks"<<endl;
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'D':{
                    Display_Menu(Tasks, Completed_Id);
                    break;
               }
               case 'E':{
                    Header("TASK TRACKER : DELETE TASK COMPLETE");
                    int taskId = -1;
                    cout<<"\nEnter Task ID : ";
                    cin>>taskId;
                    Delete_Task(taskId, Tasks, TaskMap, Completed_Id);
                    Bottom_Line_2(Exit_Parts);
                    break;
               }
               case 'F':
                    system("python Task-Management-System\\Help_and_Feedback\\Help_and_Feedback.py");
                    break;
               case 'G':
                    Exiting_Window(Exit_Parts);
               default:
                    cout<<padding("Enter a valid request...")<<"Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}