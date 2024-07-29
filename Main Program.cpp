#include <iostream>
//Using Header File since Modules are still developing in gcc and creating problems in compilation
#include "Main Header File.hpp" 
#include "Functions Header File.hpp"
#include "Display Header File.hpp"
#include <memory>

using namespace std;

void DisplayTask (Task task){
          cout<<"\nTask : "<<task.Name<<endl;
          cout<<"Description : "<<task.Description<<endl;
          cout<<"Status : "<<(task.Completed)? "Completed" : "Incomplete";
}

int main(){
     int menu_choice {1};
     char program_choice {'M'};
     list <Task> Tasks; //Stores all Tasks
     map <int, Task *> TaskMap; //TaskMap maps Tasks with their TaskId (their position in Tasks list)
     list <Task> :: iterator Completed_Id {Tasks.begin()}; //Iterator to index where Completed Tasks start in Tasks
     Main_Functions::Entrance_Window();
     while (program_choice == 'M'){
          menu_choice = Main_Functions::Main_Menu();
          switch (menu_choice){
               case 1:{
                    Header("     TASK TRACKER : ADD TASK WINDOW");
                    unique_ptr <string> Name{make_unique <string>()};
                    unique_ptr <string> Description{make_unique <string>()};
                    //getline is used to input text with white spaces also
                    cin.ignore(INT_MAX, '\n'); //To remove input buffer
                    cout<<"\nEnter Task : "; getline(cin, *Name);
                    cout<<"\nEnter Description : "; getline(cin, *Description);
                    int taskID = Add_Task(move(Name), move(Description), Tasks, Completed_Id, TaskMap);
                    //move() with unique pointer let us transfer the ownership of unique_ptr to fucntion ptrs
                    cout<<" Task added successfully with ID : "<<taskID<<endl;
                    Bottom_Line(2);
                    break;
               }
               case 2:{
                    Header("     TASK TRACKER : ARRANGE TASK"); cout<<endl;
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
                    Bottom_Line(2);
                    break;
               }
               case 3:{
                    Header("  TASK TRACKER : MARK TASK COMPLETE");
                    int taskId = -1;
                    cout<<"\nEnter Task ID : ";
                    cin>>taskId;
                    int TaskId = Marking_Completed(& taskId, TaskMap, Tasks, Completed_Id);
                    if (TaskId == Task::count_Tasks) cout<<" Task with Id : "<<taskId<<" marked completed successfully with new ID : "<<TaskId<<endl;
                    else cout<<" Task with ID : "<<taskId<<" not found in Active Tasks"<<endl;
                    Bottom_Line(2);
                    break;
               }
               case 4:{
                    Display_Menu(Tasks, Completed_Id);
                    break;
               }
               case 5:{
                    Header("TASK TRACKER : DELETE TASK COMPLETE");
                    int taskId = -1;
                    cout<<"\nEnter Task ID : ";
                    cin>>taskId;
                    Delete_Task(taskId, Tasks, TaskMap, Completed_Id);
                    Bottom_Line(2);
                    break;
               }
               case 6:
                    system("python Help_and_Feedback.py");
                    break;
               case 7:
                    Main_Functions::Exiting_Window();
               default:
                    cout<<"\t\t\t\t\t\t      Enter a valid request...";
                    sleep(2);
          }
     }
     return 0;
}