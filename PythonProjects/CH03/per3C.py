#Performance Lab 3C
#Robert John Graham III
#September 6 2018

"""
   Create a text-based game where the user is navigating through a "Fun" House. 
   Prompt the user to make a decision and using if/elif/else statements, give 
   them different outcomes based on their answers. Begin with an introduction 
   to your fun house and prompt the user to choose between at least three 
   different options. You can use nested if/elif/else statements to make the 
   game more complex.
"""
import time
#Each room first prints how many rooms have been visited
#Then the user is asked which room to go to
#Then that room function is called
def door1(rooms):
    print("You have been in {} rooms.").format(rooms)
    choice = user_input()
    rooms += 1
    if choice == "1":
        door1(rooms)
    elif choice == "2":
        door3(rooms)
    else:
        door2(rooms)

def door2(rooms):
    print("You have been in {} rooms.").format(rooms)
    choice = user_input()
    rooms += 1
    if choice == "1":
        door(rooms)
    elif choice == "2":
        door1(rooms)
    else:
        door3(rooms)

def door3(rooms):
    print("You have been in {} rooms.").format(rooms)
    choice = user_input()
    rooms += 1
    if choice == "1":
        door3(rooms)
    elif choice == "2":
        door1(rooms)
    else:
        #This is the exit condition for the program
        #Only if the user gets to this choice,
        #will the program get to close
        print("You have exited the FUN HAUS!!!!")
#Function that handles user input from which room to select
def user_input():
    choice = ""
    while True:
        choice = raw_input("Which room do you to go into (1, 2, 3):    ")
        print(choice)
        #If the user input doesn't match one of the good choices
        #Then the loop is repeated until a good choice is made
        if choice != "1" and choice != "2" and choice != "3":
            print("Please select an appropriate room choice\n")
            time.sleep(2)
        else:
            break
    return choice

#The start of the program asks which room to go to
rooms = 1
user_choice = user_input()
if user_choice == "1":
    door1(rooms)
elif user_choice == "2":
    door2(rooms)
else:
    door3(rooms)
