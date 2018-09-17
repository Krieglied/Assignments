from mecha import Mecha
from weapons.ERLargeLaser import ERLargeLaser
from weapons.ERMedLaser import ERMedLaser
from weapons.LRM import LRM

class TimberWolf(Mecha):
    def __init__(self):
        mecha_type = "Timber Wolf"
        everyone_chance = 15
        linked_chance = 30
        normal_chance = 45
        hit_points = 75
        heat_sink = 75
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(ERLargeLaser())
        weapon_set.append(ERLargeLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(LRM())
        weapon_set.append(LRM())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        for damage_type, damage_value in damage_total.iteritems():
            if damage_type == "M":
                damage_value -= 5
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False
