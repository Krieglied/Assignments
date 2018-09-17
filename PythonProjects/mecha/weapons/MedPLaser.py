from weapon import Weapon

class MedPLaser(Weapon):
    def __init__(self):
        name = "Medium Pulse Laser"
        damage = 7
        heat = 4
        wtype = "L"
        wrange = 4
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
