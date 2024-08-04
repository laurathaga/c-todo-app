#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/common.h"
#include "../headers/db.h"

unsigned int mem_amount = 0;
static Task *tasks_buffer = NULL;

void init_tasks(void)
{
  if (tasks_buffer != NULL)
    return;

  FILE *file = fopen(DB_NAME, "rb");
  FILE *indx_file = fopen(INDEX_FILE_NAME, "rb");

  if (file == NULL) 
  {
    printf("Could not open file %s, please try again\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  if (indx_file == NULL) 
  {
    printf("Could not open file %s, please try again\n", INDEX_FILE_NAME);
    exit(EXIT_FAILURE);
  }

  if (fread(&mem_amount, sizeof(int), 1, indx_file) != 1) {
    printf("Could not read from file %s\n", INDEX_FILE_NAME);
    return;
  }

  tasks_buffer = (Task *) malloc(mem_amount);

  if (tasks_buffer == NULL)
  {
    printf("could not allocate memory for task list\n");
    exit(EXIT_FAILURE);
  }

  if (fread(tasks_buffer, sizeof(Task), mem_amount, file) != mem_amount) 
  {
    printf("Could not read Task \n");

    free(tasks_buffer);
    fclose(file);

    return;
  }

  fclose(file);
  file = NULL;
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

  task->id = ++mem_amount;
  task->title = title;
  task->status = status;

  insert_row(task, mem_amount);
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
