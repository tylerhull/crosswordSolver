// Tyler Hull - 1/19/20
// Modified from previous student work in ECE 579
// Program to get 7 letter words from dictionary file

// 1. Find 7 letter words using english3.txt
//    This file is found at http://www.gwicks.net/dictionaries.htm
//    and contains 194,000 english words.

// 2. Format them properly and print them out.
// 3. Could also write them to a file for proper prolog syntax.
// 4. .....

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Change the path below to the location of your folder.
// This can be found by using the terminal command "pwd"
// when you have navigated to the folder using "cd".
#define dict_path "/home/tyler/Documents/crossword_solver/english3.txt"
#define INPUT_BUF_LEN 80      // Length of input buffer
#define DICT_WORD_SIZE 194000 // Size of Dictionary used


int main(int argc, char* argv[]){
  FILE* dict;

  char buf[INPUT_BUF_LEN];    // Input buffer
  int i,j;                    // Loop counters

  printf("Starting Getwords Program\n");
  if ((dict = fopen(dict_path,"r")) == NULL) {
      printf("Make sure you update the #define with the path.\n");
      exit(1);
  }

  printf("test1\n");
  // Look for a 7 letter word. Reject it if it has an apostrophe.
  // Make sure the word starts with a lower case letter since
  // capital letters are a variable in Prolog syntax.
  int count =0;
  for(i = 0; i < DICT_WORD_SIZE; i++) {
    fgets(buf, INPUT_BUF_LEN-1, dict);
    sleep(.1);
    printf("%s", buf);
    count = count + 1;
    printf("Word count is: %d \n",count );

    if(strlen(buf) ==8) {
      for(j=2; j<7; j++){
        if(buf[j]=='\'')
        printf("Removed %d word with apostrophe.\n",j);
        break;
      }
    }
    // sleep(.1);
    // printf("%s", buf);

    //print(" j is %d \n",j)
    if(j == 7) {        // means there is no ' character
    sleep(.1);
    printf("%s", buf);
      buf[0] = buf[0] | 0x20; // Must start with lowercase character
      buf[7] = 0;
      printf("word(%s,%c,%c,%c,%c,%c,%c,%c.\n", buf,buf[0],buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);

       sleep(.1);
       printf("%s", buf);
    }
  }
  fclose(dict);
}
