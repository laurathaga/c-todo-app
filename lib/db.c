#include <stdio.h>
#include <stdlib.h>

#include "../headers/task.h"
#include "../headers/db.h"
#include "../headers/common.h"

void insert_row(Task *tasks_buffer, unsigned int mem_amount)
{
  FILE *data_file, *index_file;

  data_file = fopen(DB_NAME, "wb");
  index_file = fopen(INDEX_FILE_NAME, "wb");

  if (data_file == NULL) 
  {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  if (index_file == NULL) 
  {
    printf("Could not open file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  if (fwrite(&mem_amount, sizeof(unsigned int), 1, index_file) != 1) {
    printf("Could not save to file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  if (fwrite(tasks_buffer, sizeof(Task), mem_amount, data_file) != mem_amount) 
  {
    printf("Could not save to file %s\n", DB_NAME);
    exit(EXIT_FAILURE);
  }

  printf("TODO saved successfuly\n");

  fclose(data_file);
  fclose(index_file);
}
