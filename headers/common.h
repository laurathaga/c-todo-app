#define TRUE 1
#define FALSE 0
#define TO_INT(arg) (arg - '0')

void list_commands(void);
void read_line(char *des);
char *to_char(unsigned long id);
void str_cpy(char *des, const char *str, int size);
