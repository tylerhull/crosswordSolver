#readtest.py

from __future__ import print_function
from pyswip.prolog import Prolog
from pyswip.easy import registerForeign, getAtomChars


def hello(t):
    print("Hello,", t)
hello.arity = 1


def main():
    registerForeign(hello)
    prolog = Prolog()
    #prolog.assertz("father(michael,john)")
    #prolog.assertz("father(michael,gina)")
    #list(prolog.query("father(michael,X), hello(X)"))
    Query(readFileSee('/home/tyler/Documents/Github/crosswordSolver/word_list.txt')))


if __name__ =="__main__":
    main()
