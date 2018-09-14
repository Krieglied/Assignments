# mecha_sub.py

"""
    Mecha currently allows for 8 different mech variants.  Each variant has
    a unique loadout of weapons, unique chances for special attacks, and
    a unique set of health and heat sink pools
"""

from mecha import Mecha
from weapon import *

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
    def computeDamageReceived(damage_total):
        for damage_type in damage_total:
            if damage_type.key == "L":
                damage_type.value -= 5
            if(self.hit_points - damage_type.value < 0):
                return True
            else:
                    self.hit_points -= damage_type.value
        return False

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
    def computeDamageReceived(damage_total):
        if len(damage_total) > 1:
            if self.hit_points - 10 < 0:
                return true
            else:
                self.hit_points -= 10
                return false
        else:
            for damage_type in damage_total:
                if(self.hit_points - damage_type.value < 0):
                    return True
                else:
                    self.hit_points -= damage_type.value
                    return False

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
    def computeDamageReceived(damage_total):
        for damage_type in damage_total:
            if damage_type.key == "M":
                damage_type.value -= 5
            if(self.hit_points - damage_type.value < 0):
                return True
            else:
                    self.hit_points -= damage_type.value
        return False

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
    def computeDamageReceived(damage_total):
        for damage_type in damage_total:
            if damage_type.key == "K":
                damage_type.value -= 5
            if(self.hit_points - damage_type.value < 0):
                return True
            else:
                    self.hit_points -= damage_type.value
        return False

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
    def computeDamageReceived(damage_total):
        for damage_type in damage_total:
            if damage_type.key == "R":
                damage_type.value -= 5
            if(self.hit_points - damage_type.value < 0):
                return True
            else:
                    self.hit_points -= damage_type.value
        return False

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
    def computeDamageReceived(damage_total):
        for damage_type in damage_total:
            if damage_type.key == "R" or damage_type.key == "L":
                damage_type.value -= 5
            if(self.hit_points - damage_type.value < 0):
                return True
            else:
                    self.hit_points -= damage_type.value
        return False

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
    def computeDamageReceived(damage_total):
        resist = True
        for damage_type in damage_total:
            if resist:
                damage_type.value -= 5
                resist = not resist
            if(self.hit_points - damage_type.value < 0):
                return True
            else:
                    self.hit_points -= damage_type.value
        return False
