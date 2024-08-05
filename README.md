# TASK MANAGEMENT SYSTEM
Task Management System (TMS): TASK TRACKER is a comprehensive software solution designed to facilitate the management and operation of tasks. It automates various processes involved in managing tasks, users, and task statuses, making it easier for users to efficiently handle their workflow. The system is intended for use in organizations of all sizes, from small teams to large enterprises.

<img src="Task-Management-System\Task-Management-System.jpeg" alt="Task Tracker" height="250">

__See me on LinkedIn :__ [Link to my LinkedIn ID](https://www.linkedin.com/in/khajanbhatt/)

## Files in the Project

    --> Mission_17 Task_Management_System.cpp : 
                Main Program code for calling all other functions providing Abstraction

    --> Display_Basics.hpp : 
                Resuable files for all missions

    --> Library-Management-System : 
                Directory for Header Files
          * Main Header File.hpp : 
                Struct Task and Login_Window are defined here
          * Function Header File.hpp : 
                All Functions that are driving Main Menu are defined here
          * Display_Functions : 
                Directory for Display Functions File
                * Display Header File.hpp :
                      Display Menu and switch cases for Display Functions is defined here
                * Display Function File.hpp :
                      Display Functions methods are defined here
          * Help_and_Feedback : 
                Directory for Help_and_Feedback File -- Python Directed
                * Help_and_Feedback.txt:
                      All details of Project and help are written in this file.
                * Help_and_Feedback.py :
                      Help and Feedback taking methods are defined here
          * Task Management Process.jpeg : 
              Image for Readme File
          * Task-Management-System.jpeg : 
              Image for Readme File to show its purpose           

<img src="Task-Management-System\Task Management Process.jpeg" alt="Task Management System Operations"  height="250">

## Features and Working:

The __Task Tracker__ opens when the user runs the file __"Mission_17 Task_Management_System.cpp"__. Designing Templates for all pages is done by using __"Display_Basics.hpp"__ which includes various function methods for Page Templates. These include-

- Headings : __"Display_Basics.hpp -> Header()"__
- Word Padding to center : __"Display_Basics.hpp -> padding [] () {}"__
- Footers and Bottom Lines : __"Display_Basics.hpp -> Bottom_Line(), Bottom_Line_2()"__
- Main Menus : __"Display_Basics.hpp -> Main_Menu()"__
- Exit Window : __"Display_Basics.hpp -> Exiting_Window()"__

Now the first page that opens is the __Login Window__ which is executed by __"Task-Management-System\Main Header File.hpp -> Login_Window()"__. This checks weather you are an Member or just an intruder. When entered the correct Password = "Task_Tracker", it procedes further in the program to show up the __Main Menu__ which si called by file __"Display_Basics.hpp -> Main_Menu()"__ with Menu Items. These further gives choices for various operations. 

- For __Adding New Task__, it calls __"Task-Management-System\Function Header File.hpp -> Add_Task()"__ which calls necessary headers and then asks user for Task Details. Then, it updates the Tasks Lists by addding new task to correct Position and updates the Task ID in Task Map by calling __"Task-Management-System\Function Header File.hpp -> mapping_setter()"__. Finally Inseration message pops up, if all things are updations are done.

- For __Arrangig Active Tasks__, it calls __"Task-Management-System\Function Header File.hpp -> Arrange_Active_Tasks()"__ which asks user for Task Arrangememt Fashion. Then, it updates the Tasks Lists and TaskMap by creating new Map and Lists and arranging Tasks and IDs in them and finally replacing old structures with new.

- For __Mark Task as Completed__, it calls __"Task-Management-System\Function Header File.hpp -> Marking_Completed()"__ which asks user for Completed Task ID and makes Completed Task move it its new position with new ID with is done by calling __"Task-Management-System\Function Header File.hpp -> mapping_setter()"__. 

- For __Dispalying Task Information__, it calls __"Library-Management-System/Member Functions File.hpp -> Borrowed_Books()"__ which showcases a table showing list of all borrowed books list, if issued by Library.

- For __Deleting a Task__, it calls __"Task-Management-System\Display_Functions\Display Header File.hpp -> Display_Menu()"__ which is a user driven Menu for various Display Tasks Types. It asks for choice and calls for __"Task-Management-System\Display_Functions\Display Header File.hpp -> Display_Operations()__. This functions reads the choice as parameter and calls appropriate fucntion according to the User Choices -

    - For __Displaying Specific Task Informations__, it calls __"Task-Management-System\Display_Functions\Display Function File.hpp -> Display_Specific_Task()"__ which ask for Task ID and shows Title, Description and Current status of the particular Task ID.  

    - For __Displaying All Tasks Informations__, it calls __"Task-Management-System\Display_Functions\Display Function File.hpp -> Display_All_Tasks()"__ which shows the list of Active tasks, if any, by using __"Task-Management-System\Display_Functions\Display Function File.hpp -> Active_Task_List()"__ and of Completed Tasks if any, by __"Task-Management-System\Display_Functions\Display Function File.hpp -> Completed_Task_List()"__.

    - For __Displaying Active Tasks Informations__, it calls __"Task-Management-System\Display_Functions\Display Function File.hpp -> Display_Active_Tasks()"__ which shows the list of Active tasks, if any, by using __"Task-Management-System\Display_Functions\Display Function File.hpp -> Active_Task_List()"__.

    - For __Displaying All Tasks Informations__, it calls __"Task-Management-System\Display_Functions\Display Function File.hpp -> Display_Completed_Tasks()"__ which shows the list of Completed Tasks if any, by __"Task-Management-System\Display_Functions\Display Function File.hpp -> Completed_Task_List()"__.

- For __Getting Help and Giving Feedbacks__, it calls __"Task-Management-System\Help_and_Feedback\Help_and_Feedback.py"__ by system command hence integrating Python with C++. This now asks user weather he needs help or wanted to give feedbacks and hence corresponding to choice calls - 

    - For __Getting Help__, it calls __"Task-Management-System\Help_and_Feedback\Help_and_Feedback.py -> HELP()"__ which is a Text File Handling program : __"Task-Management-System\Help_and_Feedback\Help_and_Feedback.txt"__ which contains documentations and resources for __Task Tracker__.

    - For __Giving Feedbacks__, it calls __"Task-Management-System\Help_and_Feedback\Help_and_Feedback.py -> FEEDBACK()"__, it displays instructions for Feedback and user can proceed to give Feedback to help improve the __Task Tracker__ and overcome its shortcomings.

- For __Exiting from the Program__, it calls the __"Display_Basics.hpp -> Exiting_Window()"__ which lets user to the Exit and Thank You Window and clears the prompt screen then.

### Flow of Operations:
    Main Program : "Mission_17 Task_Management_System.cpp" 

    Login Page : Task-Management-System\Main Header File.hpp -> Login_Window()

    Main_Menu : Display_Basics.hpp -> Main_Menu()

        Add New Task : Task-Management-System\Function Header File.hpp -> Add_Task()

        Arrange Active Tasks : Task-Management-System\Function Header File.hpp -> Arrange_Active_Tasks()

        Mark Task as Completed : Task-Management-System\Function Header File.hpp -> Marking_Completed()

        Display Tasks Windows : 
            Task-Management-System\Display_Functions\Display Header File.hpp -> Display_Menu()
            Task-Management-System\Display_Functions\Display Header File.hpp -> Display_Operations()
                Task-Management-System\Display_Functions\Display Function File.hpp -> Display_Specific_Task()
                Task-Management-System\Display_Functions\Display Function File.hpp -> Display_All_Tasks()
                Task-Management-System\Display_Functions\Display Function File.hpp -> Display_Active_Tasks()
                Task-Management-System\Display_Functions\Display Function File.hpp -> Display_Completed_Tasks()

        Delete a Task : Task-Management-System\Function Header File.hpp -> Delete_Task()

        Get Help and Give Feedbacks : 
            Task-Management-System\Help_and_Feedback\Help_and_Feedback.py
                Task-Management-System\Help_and_Feedback\Help_and_Feedback.py -> HELP()
                Task-Management-System\Help_and_Feedback\Help_and_Feedback.py -> FEEDBACK()

        Exiting : Display_Basics.hpp -> Exiting_Window()
