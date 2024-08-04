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

  fread(&current_index, sizeof(int), 1, indx_file);
  fread(&mem_amount, sizeof(int), 1, file);

  tasks_buffer = (Task *) calloc(0x0, mem_amount * sizeof(Task) + 1);

  if (tasks_buffer == NULL)
  {
    printf("could not allocate memory for task list\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < mem_amount; i++)
  {
    tasks_buffer[i].title = (char *) malloc(20);
  }

  if (fread(tasks_buffer, sizeof(Task), mem_amount, file) != mem_amount) 
  {
    printf("Could not read Task \n");

    free(tasks_buffer);
    fclose(file);

    return;
  }

  for (int i = 0; i < mem_amount; i++) 
  {
    printf("id is %lu\n", tasks_buffer[i].id);
    printf("title is %s\n", tasks_buffer[i].title);
    printf("status is %s\n", tasks_buffer[i].status == 0 ? "Undone" : "Done");
  }

  fclose(file);
  fclose(indx_file);
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

  Task task;

  task.id = current_index++;
  task.title = title;
  task.status = status;

  tasks_buffer[++mem_amount] = task;

  for (int i = 0; i < mem_amount; i++)
  {
    printf("title is %s\n", *(tasks_buffer + i)->title);
    printf("i is %d\n", i);
  }

  save_index(&current_index);
  store_into_file(tasks_buffer, &mem_amount);
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
