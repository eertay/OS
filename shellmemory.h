/* Written by Eylül Ertay in January 2020
  Student ID: 260945126
  McGill University Operating Systems COMP310
  Assignment 1 / OS Shell */


typedef struct {
  char *var;
  char *value;
} memory;

int printVar(char *var);
int setVar(char *var, char *value);
