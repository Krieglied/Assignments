taxes = 0.0825
cost = float(raw_input("Please input how much the item cost: "))
print "Without taxes, item costs {}".format(cost)
cost = cost + (cost * taxes)
print "Taxes for the item are {} % percent".format(taxes*100)
print "With taxes, item cost {0:.2f}".format(cost)
