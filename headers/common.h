#define TO_INT(arg) (arg - '0')

typedef enum _bool {
  TRUE = 1,
  FALSE = 0,
} Bool;

void read_line(char *des);
char *to_char(unsigned long id);
void str_cpy(char *des, const char *str, int size);
