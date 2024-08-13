#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/common.h"
#include "../headers/db.h"

unsigned int mem_amount = 0;
unsigned long current_index = 1;
static Task *tasks_buffer = NULL;

void init_tasks(void)
{
  if (tasks_buffer)
    return;

  FILE *file = fopen(DB_NAME, "rb");

  if (file == NULL) {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }
}

void create_task(void)
{
  Task task = {
    .title =  (char *) malloc(20),
    .id = current_index++,
    .status = UNDONE
  };

  char *title_ptr = task.title;

  printf("Enter title: ");
  read_line(title_ptr);

  printf("Enter status (1 ~ Done or 0 ~ Undone): ");
  scanf(" %d", &task.status);
}

void handle_op(char *op)
{
  switch (*op)
  {
    case 'i': {
      create_task();
      break;
    }
    case 'd': {
      break;
    };
    case 'u': {
      break;
    };
    case 'r': {
      break;
    };
  }
}
