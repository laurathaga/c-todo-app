#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/db.h"
#include "../headers/common.h"

void insert_row(Task *task)
{
  FILE *file;

  file = fopen(DB_NAME, "a");

  if (file == NULL) 
  {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  fprintf(file, to_char(task->id));
  fprintf(file, ";");
  fprintf(file, task->title);
  fprintf(file, ";");
  fprintf(file, to_char(task->status));
  fprintf(file, ";");
  fprintf(file, "\n");

  fclose(file);
  file = NULL;
}
