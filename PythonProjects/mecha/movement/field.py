# field.py

class Field(object):
    def __init__(self, columns, rows):
        self.grid = [[0 for x in range(columns)] for y in range(rows)]
        self.players = {}
    def printGrid(self, players):
        # Prints the field
        for x in xrange(len(self.grid)):
            for y in xrange(len(self.grid[x])):
                if self.grid[x][y] is 0:
                    print("|  "),
                else:
                    if self.grid[x][y] in players:
                        print("| {}").format(players.index(self.grid[x][y]) + 1),
                        self.players[self.grid[x][y]] = {x,y}
            print("|")
        for i in xrange(len(self.grid)):
            print("---"),
        print("-")
    def addPlayer(self, x, y, mech):
        self.grid[x][y] = mech
        self.players[mech] = {}