#Help and Feedback
import os, time

def HELP():
     myfile = open(r"Help_and_Feedback.txt","r")
     i,m = [222, 934, 644, 192],0
     while m < 5:
          print("\n", "="*133, "\n\t\t\t\t\t\t      TASK TRACKER : HELP WINDOW\n")
          print("="*133)
          if m < 4:
               print(myfile.read(i[m]))
               a = input("\t\t\t\t\t\t\tPress Enter...")
               os.system("cls")
          else :
               print(myfile.read())
               a = "Hope it Helps....."
               print("\n \t\t\t\t"+a+"\n")
               print("="*80)
          m = m + 1

def FEEDBACK():
     print("\n", "="*133, "\n\t\t\t\t\t\t  TASK TRACKER : FEEDBACK WINDOW\n")
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
     a = "Thank you for your Feedback.... :)"
     print("\n \t\t\t"+a+"\n")
     print("="*80)
     time.sleep(20)

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