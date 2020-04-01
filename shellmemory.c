/* Written by Eylül Ertay in January 2020
  Student ID: 260945126
  McGill University Operating Systems COMP310
  Assignment 1 / OS Shell */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shellmemory.h"

memory shell_mem[1000];

int printVar(char *var) {

  // Variable to keep track of whether a variable has been found in memory
  int found = 0;

  // Iterate through shell memory, print var if found
  for (int i = 0; i < 5; i++) {
    if (shell_mem[i].var != NULL && (strcmp(shell_mem[i].var, var) == 0)) {
      found = 1;
      printf("%s\n", shell_mem[i].value);
    }
  }

  if (!found) {
    printf("Variable does not exist\n");
  }

  return 0;
}

int setVar(char *var, char *value) {

  // Variable to keep track of whether a variable has been found in memory
  int found = 0;

  for (int i = 0; i < 1000; i++) {

    // Check if the cell is empty and if not compare the variables
    if (shell_mem[i].var != NULL && (strcmp(shell_mem[i].var, var) == 0)) {
      shell_mem[i].value = value;

      found = 1;
    }

    // Add new variable if it doesn't exist already
    else if (!found && shell_mem[i].var == NULL) {
      shell_mem[i].var = var;
      shell_mem[i].value = value;
      found = 1;
    }
  }

  return 0;
}
