#include "./headers/task.h"
#include "./headers/common.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char is_valid_op(char *op) {
  printf("todos: ");
  scanf(" %c", op);

  if (
      *op == 'i' ||
      *op == 'u' ||
      *op == 'd' ||
      *op == 'l' ||
      *op == 'q' ||
      *op == 'h' ||
      *op == 'c'
    ) {
    return TRUE;
  }

  return FALSE;
}

void print_help() {
  printf("Press \"h\" if you need help for\ninteracting with the app\n");
}

void intro(void) {
  printf("\n========== TODOS ==========\n\n");
  print_help();
  printf("\n==============================\n\n");
}

int main(void)
{
  char op = '\0';
  intro();
  init_tasks();

  while (TRUE) {
    if (!is_valid_op(&op))
    {
      printf("the command you entered is invalid! \n\n");
      print_help();
    }
    else if (op == 'q')
      break;
    else
      handle_op(&op);
  }

  return(0);
}
