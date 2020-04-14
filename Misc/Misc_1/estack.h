#define MAX 64

typedef struct stack {
	int a[MAX];
	int i;
}stack;

void init(stack *s);
void push(stack *s, int num);
int pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);
