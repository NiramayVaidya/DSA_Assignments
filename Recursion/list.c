/*
typedef struct node {
	int num;
	struct node *next;
}node;

typedef node *list;
*/

void init(list *l) {
	// *l = NULL; this is valid in case of the above definition
	l->head = NULL;
}

void append(node *ptr, int num) {
	node *tmp = ptr;
	if(tmp == NULL) {
		tmp = (node *)malloc(sizeof(node));
		l->head = tmp;
		tmp->num = num;
		tmp->next = NULL;
		l->count++;
	}
	else if(tmp->next != NULL) {
		appendrt(tmp->next, num);
	}
	else {
        tmp->next = (node *)malloc(sizeof(node));
        tmp = tmp->next;
		tmp->num = num;
        tmp->next = NULL;
	}
}

void appendrt(list *l, int num) {
	append(l->head, num);
}

void deletrt(list *l) {
	
}

int len(node *ptr, int count) {
	if (ptr == NULL) {
		return count;
	}
	else {
		return len(ptr->next, count + 1);
	}
}

int length(list l) {
	return len(l.head, 0);
}
