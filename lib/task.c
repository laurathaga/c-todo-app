#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/common.h"
#include "../headers/db.h"

unsigned int mem_amount;
unsigned long current_index = 1;
static Task *tasks_buffer = NULL;

void init_tasks(void)
{
  if (tasks_buffer)
    return;

  FILE *file = fopen(DB_NAME, "rb");
  FILE *indx_file = fopen(INDEX_FILE_NAME, "rb");

  if (file == NULL) {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  fread(&mem_amount, sizeof(int), 1, file);

  tasks_buffer = (Task *) malloc(
    mem_amount == 0 ? sizeof(Task) : mem_amount * sizeof(Task) + 1
  );

  if (tasks_buffer == NULL) {
    printf("Could not initialize tasks\n");
    exit(EXIT_FAILURE);
  }

  if (fread(tasks_buffer, sizeof(Task), mem_amount, file) != mem_amount) {
    printf("Something went wrong when reading tasks\n");
    exit(EXIT_FAILURE);
  }

  fread(&current_index, sizeof(int), 1, indx_file);
}

void create_task(void)
{
  Task *task = (Task *) malloc(sizeof(Task));

  task->id = current_index++;

  char *title_ptr = task->title;

  printf("Enter title (max: 50 characters): ");
  read_line(title_ptr);

  printf("Enter status (1 ~ Done or 0 ~ Undone): ");
  scanf(" %d", &task->status);

  tasks_buffer[mem_amount++] = *task;

  store_into_file(tasks_buffer, &mem_amount);
  save_index(&current_index);

  free(task);
  free(tasks_buffer);

  tasks_buffer = NULL;
  task = NULL;
}

void delete_task(void)
{
  char title[50];
  int i;

  printf("Please enter tasks title: ");
  read_line(title);

  Task *task;

  for (i = 0; i < mem_amount; i++) 
  {
    if (strcmp(title, tasks_buffer[i].title) == 0) 
    {
       printf("title of task is %s\n", tasks_buffer[i].title);
       break;
    }
    else 
    {
      printf("task not found! Please check for a typo \n");
      return;
    }
  }

  free(tasks_buffer);
}

void list_tasks(void)
{
  if (tasks_buffer == NULL)
  {
    printf("You should call init before list_tasks function\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < mem_amount; i++) {
    printf("title: %s\n", tasks_buffer[i].title);
  }

  free(tasks_buffer);
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
      delete_task();
      break;
    };
    case 'u': {
      break;
    };
    case 'r': {
      list_tasks();
      break;
    };
  }
}
