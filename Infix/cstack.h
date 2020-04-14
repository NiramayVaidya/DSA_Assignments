#define SIZE 32
typedef struct cstack{
	char a[SIZE];
	int i;
}cstack;

void cinit(cstack *s);
void cpush(cstack *s, char num);
char cpop(cstack *s);
int cisempty(cstack *s);
int cisfull(cstack *s);


