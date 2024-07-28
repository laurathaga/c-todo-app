#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/common.h"
#include "../headers/db.h"

#define BUFFER_SIZE 10

size_t id_index = 1;
size_t buffer_size = 0;
size_t length = 0;
static Task **tasks_buffer = NULL;
static Task **tasks_ptr = NULL;

void init_tasks(void)
{
  if (tasks_buffer != NULL)
    return;

  buffer_size = BUFFER_SIZE * sizeof(Task *);

  tasks_buffer = (Task **) calloc(0, buffer_size);

  if (tasks_buffer == NULL)
  {
    printf("could not allocate memory for task list\n");
    exit(EXIT_FAILURE);
  }

  tasks_ptr = tasks_buffer;

  FILE *file = fopen(DB_NAME, "rb");

  if (file == NULL) 
  {
    printf("Could not open file %s, please try again\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  while (!feof(file))
  {
    fread(*tasks_ptr, sizeof(Task), 1, file);

    printf("title of task is %s\n", (*tasks_ptr)->title);

    *tasks_ptr++;
  }

  printf("read_result is %d\n", read_result);
}

void create_task(void)
{
  char *title = (char *) malloc(20),
       *title_ptr = title;  

  Status status;

  printf("Please enter task title: ");
  read_line(title_ptr);

  printf("Please enter status (1 - done | 0 - undone): ");
  scanf(" %d", &status);

  Task *task = (Task *) malloc(sizeof(Task));

  if (task == NULL)
  {
    printf("Could not allocate mem for task\n");
    exit(EXIT_FAILURE);
  }

  task->id = id_index++;
  task->title = title;
  task->status = status;

  *tasks_ptr++ = task;

  insert_row(task);
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
