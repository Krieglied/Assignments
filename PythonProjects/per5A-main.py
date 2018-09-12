#per5A-main.py

#Performance Lab 5A
#Robert John Graham III
#September 12 2018

import operations

def main():
    print("CALCULATOR")
    while True:
        operations.print_loop()
        operations.operations_loop()
        user_choice = ""
        #Here the user is presented with the choice of using the result
        #for the next loop, starting a fresh computation loop, or exiting
        #the program
        while True:
            print("Do you wish to continue (CON), or exit the program (EXIT)?")
            user_choice = raw_input("::: ").rstrip()
            if user_choice.upper() in ["CON", "EXIT"]:
                break
            else:
                print("Please select a valid choice.")
        if user_choice.upper() == "EXIT":
            break


if __name__ == 'main':
    main()
