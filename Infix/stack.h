#define SIZE 32
typedef struct stack{
	int a[SIZE];
	int i;
}stack;

void init(stack *s);
void push(stack *s, int num);
int pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);


