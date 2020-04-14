#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

int readline(FILE *fp, char *line, int n);

int main() {
	tree a, b;
	tinit(&a);
	data d;
	char line[64], *token1, *token2;
	int z;
	node *x, *y;
	FILE *fp;
	fp = fopen("./data1.txt", "r");
	if(fp == NULL)
		return -1;
	printf("initialized tree a\n");
	while(1) {
		z = readline(fp, line, 64);
		if(z == 0)
			break;
		token1 = strtok(line, "\t");
		token2 = strtok(NULL, "\t\n");
		d.id = atoi(token1);
		strcpy(d.name, token2);
		insert(&a, d);
	}
	printf("inserted data(id, name) into tree a\n");
	b = copy(a);
	printf("copied tree a into tree b\n");
	printf("inorder traversal of tree a:\n");
	inorder(a);
	printf("inorder traversal of tree b:\n");
	inorder(b);
	x = min(a);
	y = min(b);
	printf("id and name in data of min of tree a is %d and %s\n", x->d.id, x->d.name);
	printf("id and name in data of min of tree b is %d and %s\n", y->d.id, y->d.name);
	fclose(fp);
	return 0;
}

int readline(FILE *fp, char *line, int n) {
	int ch;
	int i = 0;
	while((ch = fgetc(fp)) != '\n' && ch != -1)
		line[i++] = ch;
	line[i] = '\0';
	return i;
}
