# mecha_game.py

# Robert John Graham III
# September 14 2018

"""
    Yet another build of the Mecha game.  This version compartmentizes functionsm,
    adds opponent features, and network play functionality.
"""
from player.player import Player
from validation.validation import int_validation
from movement.field import Field

player_min = 1
player_max = 8
print("Please enter the number of human players (between {} and {}).").format(
        player_min, player_max)
# Make sure that the input for the number of players is validated
numb_players = int_validation(player_max)
current_player = Player()
current_player.suitUp()
test_player = Player()
test_player.suitUp()
list_of_players = []
list_of_players.append(current_player)
list_of_players.append(test_player)
field = Field(20, 20)
field.addPlayer(0, 0, current_player)
field.addPlayer(0, 1, test_player)
while True:
    ready_up = raw_input("Enter any key to yes you're ready:::")
    if ready_up is not None:
        break
print("Game....START!")
game_over = False
field.printGrid(list_of_players)
# while game_over is not True:
