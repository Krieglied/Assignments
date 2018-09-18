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