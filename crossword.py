#
#
#


from __future__ import print_function
from pyswip import *


def main():


    p = Prolog()

    father = Functor("father", 2)
    mother = Functor("mother", 2)
    assertz = Functor("assertz", 1)


    file = open("word_list.txt", "r")
    for x in file:
    print(x)
    p.assertz(x)


    X = Variable(); Y = Variable(); Z = Variable()

    listing = Functor("listing", 1)
    call(listing(father))

    q = Query(father("john",Y), mother(Z,Y))
    while q.nextSolution():
        print(Y.value, Z.value)
    q.closeQuery()    # Newer versions of SWI-Prolog do not allow nested queries

    print("\nQuery with strings\n")
    for s in p.query("father(john,Y),mother(Z,Y)"):
        print(s["Y"], s["Z"])

if __name__ == "__main__":
    main()
