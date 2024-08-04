#define DB_NAME "./database/bca.db"
#define INDEX_FILE_NAME "./database/indexes.db"

void store_into_file(Task *tasks_buffer, unsigned int *mem_amount);
void save_index(unsigned long *index);
