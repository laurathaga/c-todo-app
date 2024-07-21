#include "./headers/task.h"
#include <stdio.h>

int main(void)
{
  char op = '\0';
  init_tasks();
  
  printf("====== TODO APP ======\n");

  printf("Please enter operation: ");
  scanf(" %c", &op);

  handle_op(&op);

  return 0;
}
