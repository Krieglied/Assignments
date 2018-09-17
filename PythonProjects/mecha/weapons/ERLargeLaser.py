from weapon import Weapon

class ERLargeLaser(Weapon):
    def __init__(self):
        name = "Extended Range Large Laser"
        damage = 10
        heat = 12
        wtype = "L"
        wrange = 8
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
