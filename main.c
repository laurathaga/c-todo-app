#include "./headers/task.h"
#include "./headers/common.h"
#include <stdio.h>
#include <stdlib.h>

char is_valid_op(char *op) {
  printf("Please enter command: ");
  scanf(" %c", op);

  if (*op == 'i' || *op == 'u' || *op == 'd' || *op == 'r' || *op == 'q') {
    return TRUE;
  }

  return(FALSE);
}

void commands(void) {
  printf("In order to interact with the app you have to press: \n\n");
  printf("i -  insert -  for inserting new todo; \n");
  printf("u -  update -  for updating an existing todo; \n");
  printf("r -  read   -  for reading all the todos; \n");
  printf("d -  delete -  for deleting a todo. \n");
  printf("q -  quit   -  for quiting the app. \n");
}

void intro(void) {
  printf("\n========== TODO APP ==========\n\n");
  commands();
  printf("\n===========================\n\n");
}

int main(void)
{
  char op = '\0';
  init_tasks();
  intro();

  while (!is_valid_op(&op)) {
    printf("the command you entered is invalid! \n\n");
    commands();
  }

  handle_op(&op);

  return(0);
}
