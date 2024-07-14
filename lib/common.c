#include "../headers/common.h"
#include <stdio.h>

void read_line(char *des)
{
  int ch = getchar();

  // skip white spaces and new line at the beggining
  while (ch == ' ' || ch == '\n')
    ;

  while ((ch = getchar()) != '\n')
  {
    *des++ = ch;
  }

  *des = '\0';
}
