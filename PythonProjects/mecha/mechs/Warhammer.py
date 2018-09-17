from mecha import Mecha
from weapons.PPC import PPC
from weapons.MedPLaser import MedPLaser
from weapons.SRM import SRM

class Warhammer(Mecha):
    def __init__(self):
        mecha_type = "Warhammer"
        everyone_chance = 15
        linked_chance = 18
        normal_chance = 65
        hit_points = 80
        heat_sink = 70
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(PPC())
        weapon_set.append(PPC())
        weapon_set.append(MedPLaser())
        weapon_set.append(MedPLaser())
        weapon_set.append(MedPLaser())
        weapon_set.append(MedPLaser())
        weapon_set.append(MedPLaser())
        weapon_set.append(SRM())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        for damage_type, damage_value in damage_total.iteritems():
            if damage_type == "K":
                damage_value -= 5
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False
