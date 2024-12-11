#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/common.h"
#include "../headers/db.h"

unsigned int mem_amount;
unsigned long current_index = 1;
Task *tasks_buffer = NULL;

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

  if (indx_file == NULL) {
    printf("Could not open file %s\n", INDEX_FILE_NAME);
    exit(EXIT_FAILURE);
  }

  fread(&mem_amount, sizeof(int), 1, file);

  tasks_buffer = (Task *) malloc((mem_amount + 1) * sizeof(Task));

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

  printf("Enter title (max: 50 characters): ");
  read_line(task->title);

  printf("Enter status (1 ~ Done or 0 ~ Undone): ");
  scanf(" %d", &task->status);

  tasks_buffer[mem_amount++] = *task;

  store_into_file(tasks_buffer, &mem_amount);
  save_index(&current_index);

  free(task);

  task = NULL;
}

void update_task(void)
{
  int option;

  char *title = (char *) malloc(50),
       *new_title = (char *) malloc(50);

  printf("Please enter tasks title to update: ");
  read_line(title);

  Task *task = NULL;
  
  for (int i = 0; i < mem_amount; i++) 
  {
    if (strcmp(title, tasks_buffer[i].title) == 0) 
    {
       task = &tasks_buffer[i];
       break;
    }
  }

  if (!task)
  {
    printf("Could not find task !\n");
    exit(EXIT_FAILURE);
  }

  insert_option: 
    printf("Please press 1 to update name or 2 to update the status: ");
    scanf(" %d", &option);

  if (option == 1) {
    goto update_title;
  }
  else if (option == 2) {
    goto update_status;
  }
  else {
    printf("Invalid option\n");
    goto insert_option;
  }
  
  update_title:
    printf("Enter tasks new title: ");
    read_line(new_title);

    str_cpy(task->title, new_title, 50);
    goto end;

  update_status:
    printf("Enter status of task (1 - done; 0 - undone): ");
    scanf(" %d", &task->status);
    goto end;

  end: 
    store_into_file(tasks_buffer, &mem_amount);

    free(title);
    free(new_title);
}

void delete_task(void)
{
  char *title;
  int i;

  title = (char *) malloc(50);

  printf("Please enter title of the task to be deleted: ");
  read_line(title);

  Task *task = NULL;

  for (i = 0; i < mem_amount; i++) 
  {
    if (strcmp(title, tasks_buffer[i].title) == 0) 
    {
       task = &tasks_buffer[i];
       break;
    }
  }

  if (!task)
  {
    printf("Could not find task !\n");
    exit(EXIT_FAILURE);
  }

  Task *new_tasks = (Task *) malloc(--mem_amount * sizeof(Task));

  i = 0;

  while (i < mem_amount)
  {
    if (tasks_buffer[i].id != task->id)
      new_tasks[i] = tasks_buffer[i];
    
    i++;
  }

  store_into_file(new_tasks, &mem_amount);
  free(new_tasks);
  free(title);
}

void list_tasks(void)
{
  for (int i = 0; i < mem_amount; i++) {
    printf("title: %s | status: %s\n", tasks_buffer[i].title, tasks_buffer[i].status ? "Done" : "Undone");
  }
}

void handle_op(char *op)
{
  if (!tasks_buffer)
  {
    printf("You must call init_tasks function first! \n");
    exit(EXIT_FAILURE);
  }

  switch (*op)
  {
    case 'h': {
      list_commands();  
      break;
    }
    case 'i': {
      create_task();
      break;
    }
    case 'd': {
      if (!mem_amount)
      {
        printf("There's nothing to delete\n");
        return;
      }

      delete_task();

      break;
    };
    case 'u': {
      if (!mem_amount)
      {
        printf("There's nothing to update\n");
        return;
      }

      update_task();
      break;
    };
    case 'r': {
      if (!mem_amount)
      {
        printf("Tasks list is empty. Add some tasks! \n");
        return;
      }

      list_tasks();
      break;
    };
  }
  
  free(tasks_buffer);
}
