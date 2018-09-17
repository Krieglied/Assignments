from mecha import Mecha
from weapons.LRM import LRM
from weapons.MedPLaser import MedPLaser
from weapons.LargePLaser import LargePLaser

class MadDog(Mecha):
    def __init__(self):
        mecha_type = "Mad Dog"
        everyone_chance = 20
        linked_chance = 20
        normal_chance = 57
        hit_points = 60
        heat_sink = 90
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(LRM())
        weapon_set.append(LRM())
        weapon_set.append(MedPLaser())
        weapon_set.append(MedPLaser())
        weapon_set.append(LargePLaser())
        weapon_set.append(LargePLaser())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        for damage_type, damage_value in damage_total.iteritems():
            if damage_type == "L":
                damage_value -= 5
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False
