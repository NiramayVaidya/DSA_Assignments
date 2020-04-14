#include "queue.h"
#include <string.h>
#include <stdlib.h>
/*
typedef struct data {
	char name[16];
	unsigned int age;
}data;

typedef struct node {
	data d;
	struct node *next;
}node;

typedef struct queue {
	node *head;
	node *tail;
}queue;
*/

void qinit(queue *q) {
	q->head = q->tail = NULL;	
	q->count = 0;
}

void enq(queue *q, data d) {
	node *temp;
//	temp = q->tail;
	temp = (node *)malloc(sizeof(node));
	if(q->head == NULL) {
		strcpy(temp->d.name, d.name);
		temp->d.age = d.age;
		temp->next = temp;
		q->tail = temp;
		q->head = temp;
		q->count++;
	}
	else {
		strcpy(temp->d.name, d.name);
		temp->d.age = d.age;
		temp->next = q->head;
		q->tail->next = temp;
		q->tail = temp;
		q->tail->next = temp;
		q->count++;
	}
}

data deq(queue *q) {
	data d;
	node *temp;
	temp = q->head;
	strcpy(d.name, temp->d.name);
	d.age = temp->d.age;
	if(temp->next == q->head) {
		free(temp);
		q->head = q->tail = NULL;
		q->count--;
	}
	else {
		q->head = temp->next; 
		free(temp);
		q->tail->next = q->head;
		q->count--;
	}
	return d;
}

int qempty(queue q) {
	return q.count == 0;;
}

int qfull(queue q) {
	return q.count == 32;
} 

