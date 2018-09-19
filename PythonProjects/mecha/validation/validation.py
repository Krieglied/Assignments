# validation.py

# Used to validate that the user input an int and its within the list value range
def int_validation(choices):
    user_input = raw_input(":::")
    try:
        user_input = int(user_input)
    # If the value provided is neither an int or with the range
    # The function is recursively called until that condition is met
    except ValueError:
        print("Not a valid int.")
        user_input = int_validation(choices)
    if user_input < 1 or user_input >= (choices + 1):
        print("Please select a valid choice")
        user_input = int_validation(choices)
    return user_input
# Checks that the user input a correct move choice
def move_validation(choices):
    user_input = raw_input(":::")
    if (user_input.upper() not in choices):
        print("Invalid choice, please try again.")
        user_input = move_validation()
    return user_input
