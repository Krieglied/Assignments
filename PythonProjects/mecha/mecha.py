# mecha.py

"""
    This file handles the definitions and functions of the base mecha class
    and all of the sub variants.
"""

import time
import random
from weapon import Weapon
# Base Class for all mechs
class Mecha(object):
    def __init__(self, wset, mtype, echance, lchance, nchance, hp, hsink):
        # Loadout for the particular mech
        self.weapon_set = wset
        self.mecha_type = mtype
        # Each mech has a unique precentage for how often a special attack occurs
        # when the attack option is selected
        self.everyone_chance = echance
        self.linked_chance = lchance
        self.normal_chance = nchance
        self.hit_points = hp
        # Limits the actions of the player.  Their action pool
        self.heat_sink = hsink
        # Tracks if the mech is overheated
        self.over_heated = False
    # Basic display information about the mech
    def displayMainStats(self):
        print("Type: {}\nHit Points: {}\nHeat Tank: {}\n").format(
                self.mecha_type, self.hit_points, self.heat_sink)
    # Display information and weapons loadout for the mech
    def displayStats(self, distance):
        displayed = []
        print("Displaying Stat\n")
        self.displayMainStats()
        print("======WEAPONS=====")
        slot = 0
        for weapon in self.weapon_set:
            if (weapon.weapon_name not in displayed) and weapon.weapon_range >= distance:
                displayed.append(weapon.weapon_name)
                print("({})").format(slot + 1)
                weapon.displayWeaponStats()
                slot += 1
        if slot == 0:
            print("No weapon with range, available to fire. "),
            print("Changing to next player.")
            return False
        else:
            print("\n")
            return True
    # Each attack subtracts its heat cost from the heat sink
    def soakHeat(self, hamount):
        self.heat_sink -= hamount
        if self.heat_sink <= 0:
            print("Your mech has overheated. "), 
            print("You're out of action for a turn.")
            self.heat_sink = 15
            self.over_heated = True
    # Method that handles firing all available weapons that have range
    def fireAllWeapons(self, dbonus, hbonus, distance):
        heat_soak_total = 0
        # Weapon type has to be stored as well as damage
        damage_total = {}
        for weapon in self.weapon_set:
            damage_total = self.loadWeaponDamage(
                    weapon, damage_total, dbonus, distance)
            heat_soak_total += weapon.heat_cost
        heat_soak_total = int(heat_soak_total * hbonus)
        self.soakHeat(heat_soak_total)
        return damage_total
    # Builds the dictionary that holds the type of damage and amount
    def loadWeaponDamage(self, selected, damage_total, dbonus, distance):
        if selected.weapon_range < distance:
            return damage_total
        if selected.weapon_type not in damage_total:
            damage_total[selected.weapon_type] = int(dbonus * selected.fireWeapon())
        else:
            damage_total[selected.weapon_type] += int(dbonus * selected.fireWeapon())
        return damage_total
    # All weapons that match the selected weapon are fired
    def linkedWeaponsFire(self, selected):
        damage_total = {}
        heat_soak_total = 0
        damage = 0
        for weapon in self.weapon_set:
            if weapon.weapon_name == selected.weapon_name:
                damage += weapon.fireWeapon()
                heat_soak_total += weapon.heat_cost

        damage_total[selected.weapon_type] = damage
        self.soakHeat(heat_soak_total)
        return damage_total
    # Overall function that handles damage output for the four
    # types of attacks (normal, linked, everyone, death blossom)
    def releasePayload(self, index, distance):
        damage_total = {}
        displayed = []
        position = 0
        location = 0
        for weapon in self.weapon_set:
            if weapon.weapon_name not in displayed:
                displayed.append(weapon.weapon_name)
                if position == index:
                    break
                position += 1
            location += 1
        selected = self.weapon_set[location]
        chance = random.randint(1, 101) 
        if chance <= self.normal_chance:
            self.soakHeat(selected.heat_cost)
            damage_total[selected.weapon_type] = selected.fireWeapon()
            return damage_total
        elif chance <= (self.normal_chance + self.linked_chance):
            print("Focus Fire!!")
            time.sleep(2)
            return self.linkedWeaponsFire(selected)
        elif chance <= (
                self.normal_chance + self.linked_chance + self.everyone_chance):
            print("Bring Everyone.")
            time.sleep(2)
            print("Everyone? .....")
            time.sleep(2)
            print("EVERYONE!!!!")
            time.sleep(2)
            return self.fireAllWeapons(1, 0.75, distance)
        else:
            print("Initiating.....")
            time.sleep(2)
            print("Death Blossom")
            time.sleep(2)
            return self.fireAllWeapons(1.5, 2, distance)
