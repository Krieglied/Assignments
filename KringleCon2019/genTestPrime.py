import sympy

primes = list(sympy.primerange(1137,7731))
for prime in primes:
    notprime = ['0','2','4','5','6','8','9']
    found = True
    for nprime in notprime:
        if nprime in str(prime):
           found = False
    if found:
        if not (str(prime).count('1') > 2 or str(prime).count('3') > 2 or str(prime).count('7') > 2):
            print(prime)
