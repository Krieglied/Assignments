"""
Robert John Graham III
Lab 2G: Planets Exercise
Recommended Version: Python 2.7
September 5 2018

Instructions:
-Follow TODO's below
"""


planet_string = "Mercury|Venus|Earth|Mars|Jupiter|Saturn|Uranus|Neptune"
planet_list = []
#TODO: Convert planets_string to a list, save it to planet_list.
planet_list.extend(planet_string.split("|"))

def log_planets():
    print "Here is a list of the planets:"
    for planet in planet_list:
        print planet
    print "----------------\n\n"

log_planets()

print 'Adding "The Sun" to the beginning of the planets list.'
#TODO: Perform action above
planet_list.insert(0, "The Sun")
log_planets()

print 'Adding "Pluto" to the end of the planets list.'
#TODO: Perform action above
planet_list.append("Pluto")
log_planets()

print 'Removing "The Sun" from the beginning of the planets list.'
#TODO: Perform action above
planet_list.remove("The Sun")
log_planets()

print 'Removing "Pluto" from the end of the planets list.'
#TODO: Perform action above
planet_list.remove("Pluto")
log_planets()

print 'Finding and logging the index of "Earth" in the planets list.'
#TODO: Perform action above
earth_index = planet_list.index("Earth")
print "The Earth's index is {}".format(earth_index)
log_planets()

print 'Removing the planet after "Earth".'
#TODO: Perform action above.  
planet_removed = planet_list[earth_index+1]
planet_list.remove(planet_removed)
log_planets()

print 'Addding back in the planet removed after "Earth".'
#TODO: Perform action above
planet_list.insert(earth_index+1,planet_removed)
log_planets()

print 'Reversing the order of the planets list.'
#TODO Perform action above
planet_list = planet_list[::-1]
log_planets()

print 'Sorting the planets list'
#TODO Perform action above
planet_list.sort()
log_planets()
