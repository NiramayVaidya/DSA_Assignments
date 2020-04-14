typedef struct node {
	int num;
	struct node *next;
}node;

typedef struct list {
	node *head;
	int count;
}list;

void init list(list *l);
void appendrt(list *l, int num);
void deletrt(list *l);
int length(list l);
