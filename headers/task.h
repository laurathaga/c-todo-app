typedef enum _status {
  UNDONE,
  DONE,
} Status;

struct _task {
  unsigned long id;
  char title[50];
  Status status;
};

typedef struct _task Task;

void init_tasks(void);

void create_task(void);

void delete_task(void);

Task *find_task(char *title);

void handle_op(char *op);
