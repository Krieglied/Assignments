from mecha import Mecha
from weapons.PPC import PPC
from weapons.ERMedLaser import ERMedLaser
from weapons.SRM import SRM

class Hellbringer(Mecha):
    def __init__(self):
        mecha_type = "Hellbringer"
        everyone_chance = 10
        linked_chance = 15
        normal_chance = 65
        hit_points = 65
        heat_sink = 85
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(PPC())
        weapon_set.append(PPC())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(SRM())
        return weapon_set
    def computeDamageReceived(self,damage_total):
        for damage_type, damage_value in damage_total.iteritems():
            if damage_type== "P":
                damage_value -= 5
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False