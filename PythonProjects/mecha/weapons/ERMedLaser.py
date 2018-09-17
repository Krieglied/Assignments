from weapon import Weapon

class ERMedLaser(Weapon):
    def __init__(self):
        name = "Extended Range Medium Laser"
        damage = 7
        heat = 5
        wtype = "L"
        wrange = 5
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
