# crosswordSolver
Crossword solver written in Prolog with a Python interface

## Get new words from a text file and format for Prolog

*Modified from previous student work in ECE 579*.
Program to get 7 letter words from a dictionary text file and write to .txt file called *word_list.txt* 

Compile with: 
**gcc -o getwords getwords2.c**

Run file with: 
**./getwords**

1. Find 7 letter words using english3.txt
    This file is found at http://www.gwicks.net/dictionaries.htm
    and contains 194,000 english words.
    -This file is hardcoded to get 7 characters words from the dictionary file.
    -In order to get different size words, the print statements will need to
     be modified to print the buffer array numbers to suit your word length.
    -For example, for a word length of 3 you would write:

     printf("word(%s,%c,%c,%c).\n", buf, buf[0], buf[1], buf[2]);
     fprintf (output,"word(%s,%c,%c,%c).\n", buf, buf[0], buf[1], buf[2]);

 2. Format them properly and print them out.
 3. Write them to a file wih proper prolog syntax.
 4. Future work.... Could be modified to output text files for various lengths of words.


## Check to make your new word list will work with Prolog

Prolog code to read from a file and add terms to a knowledge base.
Modified from the following website:
https://stackoverflow.com/questions/16100438/how-to-read-all-the-prolog-predicate-in-a-txt-file-using-read-predicate-in-prol

This section of code will read from a file and add the contents to
the prolog knowledge base. Then the contents of the file can be querried.
Make sure that the file being read has terms in proper prolog syntax.

1. Compile the knowledge base with:
   **[readtest].**

2. Call this function from the command line or a program with:
   readFileSee('/home/tyler/Documents/crossword_solver/word_list.txt').
3. test with: word(doesn^t, _,_,_,_,_,_,_).
              returns true.
   test with: word(X, _,_,_,_,_,_,_).
              returns all results. Cycle through them with the ; character.
              Hit return key when you want to stop.

## Now that you have your list of words working, lets used them to solve crosswords

...
...
...
...

