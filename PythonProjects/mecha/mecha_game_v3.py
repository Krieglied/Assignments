# mecha_game.py

# Robert John Graham III
# September 14 2018

"""
    Yet another build of the Mecha game.  This version compartmentizes functionsm,
    adds opponent features, and network play functionality.
"""
from player.player import Player
from validation.validation import int_validation

player_min = 1
player_max = 8
print("Please enter the number of human players (between {} and {}).").format(
        player_min, player_max)
# Make sure that the input for the number of players is validated
numb_players = int_validation(player_max)
current_player = Player()
current_player.suitUp()
