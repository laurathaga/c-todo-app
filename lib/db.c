#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/db.h"
#include "../headers/common.h"

void store_into_file(Task *tasks_buffer, unsigned int *mem_amount)
{
  FILE *file;

  file = fopen(DB_NAME, "wb");

  if (file == NULL) 
  {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  if (fwrite(mem_amount, sizeof(int), 1, file) != 1)
  {
    printf("Could not save to file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  if (fwrite(tasks_buffer, sizeof(Task), *mem_amount, file) != *mem_amount) 
  {
    printf("Could not save to file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  printf("TODO saved successfuly\n");

  fclose(file);
}

void save_index(unsigned long *index)
{
  FILE *file;

  file = fopen(INDEX_FILE_NAME, "wb");

  if (file == NULL)
  {
    printf("Could not open file %s\n", INDEX_FILE_NAME);
    exit(EXIT_FAILURE);
  }

  if (fwrite(index, sizeof(unsigned long), 1, file) != 1) 
  {
    printf("Could not save to file %s\n", INDEX_FILE_NAME);
    exit(EXIT_FAILURE);
  }

  fclose(file);
}
