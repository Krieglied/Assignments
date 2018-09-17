from weapon import Weapon

class PPC(Weapon):
    def __init__(self):
        name = "Extended Range Particle Projector Cannon"
        damage = 15
        heat = 15
        wtype = "P"
        wrange = 7
        Weapon.__init__(self, name, damage, heat, 0, wtype, wrange)
