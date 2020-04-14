typedef struct node {
	char ch;
	struct node *p;
	struct node *q;
}node;

typedef struct Integer {
	int count;
	node *head;
	node *tail;
}Integer;

void initInteger(Integer *a);
void addDigit(Integer *a, char ch);
Integer createIntegerFromString(char *Str);
Integer addIntegers(Integer a, Integer b);
Integer subtractIntegers(Integer a, Integer b);
void printInteger(Integer a);
void destroyInteger(Integer *a);
