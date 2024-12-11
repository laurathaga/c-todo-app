#include "./headers/task.h"
#include "./headers/common.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char is_valid_op(char *op) {
  printf("Please enter command: ");
  scanf(" %c", op);

  if (
      *op == 'i' ||
      *op == 'u' ||
      *op == 'd' ||
      *op == 'r' ||
      *op == 'q' ||
      *op == 'h'
    ) {
    return TRUE;
  }

  return(FALSE);
}

void print_help() {
  printf("Press \"h\" if you need help for interacting with the app\n");
}

void intro(void) {
  printf("\n========== TODO APP ==========\n\n");
  print_help();
  printf("\n==============================\n\n");
}

int main(void)
{
  char op = '\0';
  char count = 0;
  intro();
  init_tasks();

  while (TRUE) {
    if (!is_valid_op(&op))
    {
      printf("the command you entered is invalid! \n\n");
      print_help();
    }
    else if (op == 'q') 
    {
      break;
    }
    else
    {
      handle_op(&op);
    }

    if (count == 100) break;

    count++;
  }


  return(0);
}
