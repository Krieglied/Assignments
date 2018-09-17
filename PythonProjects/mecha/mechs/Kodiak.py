from mecha import Mecha
from weapons.AC import AC
from weapons.ERMedLaser import ERMedLaser
from weapons.ERLargeLaser import ERLargeLaser
from weapons.SRM import SRM

class Kodiak(Mecha):
    def __init__(self):
        mecha_type = "Kodiak"
        everyone_chance = 5
        linked_chance = 5
        normal_chance = 85
        hit_points = 100
        heat_sink = 50
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(AC())
        weapon_set.append(ERLargeLaser())
        weapon_set.append(SRM())
        weapon_set.append(SRM())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        weapon_set.append(ERMedLaser())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        for damage_type, damage_value in damage_total.iteritems():
            if damage_type == "R":
                damage_value -= 5
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False
