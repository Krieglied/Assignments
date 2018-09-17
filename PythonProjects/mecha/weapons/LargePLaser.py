from weapon import Weapon

class LargePLaser(Weapon):
    def __init__(self):
        name = "Large Pulse Laser"
        damage = 10
        heat = 10
        wtype = "L"
        wrange = 6
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
