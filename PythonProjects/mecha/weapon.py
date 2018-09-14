# weapon.py

""" 
    This file handles the definition of a weapon for the mech game
    and also the sub variants that exists
"""

import time
import random
# Base class for weapons
class Weapon(object):
    def __init__(self, name, dvalue, hvalue, avalue, wtype, rvalue):
        self.weapon_name = name
        self.damage = dvalue
        # If the weapon is fired, that will incur this action cost
        self.heat_cost = hvalue
        # Some weapons can only be fired a number of times
        self.ammo = avalue
        # Some mechs will be resistance to certain types of attack
        self.weapon_type = wtype
        # Since mechs can move, some weapons can't be fired if the 
        # opponent is too far away
        self.weapon_range = rvalue
    # Default print message to indicate what weapon fired and for 
    # how much damage
    def fireWeapon(self):
        print("Firing {} of type {} dealing {} damage.").format(
                self.weapon_name, self.weapon_type, self.damage)
        return self.damage
    def displayWeaponStats(self):
        print("Model: {}\nDamage: {}\nHeat Cost: {}\nRange: {}\n").format(
                self.weapon_name, self.damage, self.heat_cost, self.weapon_range)
# List of weapons currently available
class PPC(Weapon):
    def __init__(self):
        name = "Extended Range Particle Projector Cannon"
        damage = 15
        heat = 15
        wtype = "P"
        wrange = 7
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)

class ERMedLaser(Weapon):
    def __init__(self):
        name = "Extended Range Medium Laser"
        damage = 7
        heat = 5
        wtype = "L"
        wrange = 5
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)

class MedPLaser(Weapon):
    def __init__(self):
        name = "Medium Pulse Laser"
        damage = 7
        heat = 4
        wtype = "L"
        wrange = 4
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)

class LargePLaser(Weapon):
    def __init__(self):
        name = "Large Pulse Laser"
        damage = 10
        heat = 10
        wtype = "L"
        wrange = 6
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)

class ERLargeLaser(Weapon):
    def __init__(self):
        name = "Extended Range Large Laser"
        damage = 10
        heat = 12
        wtype = "L"
        wrange = 8
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
class SmallPLaser(Weapon):
    def __init__(self):
        name = "Small Pulse Laser"
        damage = 3
        heat = 2
        wtype = "L"
        wrange = 2
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)

class Gauss(Weapon):
    def __init__(self):
        name = "Gauss Rifle"
        damage = 15
        heat = 1
        ammo = 5
        wtype = "R"
        wrange = 7
        Weapon.__init__(self, name, damage, heat, ammo, wtype, wrange)
    def fireWeapon(self):
        if self.ammo == 0:
            print("Out of Ammo")
            return 0
        else:
            print("Firing {} of type {} dealing {} damage.").format(
                self.weapon_name, self.weapon_type, self.damage)
            self.ammo -= 1
            return self.damage
    def displayWeaponStats(self):
        print("Model: {}\nDamage: {}\nHeat Cost: {}").format(
                self.weapon_name, self.damage, self.heat_cost)
        print("Ammunition: {}\nRange: {}\n").format(
                self.ammo, self.weapon_range)

class AC(Weapon):
    def __init__(self):
        name = "Autocannon"
        damage = 10
        heat = 3
        ammo = 15
        wtype = "K"
        wrange = 5
        Weapon.__init__(self, name, damage, heat, ammo, wtype, wrange)
    def fireWeapon(self):
        if self.ammo == 0:
            print("Out of Ammo")
            return 0
        else:
            print("Firing {} of type {} dealing {} damage.").format(
                self.weapon_name, self.weapon_type, self.damage)
            self.ammo -= 1
            return self.damage
    def displayWeaponStats(self):
        print("Model: {}\nDamage: {}\nHeat Cost: {}").format(
                self.weapon_name, self.damage, self.heat_cost)
        print("Ammunition: {}\nRange: {}\n").format(
                self.ammo, self.weapon_range)

class AC20(Weapon):
    def __init__(self):
        name = "Autocannon/20"
        damage = 20
        heat = 7
        ammo = 15
        wtype = "K"
        wrange = 3
        Weapon.__init__(self, name, damage, heat, ammo, wtype, wrange)
    def fireWeapon(self):
        if self.ammo == 0:
            print("Out of Ammo")
            return 0
        else:
            print("Firing {} of type {} dealing {} damage.").format(
                self.weapon_name, self.weapon_type, self.damage)
            self.ammo -= 1
            return self.damage
    def displayWeaponStats(self):
        print("Model: {}\nDamage: {}\nHeat Cost: {}").format(
                self.weapon_name, self.damage, self.heat_cost)
        print("Ammunition: {}\nRange: {}\n").format(
                self.ammo, self.weapon_range)

class LRM(Weapon):
    def __init__(self):
        name = "Long Range Missles"
        damage = 10
        heat = 6
        ammo = 10
        wtype = "M"
        wrange = 7
        Weapon.__init__(self, name, damage, heat, ammo, wtype, wrange)
    def fireWeapon(self):
        if self.ammo == 0:
            print("Out of Ammo")
        else:
            result = 0
            for i in range(10):
                if random.randint(1, 11) > 7:
                    result += 1
            if result < 2:
                result = 2
            print("Firing {} of type {} dealing {} damage.").format(
                    self.weapon_name, self.weapon_type, result)
            self.ammo -= 1
            return result
    def displayWeaponStats(self):
        print("Model: {}\nDamage: {}\nHeat Cost: {}").format(
                self.weapon_name, self.damage, self.heat_cost)
        print("Ammunition: {}\nRange: {}\n").format(
                self.ammo, self.weapon_range)

class SRM(Weapon):
    def __init__(self):
        name = "Short Range Missles"
        damage = 10
        heat = 4
        ammo = 10
        wtype = "M"
        wrange = 3
        Weapon.__init__(self, name, damage, heat, ammo, wtype, wrange)
    def fireWeapon(self):
        if self.ammo == 0:
            print("Out of Ammo")
        else:
            result = 0
            for i in range(10):
                if random.randint(1, 11) > 7:
                    result += 1
            if result < 2:
                result = 2
            print("Firing {} of type {} dealing {} damage.").format(
                    self.weapon_name, self.weapon_type, result)
            self.ammo -= 1
            return result
    def displayWeaponStats(self):
        print("Model: {}\nDamage: {}\nHeat Cost: {}").format(
                self.weapon_name, self.damage, self.heat_cost)
        print("Ammunition: {}\nRange: {}\n").format(
                self.ammo, self.weapon_range)
