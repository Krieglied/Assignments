from mecha import Mecha
from weapons.Gauss import Gauss
from weapons.LargePLaser import LargePLaser
from weapons.SmallPLaser import SmallPLaser

class StoneRhino(Mecha):
    def __init__(self):
        mecha_type = "Stone Rhino"
        everyone_chance = 7
        linked_chance = 7
        normal_chance = 80
        hit_points = 100
        heat_sink = 50
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(Gauss())
        weapon_set.append(Gauss())
        weapon_set.append(LargePLaser())
        weapon_set.append(LargePLaser())
        weapon_set.append(SmallPLaser())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        for damage_type, damage_value in damage_total.iteritems():
            if damage_type == "R" or damage_type == "L":
                damage_value -= 5
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False
