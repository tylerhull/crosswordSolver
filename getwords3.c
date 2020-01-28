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
#define out_path "/home/tyler/Documents/Github/crosswordSolver/allword_list.txt"
#define INPUT_BUF_LEN 80      // Length of input buffer


//------------------------------------------------------------------------------
int main(){
  FILE* dict;   // Set file pointer for our dictionary list
  FILE* output; // Set file pointer for our output file with prolog syntax
                // We output to a .txt file which can be read and asserted
                // into a prolog knowledge base using assertz.

  //----------------------------------------------------------------------------
  // **** COUNT THE NUMBER OF WORDS IN THE FILE ****
  // Open the Dictionary file and count how many lines there are.
  // We assume there are only 1 word per line.
  int count = 0;  // Line counter (result)
  int DICT_WORD_SIZE = 0; // Counter for the number of words in file
  char c;  // To store a character read from file

  printf("Counting the number of lines in the file...\n");    // Print to terminal when we start.
  if ((dict = fopen(dict_path,"r")) == NULL) {  // Open a file to the dictionary
      printf("Make sure you update the #define with the path to your file.\n");
      exit(1);    // If the path is wrong, give an error message and exit.
  }

  // Extract characters from file and store in character c
  for (c = getc(dict); c != EOF; c = getc(dict)){
    if (c == '\n') // Increment count if this character is newline
      count = count + 1;
  }
  // Close the file
  fclose(dict);
  DICT_WORD_SIZE = count;  // Set the size of the dictionary to line count


  //----------------------------------------------------------------------------
  // **** COUNT THE NUMBER OF LETTERS IN EACH WORD ****
  // Count the number of letters in each word and store them in an array.

  int wordLength = 0; // Counter for the length of words
  int wordLengthArr[DICT_WORD_SIZE];
  int arrayInt = 0;

  printf("Counting the number letters in each word...\n");    // Print to terminal when we start.
  if ((dict = fopen(dict_path,"r")) == NULL) {  // Open a file to the dictionary
      printf("Make sure you update the #define with the path to your file.\n");
      exit(1);    // If the path is wrong, give an error message and exit.
  }

  // Extract characters from file and store in character c
  for (c = getc(dict); c != EOF; c = getc(dict)){
    if (c != '\n'){
      wordLength = wordLength + 1;
      wordLengthArr[arrayInt] = wordLength;

    }
    if (c == '\n'){ // Increment count if this character is newline
      wordLengthArr[arrayInt] = wordLength;
      arrayInt = arrayInt + 1;
      wordLength = 0;

    }
  }

  // Close the file
  fclose(dict);
  printf("The file has %d lines\n ", count);
  DICT_WORD_SIZE = count;  // Set the size of the dictionary to line count
  sleep(0.5);



  //----------------------------------------------------------------------------
  // **** SETUP TO READ FILES AGAIN ****
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

    //**** Search words for a ' or a \n and correct them ****
    int stringLength = strlen(buf);
    if(strlen(buf) == 8) {    // Need to use 8 here because of the newline char.
        for (j=0; j < wordLengthArr[j]; j++){  // Search current word for the ' character
          if (buf[j]== '\''){     // Check to see if the current char is a '
            buf[j] = '^';         // Replace the ' with a ^ and continue'
          }
          if (buf[j] == '\n'){        // Find the newline characters
            buf[stringLength-1] = 0;  // Replace the newline character with 0.
          }                           // This allows us to print words properly.
        }

      buf[0] = tolower(buf[0]); // Force the first character to lowercase
  
      printf("word(%s,[%c,%c,%c,%c,%c,%c,%c],7).\n", buf,buf[0],buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
      fprintf (output,"word(%s,[%c,%c,%c,%c,%c,%c,%c],7).\n", buf,buf[0],buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
      wordcount = wordcount + 1;    // Count the number of words printed
    }
    sleep(0.9);
  }

  //----------------------------------------------------------------------------
  // **** CLEAN UP AND FINISH ****

  /* output each array element's value */
  int k = 0;        // Counter for finding largest word.
  int kount = 0;    // Keep track of largest word here.
  int element = 0;  // Keep track of line number of largest word.
  for (k = 0; k < DICT_WORD_SIZE; k++ ) {
  //  printf("Element[%d] = %d\n", k, wordLengthArr[k] );
    if (wordLengthArr[k] > kount){
      kount = wordLengthArr[k];
      element = k;
    }
  }

  // Print out the amount of words found out of the total number searched.
  printf("Found %d usable words out of %d words in file. \n", wordcount, totalcount);
  // printf("The file has %d lines\n", count);

  // Print location of largest word corrected for array starting at zero.
  printf("Largest word is %d characters at line number: %d\n", kount, element + 1);

  fclose(dict);   // Close the dictionary text file.
  fclose(output);   // Close the output text file.
}
