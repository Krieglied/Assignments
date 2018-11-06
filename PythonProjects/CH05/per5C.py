# Performance Lab 5B
# Robert John Graham III
# September 13 2018

"""
Create a very simple super hero class. Some attributes you will need:

    Hero Name
    Real Name
    Power(s)
    Colors
    etc
"""
# Class has an init, and getters/setters for all variables
class SuperHero():

    def __init__(self):
        self.hero_name = "Batman"
        self.real_name = "Bruce Wayne"
        self.powers = ["Rich", "Gadgets"]
        self.colors = ["Black", "Yellow"]

    # Default message for the class
    def default_message(self):
        print("The super hero is {} whose real name is {}.").format(
                self.hero_name, self.real_name)
        print("The super heor has {} powers and dresses in {} colors").format(
                self.powers, self.colors)
        return "End of Message"

    # Getters/Setters
    def setHero(name):
        self.hero_name = name
    def getHero():
        return self.hero_name
    def setReal(name):
        self.real_name = name
    def getReal():
        return self.real_name
    def addPower(power):
        self.powers.append(power)
    def delPower(power):
        self.powers.remove(poweri)
    def getPowers():
        return self.powers
    def addColor(color):
        self.colors.append(color)
    def delColor(color):
        self.colors.remove(color)
    def getColors():
        return self.colors


x = SuperHero()
print x.default_message()
