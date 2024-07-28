#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/db.h"
#include "../headers/common.h"

void insert_row(Task *task)
{
  FILE *file;

  file = fopen(DB_NAME, "ab");

  if (file == NULL) 
  {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  size_t write_result = fwrite(
    task, // pointer to value
    sizeof(Task), // size of value
    1, // amount of items
    file // pointer to file
  );

  if (write_result != 1) 
  {
    printf("Could not save to file \n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  printf("TODO saved successfuly\n");

  fclose(file);
  file = NULL;
}
