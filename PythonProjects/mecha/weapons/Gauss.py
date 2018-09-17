from weapon import Weapon

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
