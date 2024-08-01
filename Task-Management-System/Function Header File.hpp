#pragma once

#include "Main Header File.hpp"
#include <climits>
#include <vector>
#include <array>
#include <list>
#include <map>

int mapping_setter (list <Task> &Tasks, map <int, Task *> &TaskMap, Task * New_Task){
     int TaskId = -1;
     std::map<int, Task *> newTaskMap; // Create a new map to swap with originial
     for (const auto &mapPair : TaskMap){
          int taskId = 0;
          Task * Task_from_mapPair = mapPair.second;
          for (const Task & Task_from_Tasks : Tasks){
               taskId++;
               if (Task_from_mapPair == &Task_from_Tasks){
                    if (New_Task == Task_from_mapPair) TaskId = taskId;
                    newTaskMap[taskId] = Task_from_mapPair;
                    break;
               }
          }
     }
     TaskMap.swap(newTaskMap); // Swap the original map with the new map
     return TaskId;
}

int Add_Task (unique_ptr <string> Name, unique_ptr <string> Description, list <Task> &Tasks, list <Task> :: iterator &Completed_Id, map <int, Task *> &TaskMap){
     unique_ptr <Task> New_Task {make_unique <Task> (*Name, *Description, false)};
     cout<<"\n\n\t\t\t\t\t           Adding the Tasks List";
     Completed_Id = Tasks.insert(Completed_Id, *New_Task);
     cout<<" and Tasks ID..."<<endl;
     TaskMap[Task::count_Tasks] = &(*Completed_Id);
     if (Completed_Id != Tasks.end()) //Incrementing Completed_List to move to new position
        ++Completed_Id;
     int TaskId = mapping_setter(Tasks, TaskMap, TaskMap[Task::count_Tasks]);
     cout<<"\n\nSuccessfully Added...";
     return TaskId;
}
 
int Marking_Completed (const int * taskId, map <int, Task *> &TaskMap, list <Task> &Tasks, list <Task> :: iterator &Completed_Id){
     cout<<"\n\t\t\t\t\t        Updating the Tasks List";
     bool found = false;
     if (*taskId > 0 && *taskId <= Task::count_Tasks){
          for (const auto &mapPair : TaskMap)
               if (*taskId == mapPair.first){
                    if (mapPair.second->Completed == false){
                         mapPair.second->Completed = true;
                         found = true;
                    }
                    else found = false;
               }
     }
     cout<<" and Tasks ID..."<<endl;
     if (found == false){
          cout<<"\n\nUpdation Failed...";
          return INT_MAX;
     }
     list <Task> :: iterator itr {Tasks.begin()};
     advance(itr, (*taskId) - 1);
     Task Completed_Task = *itr;
     Tasks.erase(itr); //Now itr holds address to the erased element memory
     Tasks.push_back(Completed_Task);
     TaskMap[*taskId] = &(Tasks.back());
     int TaskId = mapping_setter(Tasks, TaskMap, &(Tasks.back()));
     if (Completed_Id == Tasks.end()) Completed_Id = (--Tasks.end());
     cout<<"\n\nSuccessfully Updated...";
     return TaskId;
}

void Arrange_Active_Tasks(string &Priority, list <Task> &Tasks, map <int, Task *> &TaskMap, list <Task> :: iterator &Completed_Id){
     list <Task> New_Tasks;
     map <int, Task*> New_TaskMap;
     for(size_t i = 0; i < Priority.size(); i += 2){
          int task = Priority[i];
          list <Task> :: iterator itr = Tasks.begin();
          advance(itr, task - 1);
          New_Tasks.push_back(*itr);
     }
     int count = 1;
     for (auto itr = Completed_Id; itr != Tasks.end(); itr++, count++) {
          New_Tasks.push_back(*itr);
          if (count == 1) Completed_Id = --(New_Tasks.end());
     }
     Tasks.swap(New_Tasks);
     int taskId = 1;
     for (auto &a : Tasks){
          New_TaskMap[taskId] = &a;
          taskId++;
     }
     TaskMap.swap(New_TaskMap);
     cout<<"\nUpdated the Active Tasks List..."<<endl;
}

void Delete_Task (int &taskId, list <Task> &Tasks, map <int, Task *> &TaskMap, list <Task> :: iterator &Completed_Id){
     cout<<"\n\t\t\t\t\t         Fetching the Tasks Details...";
     if (taskId <= 0 || taskId > Task::count_Tasks){
          cout<<"\n\nTask with ID : "<<taskId<<" not found in Tasks"<<endl;
          return;
     }
     list <Task> :: iterator itr = Tasks.begin();
     advance (itr, taskId - 1);
     if (itr == Completed_Id) Completed_Id++;
     Tasks.erase(itr);
     TaskMap.erase(taskId);
     mapping_setter(Tasks, TaskMap, &(*Tasks.begin()));
     cout<<"\n\nTask with ID : "<<taskId<<" deleted from Tasks List"<<endl;
}