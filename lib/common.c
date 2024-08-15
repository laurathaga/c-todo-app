#include "../headers/common.h"
#include <stdio.h>

void read_line(char *des)
{
  char *curr = des;

  int ch;
  
  // skip white spaces and new line at the beggining
  while ((ch = getchar()) == ' ') 
    ;

  while ((ch = getchar()) != '\n')
  {
    *curr++ = ch;
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
