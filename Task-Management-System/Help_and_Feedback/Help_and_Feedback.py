#Help and Feedback.py 

'''OVERVIEW : 
This script provides a help and feedback interface for the Task Management System. It includes functions to display help information and collect user feedback. The HELP() function reads and displays help content from a file, while the FEEDBACK() function collects user ratings and comments on various aspects of the system.

DEPENDENCIES : 
   -> Standard Libraries: os, time.
   -> Files: "Task-Management-System/Help_and_Feedback/Help_and_Feedback.txt"

FUNCTIONS : 
   -> def HELP()
        * Description: Displays help information from the "Help_and_Feedback.txt" file in chunks, allowing users to read through the content one section at a time.
        * Usage: Called when the user selects the option for help.
        * Details: Reads the help file in chunks of varying sizes. Clears the screen between chunks for readability. Ends with a final message of hope that the information helps.

   -> def FEEDBACK()
        * Description: Collects user feedback on different aspects of the Task Management System, including presentation, function use, and user interaction.
        * Usage: Called when the user selects the option to provide feedback.
        * Details: Displays a feedback form with rating options for presentation, function use, and user interaction. Thanks the user for their feedback after submission.

USAGE : The script starts by displaying a menu where the user can choose between receiving help or providing feedback.
Depending on the user's choice, it either calls the HELP() function to display help content or the FEEDBACK() function to collect feedback. The screen is cleared (os.system("cls")) between operations to ensure a clean display of content.'''

import os, time

def HELP():
     myfile = open(r"Task-Management-System\Help_and_Feedback\Help_and_Feedback.txt","r")
     i = [222, 934, 644, 192]
     m = 0
     while m < 5:
          print("\n", "="*132, "\n\t\t\t\t\t\t      TASK TRACKER : HELP WINDOW\n")
          print("="*133)
          if m < 4:
               print(myfile.read(i[m]))
               a = input("\t\t\t\t\t\t\tPress Enter...")
               os.system("cls")
          else :
               print(myfile.read())
               print("\n \t\t\t\t\t\t\t", "Hope it Helps.....","\n\n")
               print("="*133)
          m = m + 1

def FEEDBACK():
     print("\n", "="*132, "\n\t\t\t\t\t\t  TASK TRACKER : FEEDBACK WINDOW\n")
     print("="*133)
     print('''\n\t\t\tRatings :
          
-> Outstanding     : ***** 
-> Good            : ****
-> Satisfactory    : ***
-> Poor            : **
-> Unsatisfactory  : *\n''')
     print("_"*133)
     time.sleep(1)
     a = input("\n Presentation     : ")
     a = input("\n Use of Functions : ")
     a = input("\n User Interaction : ")
     print("\n \t\t\t\t\t\t", "Thank you for your Feedback.... :)","\n")
     print("="*133)
     time.sleep(3)

os.system("cls")
print("="*133,"\n\t\t\t\t\t\t   TASK TRACKER : HELP AND FEEDBACK\n")
print("="*133)
print('''\nDo You want : 
\n             1. Help 
\n             2. To Give Feedback''')
a = int(input("\n\nEnter your Choice : "))
time.sleep(2)
print("\n\nInitiating.......")
time.sleep(1)
os.system("cls")
if (a == 1) :
     HELP()
else :
     FEEDBACK()