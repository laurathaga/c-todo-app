#include "./headers/task.h"
#include <stdio.h>

int main(void)
{
  char op = '\0';
  init_tasks();

  printf("\n====== TODO APP ======\n\n");

  printf("In order to interact with the app you have to press: \n\n");
  printf("i - for inserting new todo; \n");
  printf("u - for updating an existing todo; \n");
  printf("r - for reading all the todos; \n");
  printf("d - for deleting a todo. \n");

  printf("\n======================\n\n");

  printf("Please enter command: ");
  scanf(" %c", &op);

  handle_op(&op);

  return 0;
}
