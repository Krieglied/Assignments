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
import math
from mechs import mecha
from mechs import Hellbringer
from mechs import MadDog
from mechs import Summoner
from mechs import TimberWolf
from mechs import Warhammer
from mechs import Kodiak
from mechs import StoneRhino
from mechs import Mauler

#from mecha_sub import Hellbringer,MadDog,Summoner,TimberWolf,Warhammer
#from mecha_sub import Kodiak,StoneRhino,Mauler
#from mecha import Mecha

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
def move_validation():
    user_input = raw_input(":::")
    if (user_input.upper() != "A" and user_input.upper() != "W" 
            and user_input.upper() !=  "S"  and user_input.upper() != "D" 
            and user_input != "0"):
        print("Invalid choice, please try again.")
        user_input = move_validation()
    return user_input
# game_movement.py

# List of functions that handle moving the mech within the grid
def moveLeft(location,grid):
    x = location[0]
    y = location[1]
    if ((x - 1 > 0) and (grid[y][x - 1] == 0)):
        grid[y][x - 1] = grid[y][x]
        grid[y][x] = 0
        location[0] -= 1
        print("Move successful!")
        return True
    else:
        print("Illegal move.  Try Again.")
        return False
def moveUp(location,grid):
    x = location[0]
    y = location[1]
    if ((y - 1 > 0) and (grid[y - 1][x] == 0)):
        grid[y - 1][x] = grid[y][x]
        grid[y][x] = 0
        location[1] -= 1
        print("Move successful!")
        return True
    else:
        print("Illegal move.  Try Again.")
        return False
def moveDown(location,grid):
    x = location[0]
    y = location[1]
    if ((y + 1 > 0) and (grid[y + 1][x] == 0)):
        grid[y + 1][x] = grid[y][x]
        grid[y][x] = 0
        location[1] += 1
        print("Move successful!")
        return True
    else:
        print("Illegal move.  Try Again.")
        return False
def moveRight(location,grid):
    x = location[0]
    y = location[1]
    if ((x + 1 > 0) and (grid[y][x + 1] == 0)):
        grid[y][x + 1] = grid[y][x]
        grid[y][x] = 0
        location[0] += 1
        print("Move successful!")
        return True
    else:
        print("Illegal move.  Try Again.")
        return False
def stay():
    print("No move to perform")
    return True
# Processes the user's choice of move, return False if the move is not valid
def checkMove(move_choice, location, grid):
    moves = True
    if move_choice == "A":
        moves = moveLeft(location,grid)
    elif move_choice == "W":
        moves = moveUp(location,grid)
    elif move_choice == "S":
        moves = moveDown(location,grid)
    elif move_choice == "D":
        moves = moveRight(location,grid)
    else:
        moves = stay()
    return moves
# Uses pythagoras theorem to compute distance between mechs
def computeDistance(location, opplocation):
    distance = 0
    a = opplocation[0] - location[0]
    b = opplocation[1] - location[1]
    if (a < 0):
        a = (-a)
    if (b < 0):
        b = (-b)
    distance = int(math.sqrt(a ** 2 + b ** 2))
    return distance

# Token to record whose turn it is (True for player 1, False for player 2)
player = True
# Token to indicate the end of the game
game_over =  False
mech_player = [None] * 2
rows = 20
columns = 20
# Field that the mechs fight on
grid = [[0 for x in range(columns)] for y in range(rows)]

for i in range(len(mech_player)):
    # Displays the list of mechs for each player
    mech_choice = 0
    print("MECHS AVAILABLE")
    print("(1)")
    Hellbringer.Hellbringer.displayMainStats(Hellbringer.Hellbringer())
    print("(2)")
    MadDog.MadDog().displayMainStats(MadDog.MadDog())
    print("(3)")
    Summoner.Summoner().displayMainStats(Summoner.Summoner())
    print("(4)")
    TimberWolf.TimberWolf().displayMainStats(TimberWolf.TimberWolf())
    print("(5)")
    Warhammer.Warhammer().displayMainStats(Warhammer.Warhammer())
    print("(6)")
    Kodiak.Kodiak().displayMainStats(Kodiak.Kodiak())
    print("(7)")
    StoneRhino.StoneRhino().displayMainStats(StoneRhino.StoneRhino())
    print("(8)")
    Mauler.Mauler().displayMainStats(Mauler.Mauler())
    print("Player {}, please select your mech (Input the number):").format(i)
    # Validates the user choice
    mech_choice = int_validation(8)
    mech_list = {1:Hellbringer.Hellbringer(), 
            2:MadDog.MadDog(), 
            3:Summoner.Summoner(), 
            4:TimberWolf.TimberWolf(), 
            5:Warhammer.Warhammer(), 
            6:Kodiak.Kodiak(), 
            7:StoneRhino.StoneRhino(), 
            8:Mauler.Mauler()}
    # Assigns the mech to the choice from the user
    mech_player[i - 1] = mech_list[mech_choice]

grid[5][10] = mech_player[0]
grid[10][10] = mech_player[1]

# Game loop, goes until one player wins
while game_over is not True:
    # If the player's mech is overheated, their turn is skipped
    if (mech_player[0].over_heated if player else mech_player[1].over_heated):
        print("Your mech is overheated.  You have to wait a turn.")
        time.sleep(2)
        if player:
            mech_player[0].over_heated = not mech_player[0].over_heated
        else:
            mech_player[1].over_heated = not mech_player[1].over_heated
    else:
        damage_total = {}
        location = []
        opplocation = []
        weapon_choice = 0
        # Prints the field
        for x in xrange(len(grid)):
            for y in xrange(len(grid[x])):
                if grid[x][y] is 0:
                    print("|  "),
                else:
                    if grid[x][y] is mech_player[0]:
                        print("| 1"),
                    else:
                        print("| 2"),
                    if ((player and grid[x][y] == mech_player[0]) 
                            or (not player and grid[x][y] == mech_player[1])):
                        location.append(x)
                        location.append(y)
                    if ((player and grid[x][y] == mech_player[1]) 
                            or (not player and grid[x][y] == mech_player[0])):
                        opplocation.append(x)
                        opplocation.append(y)
            print("|")
        for i in xrange(len(grid)):
            print("---"),
        print("-")
        print("Player {}\n").format(1 if player else 2)
        mech_player[0].displayMainStats(mech_player[0]) if player else mech_player[1].displayMainStats(mech_player[1])
        print("")
        # Handles the player movement
        while True:
            print("Player {} which direction would").format(1 if player else 2),
            print("you like to move (A:W:S:D) or 0 if you don't want to move:")
            move_choice = move_validation()
            if checkMove(move_choice, location, grid):
                break
        distance = computeDistance(location, opplocation)
        print("Player {}, select which weapon to use:").format(1 if player else 2)
        # Only displays if there is a available at this range to fire
        if ((not mech_player[0].displayStats(distance)) if player 
                else not mech_player[1].displayStats(distance)):
            player = not player
            continue
        weapon_choice = int_validation(len(mech_player[0].weapon_set) 
                if player else len(mech_player[1].weapon_set))
        damage_total = (mech_player[0].releasePayload(weapon_choice - 1, distance) 
                if player else mech_player[1].releasePayload(weapon_choice - 1, distance))
        time.sleep(2)
        game_over = mech_player[1].computeDamageReceived(damage_total) if player else mech_player[0].computeDamageReceived(damage_total)
        time.sleep(2)
        if game_over:
            break
	player = not player
print("The match has finished!")
print("Player {} has defeated his enemy!").format(1 if player else 2)