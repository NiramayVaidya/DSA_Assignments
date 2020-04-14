typedef struct data {
	int id;
	char name[16];
}data;
typedef struct node {
	data d;
	struct node *left, *right;
}node;
typedef node *tree;

void tinit(tree *t);
void insert(tree *t, data d);
tree copy(tree t);
void inorder(tree t);
tree min(tree t);

