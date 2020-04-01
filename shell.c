/* Written by Eylül Ertay in January 2020
  Student ID: 260945126
  McGill University Operating Systems COMP310
  Assignment 1 / OS Shell */


#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include <string.h>
#include <assert.h>


/** Parser adapted from the lecture slides
*/

int parser(char userInp[]) {

  char temp[200];
  int a,b;
  char *words[100];
  // Words index
  int w = 0;

  // Getting rid of \r and \n
  if (userInp[strlen(userInp) - 1] == '\r' || userInp[strlen(userInp) -1] == '\n' ) {
        userInp[strlen(userInp) - 1] = '\0';
  }

  // Skips white spaces
  for(a=0; userInp[a]==' ' && a<1000; a++);

  while(userInp[a] != '\0' && a<1000) {

    for(b=0; userInp[a]!='\0' && userInp[a]!=' ' && a<1000; a++, b++) {

      // Extracts a word
      temp[b] = userInp[a];
    }

    temp[b] = '\0';
    words[w] = strdup(temp);

    a++; w++;
  }

  return interpreter(words);
}

int main(int argc, char const *argv[]) {

  char prompt[100] = {'$', '\0'};
  char userInp[1000];
  int errorCode = 0;


  printf("Welcome to the Eylül shell!\n");
  printf("Version 1.0 Created January 2020\n");

  while (1) {

    printf("%s", prompt);
    fgets(userInp, 999, stdin);
    strtok(userInp, "\n");
    errorCode = parser(userInp);

    if (errorCode == -1) {
      exit(1);
    }

  }

  return 0;
}
