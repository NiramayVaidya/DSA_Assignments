#define MAX 4

typedef struct stack {
	int a[MAX];
	int i, j;
}stack;

void init (stack *st); 
void push (stack *st, int num); 
int pop (stack *st);
int isempty (stack *st); 
int isfull (stack *st); 

