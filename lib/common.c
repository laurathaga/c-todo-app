#include "../headers/common.h"
#include <stdio.h>

void read_line(char *des)
{
  char *curr = des;

  int ch = getchar();

  while (ch == ' ' || ch == '\n')
    ch = getchar();
  
  while (ch != '\n') 
  {
    *curr++ = ch;

    ch = getchar();
  }
  
  *curr = '\0';
}

void str_cpy(char *des, const char *str, int size)
{
  int counter = 0;

  while (counter++ < size && *str)
  {
    *des++ = *str++;
  }

  *des = 0;
}

char *to_char(unsigned long id)
{
  static char num[1];

  num[0] = id + '0';

  return num;
}

void list_commands(void) {
  printf("In order to interact with the app you can press: \n\n");
  printf("i - (insert) -  for inserting new todo; \n");
  printf("u - (update) -  for updating an existing todo; \n");
  printf("l - (list)   -  for listing all todos; \n");
  printf("d - (delete) -  for deleting a todo. \n");
  printf("c - (clear)  -  for clearing all todos. \n");
  printf("q - (quit)   -  for quiting the app. \n");
}
