from mecha import Mecha
from weapons.PPC import PPC
from weapons.AC import AC
from weapons.LRM import LRM

class Summoner(Mecha):
    def __init__(self):
        mecha_type = "Summoner"
        everyone_chance = 35
        linked_chance = 0
        normal_chance = 30
        hit_points = 80
        heat_sink = 70
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(AC())
        weapon_set.append(LRM())
        weapon_set.append(PPC())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        if len(damage_total) > 1:
            if self.hit_points - 10 < 0:
                return True
            else:
                self.hit_points -= 10
                return False
        else:
            for damage_type, damage_value in damage_total.iteritems():
                if(self.hit_points - damage_value < 0):
                    return True
                else:
                    self.hit_points -= damage_value
                    return False
