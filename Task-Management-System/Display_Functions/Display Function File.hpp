//Display Function.hpp

/*OVERVIEW : 
The Display Function.hpp file is a header file within the Task Management System (TMS), specifically the "TASK TRACKER" application. It defines several functions that facilitate displaying tasks, including active tasks, completed tasks, and specific task details.

DEPENDENCIES : 
   -> Standard Libraries: <iterator>, <format>, <list>, <map>
   -> Custom Header Files:
        * #include "../Main Header File.hpp"
        * #include "../../Display_Basics.hpp"

FUNCTIONS : 
   -> int Active_Task_List(list<Task>& Tasks, list<Task>::iterator Completed_Id)
        * Description: This function displays all active tasks from the list of tasks.
        * Returns: The number of active tasks.
        * Details: Iterates through the tasks from the beginning to Completed_Id. If there are no active tasks, it prints "Currently No Active Tasks...". Otherwise, it formats and displays each active task's ID, name, and description.

   -> void Completed_Task_List(int taskId, list<Task>& Tasks, list<Task>::iterator Completed_Id)
        * Description: This function displays all completed tasks..
        * Details: Iterates from Completed_Id to the end of the list. If there are no completed tasks, it prints "No Tasks Completed...". Otherwise, it formats and displays each completed task's ID, name, and description.

   -> void Display_All_Tasks(list<Task>& Tasks, list<Task>::iterator Completed_Id)
        * Description: This function displays all tasks, both active and completed.
        * Details: Displays a header indicating the start of the "DISPLAY ALL TASKS" section. Calls Active_Task_List to display active tasks. Calls Completed_Task_List to display completed tasks.

   -> void Display_Specific_Task(list<Task>& Tasks, const int* taskId)
        * Description: This function displays details of a specific task based on its ID.
        * Details: Validates the provided task ID. If the task ID is valid, it displays the task's name, description, and completion status. If the task ID is invalid, it prints an error message.

   -> void Display_Active_Tasks(list<Task>& Tasks, list<Task>::iterator Completed_Id)
        * Description: This function displays only the active tasks.
        * Details: Displays a header indicating the start of the "DISPLAY ACTIVE TASKS" section. Calls Active_Task_List to display the active tasks.

   -> void Display_Completed_Tasks(list<Task>& Tasks, list<Task>::iterator Completed_Id)
        * Description: This function displays only the completed tasks.
        * Details: Displays a header indicating the start of the "DISPLAY COMPLETED TASKS" section. Calls Completed_Task_List to display the completed tasks.

USEAGE : These functions are typically used in the context of a menu-driven application where users can choose to display tasks based on their status (active, completed, or specific tasks). The header file facilitates organized and formatted output to the console, aiding users in efficiently managing their tasks.*/

#pragma once

#include "../Main Header File.hpp"
#include "../../Display_Basics.hpp"
#include <iterator>
#include <format>
#include <list>
#include <map>
using namespace std;

int Active_Task_List (list <Task> &Tasks, list <Task> :: iterator Completed_Id){
     int taskId = 0;
     if (Tasks.begin() == Completed_Id)cout<<padding("Currently No Active Tasks...")<<"Currently No Active Tasks..."<<endl;
     else {
          taskId = 1;
          for (list <Task> :: iterator itr {Tasks.begin()}; itr != Completed_Id; itr++, taskId++)
               cout<<format(" -> Task {:<5} Name : {:<35} Description : {}", taskId, (*itr).Name, (*itr).Description)<<endl;
     }
     return taskId;
}

void Completed_Task_List (int taskId, list <Task> &Tasks, list <Task> :: iterator Completed_Id ){
     if (Completed_Id != Tasks.end()){
          for (list <Task> :: iterator itr {Completed_Id}; itr != Tasks.end(); itr++, taskId++)
               cout<<format("\n -> Task {:<5} Name : {:<35} Description : {}", taskId, (*itr).Name, (*itr).Description);
          cout<<endl;
     }
     else 
          cout<<padding("No Tasks Completed...")<<"No Tasks Completed..."<<endl;
}

void Display_All_Tasks (list <Task> &Tasks, list <Task> :: iterator Completed_Id ){
     Header("TASK TRACKER : DISPLAY ALL TASKS");
     cout<<"\n ACTIVE TASKS : "<<endl;
     int taskId = Active_Task_List(Tasks, Completed_Id);
     cout<<"\n COMPLETED TASKS : "<<endl;
     Completed_Task_List(taskId, Tasks, Completed_Id);
}

void Display_Specific_Task(list <Task> &Tasks, const int *taskId){
     cout<<endl<<padding("Fetching the Tasks Details...")<<"Fetching the Tasks Details...";
     if (*taskId <= 0 || *taskId > Task::count_Tasks){
          cout<<"\n\nTask with ID : "<<*taskId<<" not found in Tasks"<<endl; 
          return;
     }
     list <Task> :: iterator itr {Tasks.begin()};
     advance(itr, (*taskId) - 1);
     cout<<"\n\nTask : "<<itr->Name
         <<"\nDescription : "<<itr->Description
         <<"\nCompleted : "<<((itr->Completed)? "Yes" : "No") <<endl;
}

void Display_Active_Tasks (list <Task> &Tasks, list <Task> :: iterator Completed_Id){
     Header("TASK TRACKER : DISPLAY ACTIVE TASKS");
     cout<<endl;
     Active_Task_List(Tasks, Completed_Id);
}

void Display_Completed_Tasks (list <Task> &Tasks, list <Task> :: iterator Completed_Id ){
     int taskId = distance(Tasks.begin(), Completed_Id);
     Header("TASK TRACKER : DISPLAY COMPLETED TASKS");
     cout<<endl;
     Completed_Task_List(taskId, Tasks, Completed_Id);
}