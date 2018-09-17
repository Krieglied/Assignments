from weapon import Weapon

class SmallPLaser(Weapon):
    def __init__(self):
        name = "Small Pulse Laser"
        damage = 3
        heat = 2
        wtype = "L"
        wrange = 2
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
