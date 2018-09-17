from mecha import Mecha
from weapons.ERLargeLaser import ERLargeLaser
from weapons.LRM import LRM
from weapons.AC import AC

class Mauler(Mecha):
    def __init__(self):
        mecha_type = "Mauler"
        everyone_chance = 4
        linked_chance = 15
        normal_chance = 77
        hit_points = 90
        heat_sink = 60
        Mecha.__init__(self, self.setWeapons(), mecha_type, everyone_chance,
                linked_chance, normal_chance, hit_points, heat_sink)
    def setWeapons(self):
        weapon_set = []
        weapon_set.append(ERLargeLaser())
        weapon_set.append(ERLargeLaser())
        weapon_set.append(LRM())
        weapon_set.append(LRM())
        weapon_set.append(AC())
        weapon_set.append(AC())
        weapon_set.append(AC())
        weapon_set.append(AC())
        return weapon_set
    def computeDamageReceived(self, damage_total):
        resist = True
        for damage_type, damage_value in damage_total.iteritems():
            if resist:
                damage_value -= 5
                resist = not resist
            if(self.hit_points - damage_value < 0):
                return True
            else:
                self.hit_points -= damage_value
        return False
