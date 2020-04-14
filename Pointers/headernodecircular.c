#include<stdio.h>
#include<stdlib.h>

typedef struct data {
	char name;
    struct data *p;
} data;

int main() {
	char ch;
	data a, *q, *r;
	a.p = (data *)malloc(sizeof(data));
	q = a.p;
	scanf("%c", &(q->name));
	scanf("%c", &ch);
	while(q->name != '\n') {
		q->p = (data *)malloc(sizeof(data));
		r = q;
		q = q->p;
		free(r);	
		scanf("%c", &(q->name));
		if(q->name != '\n') {
			scanf("%c", &ch);
		}
	}
	q->p = &a;
	free(q);
	return 0;
}
	
