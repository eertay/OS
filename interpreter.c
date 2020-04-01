/* Written by Eylül Ertay in January 2020
  Student ID: 260945126
  McGill University Operating Systems COMP310
  Assignment 1 / OS Shell */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "shell.h"
#include "shellmemory.h"


int help() {

  printf("These shell commands are defined internally.  Type 'help' to see this list.\n");
  printf("COMMAND\t\t\t\tDESCRIPTION\n");
	printf("help\t\t\t\tDisplays all the commands\n");
	printf("quit\t\t\t\tExits / terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING\t\t\tAssigns a value to shell memory\n");
	printf("print VAR\t\t\tDisplays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT\t\t\tExecutes the file SCRIPT.TXT\n");

  return 0;
}

int quit() {

  printf("Bye!\n");
  exit(0);
  return 0;
}

int unknown() {
  printf("Unknown command\n");
  return 0;
}


int run(char *words[]) {

  int errorCode;
	char * fileName = strdup(words[1]);
	FILE * file = fopen(fileName, "r");
  char line[1000];

	if(file == NULL){
		printf("Script not found\n");
		errorCode = 0;
		return errorCode;
	}


  while(fgets(line, 999, file)){
		errorCode = parser(line);
	}

	return errorCode;

}

/* Public */
int interpreter(char *words[]) {

  int errorCode = 0;

  if(words[0] == NULL) {
      unknown();
      return errorCode;
  }


  // Comparing the imput to valid commands, returning unknown otherwise
  if (strcmp(words[0], "help") == 0) {
    errorCode = help();
  }

  else if (strcmp(words[0], "quit") == 0) {
    errorCode = quit();
  }

  else if (strcmp(words[0], "set") == 0) {
    errorCode = setVar(words[1], words[2]);
  }

  else if (strcmp(words[0], "print") == 0) {
    errorCode = printVar(words[1]);
  }

  else if (strcmp(words[0], "run") == 0) {

    errorCode = run(words);
  }

  else {
    errorCode = unknown();
  }
  return errorCode;
}
