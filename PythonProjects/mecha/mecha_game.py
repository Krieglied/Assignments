# mecha_game.py

# Robert John Graham III
# September 14 2018

"""
    This mecha game is a translation of a C++ project to python, to show the
    difference and similiarites between C++ objects/classes and Python's.
    This is a two player game that allows each player to select a mech, and
    then take pot shots at each other on a field until only one mech
    stands victorious
"""

import time
from mecha_sub import *
from mecha import Mecha

def int_validation():
    user_input = raw_input(":::")
    try:
        user_input = int(user_input)
    except ValueError:
        print("Not a valid int.")
        user_input = int_validation()
    if user_input < 1 or user_input >= 9:
        print("Please select a valid choice")
        user_input = int_validation()
    return user_input

# Token to record whose turn it is (True for player 1, False for player 2)
player = True
# Token to indicate the end of the game
game_over =  False
mechs = [None] * 2
rows = 20
columns = 20
grid = [[0 for x in range(columns)] for y in range(rows)]

for i in range(len(mechs)):
    # Displays the list of mechs for each player
    mech_choice = 0
    print("MECHS AVAILABLE")
    print("(1)")
    Hellbringer().displayMainStats()
    print("(2)")
    MadDog().displayMainStats()
    print("(3)")
    Summoner().displayMainStats()
    print("(4)")
    TimberWolf().displayMainStats()
    print("(5)")
    Warhammer().displayMainStats()
    print("(6)")
    Kodiak().displayMainStats()
    print("(7)")
    StoneRhino().displayMainStats()
    print("(8)")
    Mauler().displayMainStats()
    print("Player {}, please select your mech (Input the number):").format(i)
    # Validates the user choice
    mech_choice = int_validation()
    mech_list = {1:Hellbringer(), 2:MadDog(), 3:Summoner(), 4:TimberWolf(), 5:Warhammer(), 6:Kodiak(), 7:StoneRhino(), 8:Mauler()}
    # Assigns the mech to the choice from the user
    mechs[i - 1] = mech_list[mech_choice]

grid[5][10] = mechs[0]
grid[10][10] = mechs[1]

mechs[0].over_heated = True
mechs[1].over_heated = True
while game_over is not True:
    if (mechs[0].over_heated if player else mechs[1].over_heated):
        print("Your mech is overheated.  You have to wait a turn.")
        time.sleep(2)
        if player:
            mechs[0].over_heated = not mechs[0].over_heated
        else:
            mechs[1].over_heated = not mechs[1].over_heated
    else:

