#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void tinit(tree *t) {
	*t = NULL;
}

void insert(tree *t, data d) {
	node *p = *t, *q, *tmp;
	int count = 0;
	while(p) {
		q = p;
		if(d.id > p->d.id) {
			p = p->right;
			count = 1;
		}
		else if(d.id < p->d.id) {
			p = p->left;
			count = -1;
		}
		else
			return;
	}
	tmp = (node *)malloc(sizeof(node));
	tmp->d = d;
	tmp->left = tmp->right = NULL;
	if(count == 0) {
		*t = tmp;
		return;
	}
	if(count == 1)
		q->right = tmp;
	else
		q->left = tmp;
}

tree copy(tree t) {
	node *tmp;
	if(t == NULL)
		return NULL;
	tmp = (node *)malloc(sizeof(node));
	tmp->d = t->d;
	tmp->left = copy(t->left);
	tmp->right = copy(t->right);
	return tmp;
}

void inorder(tree t) {
	if(t == NULL)
		return;
	inorder(t->left);
	printf("%d\t%s\n", t->d.id, t->d.name);
	inorder(t->right);
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))

tree min(tree t) {
	node *a, *b;
	if(t == NULL)
		return NULL;
	else {
		a = min(t->left);
		b = min(t->right);
		if(a && b) {
			if(MIN(a->d.id, b->d.id) == a->d.id) {
				if(MIN(a->d.id, t->d.id) == a->d.id)
					return a;
				else
					return t;
			}			
			else if(MIN(a->d.id, b->d.id) == b->d.id) {
				if(MIN(b->d.id, t->d.id) == b->d.id)
					return b;
				else
					return t;
			}
		}
		else if(a) {
			if(MIN(a->d.id, t->d.id) == a->d.id)
				return a;
			else
				return t;
		}
		else if(b) {
			if(MIN(b->d.id, t->d.id) == b->d.id)
				return b;
			else
				return t;
		}
		else
			return t;
	}
}
