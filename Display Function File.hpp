#pragma once

#include "Main Header File.hpp"
#include <iterator>
#include <format>
#include <vector>
#include <array>
#include <list>
#include <map>
using namespace std;

void Display_All_Tasks (list <Task> &Tasks, list <Task> :: iterator Completed_Id ){
     Header("   TASK TRACKER : DISPLAY ALL TASKS");
     cout<<"\n ACTIVE TASKS : "<<endl;
     int taskId = 1;
     if (Tasks.begin() == Completed_Id) cout<<"                 Currently No Active Tasks..."<<endl;
     else {
          for (list <Task> :: iterator itr {Tasks.begin()}; itr != Completed_Id; itr++, taskId++)
               cout<<format("\n -> Task {:<5} Name : {:<35} Description : {}", taskId, (*itr).Name, (*itr).Description);
          cout<<endl;
     }
     cout<<"\n COMPLETED TASKS : "<<endl;
     if (Completed_Id != Tasks.end()){
          for (list <Task> :: iterator itr {Completed_Id}; itr != Tasks.end(); itr++, taskId++)
               cout<<format("\n -> Task {:<5} Name : {:<35} Description : {}", taskId, (*itr).Name, (*itr).Description);
          cout<<endl;
     }
     else 
          cout<<"                 No Tasks Completed..."<<endl;
}

void Display_Specific_Task(list <Task> &Tasks, const int *taskId){
     cout<<"\n\t\t\t\t\t         Fetching the Tasks Details...";
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

int Active_Task_List (list <Task> &Tasks, list <Task> :: iterator Completed_Id){
     int taskId = 0;
     if (Tasks.begin() == Completed_Id)cout<<"Currently No Active Tasks..."<<endl;
     else {
          taskId = 1;
          for (list <Task> :: iterator itr {Tasks.begin()}; itr != Completed_Id; itr++, taskId++)
               cout<<format(" -> Task {:<5} Name : {:<35} Description : {}", taskId, (*itr).Name, (*itr).Description)<<endl;
     }
     return taskId - 1;
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
     if (Completed_Id != Tasks.end()){
          for (list <Task> :: iterator itr {Completed_Id}; itr != Tasks.end(); itr++, taskId++)
               cout<<format(" -> Task {:<5} Name : {:<35} Description : {}", taskId, (*itr).Name, (*itr).Description)<<endl;
     }
     else 
          cout<<"No Tasks Completed..."<<endl;
}