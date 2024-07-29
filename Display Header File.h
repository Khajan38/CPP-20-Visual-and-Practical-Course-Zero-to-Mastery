#pragma once

#include "Display Function File.h"
using namespace std;

void Display_Operations (int, list <Task> &, list <Task> :: iterator &);

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
               Bottom_Line(2);
               break;
          }
          case 2:
               Display_All_Tasks(Tasks, Completed_Id);
               Bottom_Line(2);
               break;
          case 3:
               Display_Active_Tasks(Tasks, Completed_Id);
               Bottom_Line(2);
               break;
          case 4:
               Display_Completed_Tasks(Tasks, Completed_Id);
               Bottom_Line(2);
               break;
          default:
               cout<<"\t\t\t\t\t\t      Enter a valid request...";
               sleep(2);
     }
}