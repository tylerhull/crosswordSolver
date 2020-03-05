// Tyler Hull - 1/19/20
// Modified from previous student work in ECE 579
// Program to get 7 letter words from dictionary file and write to .txt file
// Compile with: gcc -o getwords getwords2.c
// Run file with: ./getwords

// 1. Find 7 letter words using english3.txt
//    This file is found at http://www.gwicks.net/dictionaries.htm
//    and contains 194,000 english words.
//    -This file is hardcoded to get 7 characters words from the dictionary file.
//    -In order to get different size words, the print statements will need to
//     be modified to print the buffer array numbers to suit your word length.
//    -For example, for a word length of 3 you would write:

//     printf("word(%s,%c,%c,%c).\n", buf, buf[0], buf[1], buf[2]);
//     fprintf (output,"word(%s,%c,%c,%c).\n", buf, buf[0], buf[1], buf[2]);

// 2. Format them properly and print them out.
// 3. Write them to a file wih proper prolog syntax.
// 4. .... Could be modified to output text files for various lengths of words.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

// Change the path below to the location of your folder.
// This can be found by using the terminal command "pwd"
// when you have navigated to the folder using the "cd" command.
#define dict_path "/home/tyler/Documents/Github/crosswordSolver/english3.txt"
#define out_path "/home/tyler/Documents/Github/crosswordSolver/word_list5.txt"
#define INPUT_BUF_LEN 80      // Length of input buffer
#define DICT_WORD_SIZE 194000 // Size of Dictionary used


//------------------------------------------------------------------------------
int main(){
  FILE* dict;   // Set file pointer for our dictionary list
  FILE* output; // Set file pointer for our output file with prolog syntax
                // We output to a .txt file which can be read and asserted
                // into a prolog knowledge base using assertz.

  // **** SETUP TO READ FILES ****
  // Open a file to store our results in.
  output = fopen (out_path,"w");
  char buf[INPUT_BUF_LEN];    // Setup the input buffer to temporarily store words
  int i,j;                    // Setup our loop counters

  printf("Starting Getwords Program\n");    // Print to terminal when we start.
  if ((dict = fopen(dict_path,"r")) == NULL) {  // Open a file to the dictionary
      printf("Make sure you update the #define with the path to your file.\n");
      exit(1);    // If the path is wrong, give an error message and exit.
  }

  //----------------------------------------------------------------------------
  // **** READ EACH INPUT LINE, IF 7 CHARACTERS, WRITE TO FILE ****
  // Look for a 7 letter word. Fix it if it has an apostrophe.
  // Make sure the word starts with a lower case letter since
  // capital letters are a variable in Prolog syntax.
  int totalcount = 0;   // Variable for total words searched
  int wordcount = 0;    // Variable for number of 7 character words.
  for(i = 0; i < DICT_WORD_SIZE; i++) { // Set the loop for the dictionary length
    fgets(buf, INPUT_BUF_LEN-1, dict);  // fgets injects newline character at end
    totalcount = totalcount + 1;        // Cound the total number of words

    if(strlen(buf) == 6) {    // Need to use 8 here because of the newline char.
        for (j=0; j<5; j++){  // Search current word for the ' character
          if (buf[j]== '\''){ // Check to see if the current char is a '
            buf[j] = '^';     // Replace the ' with a ^ and continue'
          }
        }

      buf[0] = tolower(buf[0]); // Force the first character to lowercase
      buf[5] = 0;   // Replace the ending newline character with a 0.
                    // This lets us print the  new prolog term on one line.
      printf("word(%s,%c,%c,%c,%c,%c).\n", buf,buf[0],buf[1], buf[2], buf[3], buf[4]);
      fprintf (output,"word(%s,%c,%c,%c,%c,%c).\n", buf,buf[0],buf[1], buf[2], buf[3], buf[4]);
      wordcount = wordcount + 1;    // Count the number of words printed
    }
  }

  //----------------------------------------------------------------------------
  // **** CLEAN UP AND FINISH ****
  // Print out the amount of words found out of the total number searched.
  printf("Found %d usable words out of %d words in file. \n", wordcount, totalcount );

  fclose(dict);   // Close the dictionary text file.
  fclose(output);   // Close the output text file.
}
