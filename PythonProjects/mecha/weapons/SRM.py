import time
import random
from weapon import Weapon

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
