# player.py
from mechs.mecha import Mecha
from mechs.Hellbringer import Hellbringer
from mechs.MadDog import MadDog
from mechs.Summoner import Summoner
from mechs.TimberWolf import TimberWolf
from mechs.Warhammer import Warhammer
from mechs.Kodiak import Kodiak
from mechs.StoneRhino import StoneRhino
from mechs.Mauler import Mauler
from validation.validation import int_validation

class Player(object):
    def __init__(self):
        self.location = []
        self.player_mech = Mecha()
    # User selects a mech to use for the game
    def suitUp(self):
        choices = 8
        mech_list = {1:Hellbringer(),
            2:MadDog(),
            3:Summoner(),
            4:TimberWolf(),
            5:Warhammer(),
            6:Kodiak(),
            7:StoneRhino(),
            8:Mauler()}
        print("PILOT\nSELECT YOUR MECH")
        for x in xrange(1, choices):
            print("({})").format(x)
            Mecha.displayMainStats(mech_list[x])
        print("\n\n(Input the number)"),
        mech_choice = int_validation(choices)
        self.player_mech = mech_list[mech_choice]
        Mecha.displayMainStats(self.player_mech)
