#include "../headers/task.h"
#define BUFFER_SIZE 10


static size_t buffer_size = 0;
static Task **tasks = NULL;
static Task **tasks_ptr = NULL;

void init_tasks(void)
{
  int len = BUFFER_SIZE * sizeof(Task *);

  tasks = (Task **) malloc(len);

  if (tasks == NULL)
  {
    printf("could not allocate memory for task list\n");
    exit(EXIT_FAILURE);
  }

  tasks_ptr = tasks;
}
