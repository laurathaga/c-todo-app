#include "./headers/task.h"
#include "./headers/common.h"
#include <stdio.h>
#include <stdlib.h>

int is_valid_op(char *op) {
  if (*op == 'i' || *op == 'u' || *op == 'd' || *op == 'r') {
    return TRUE;
  }

  return FALSE;
}

void commands(void) {
  printf("In order to interact with the app you have to press: \n\n");
  printf("i - for inserting new todo; \n");
  printf("u - for updating an existing todo; \n");
  printf("r - for reading all the todos; \n");
  printf("d - for deleting a todo. \n");
}

void intro(void) {
  printf("\n====== TODO APP ======\n\n");

  commands();

  printf("\n======================\n\n");
}

int main(void)
{
  char op = '\0';
  init_tasks();

  printf("Please enter command: ");
  scanf(" %c", &op);

  intro();

  if (!is_valid_op(&op)) {
    printf("the command you entered is unvalid! \n");
    commands();
    exit(EXIT_FAILURE);
  }

  handle_op(&op);

  return 0;
}
