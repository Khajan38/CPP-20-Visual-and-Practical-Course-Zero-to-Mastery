//Display Header File.hpp

/*OVERVIEW : 
This header file defines functions for handling and displaying task-related operations in the Task Management System. It provides a menu for users to select various display options and handles the corresponding display operations.

DEPENDENCIES : 
   -> Standard Libraries: iostream, array
   -> Custom Header Files:
        * "Display Function File.hpp"

FUNCTIONS : 
   -> void Display_Menu(list <Task> &Tasks, list <Task>::iterator Completed_Id)
        * Description: Presents a menu to the user for selecting different display options related to tasks.
        * Usage: Provides an interface for users to choose between displaying specific tasks, all tasks, active tasks, or completed tasks.
        * Details: Takes user input to determine which display operation to perform. Calls Display_Operations() to handle the selected option.

   -> void Display_Operations(int choice, list <Task> &Tasks, list <Task>::iterator &Completed_Id)
        * Description: Executes the chosen display operation based on user input.
        * Usage: Handles the logic for displaying specific tasks, all tasks, active tasks, or completed tasks.
        * Details: Uses a switch statement to handle different cases based on the user's choice. Calls corresponding display functions such as Display_Specific_Task(), Display_All_Tasks(), etc. Includes a default case to handle invalid input.*/

#pragma once

#include "Display Function File.hpp"
using namespace std;

void Display_Operations (int, list <Task> &, list <Task> :: iterator &);
array <string, 2> Exit_Parts {"TASK TRACKER", "Task Tracker"};

void Display_Menu (list <Task> &Tasks, list <Task> :: iterator Completed_Id){
     Header("TASK TRACKER : DISPLAY TASK MENU");
     cout<<"\n\t\t\t\t\t\t 1. Display Specific Task\
     \n\t\t\t\t\t\t 2. Display All Tasks\
     \n\t\t\t\t\t\t 3. Display Active Tasks\
     \n\t\t\t\t\t\t 4. Display Completed Tasks\
     \n\nEnter your choice : ";
     int choice; cin>>choice;
     if (choice >= 1 && choice <= 4) Bottom_Line(1);
     Display_Operations(choice, Tasks, Completed_Id);
}

void Display_Operations(int choice, list <Task> &Tasks, list <Task> :: iterator & Completed_Id){
     switch(choice){
          case 1:{
               Header("TASK TRACKER : DISPLAY SPECFIC TASK");
               int taskId = -1;
               cout<<"\nEnter Task ID : ";
               cin>>taskId;
               Display_Specific_Task(Tasks, &taskId);
               Bottom_Line_2(Exit_Parts);
               break;
          }
          case 2:
               Display_All_Tasks(Tasks, Completed_Id);
               Bottom_Line_2(Exit_Parts);
               break;
          case 3:
               Display_Active_Tasks(Tasks, Completed_Id);
               Bottom_Line_2(Exit_Parts);
               break;
          case 4:
               Display_Completed_Tasks(Tasks, Completed_Id);
               Bottom_Line_2(Exit_Parts);
               break;
          default:
               cout<<padding("Enter a valid request...")<<"Enter a valid request...";
               sleep(2);
     }
}