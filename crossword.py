#
#
#


from __future__ import print_function
from pyswip.prolog import Prolog
from pyswip.easy import *



def main():
    prolog.consult("readtest.pl")

    #result = list(prolog.query("L=%s,sudoku(L)" % p, maxresult=1))
    # Run command to add words to knowledgebase
    prolog.query(readFileSee("/home/tyler/Documents/crossword_solver/word_list.txt")
    #list(prolog.query("word(doesn^t, _,_,_,_,_,_,_)"))

    #prolog.query("word(doesn^t,_,_,_,_,_,_,_)")
    for soln in prolog.query("Y(X,_,_,_,_,_,_,_)")
    #print(soln["X"], "is the father of", soln["Y"])


    print(" -- SOLUTION --")



if __name__ == "__main__":
    prolog = Prolog()
    main()
