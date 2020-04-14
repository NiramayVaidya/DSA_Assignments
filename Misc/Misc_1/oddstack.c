#include "oddstack.h"

void init (stack *st) {
	st->i = 0;
}

void push (stack *st, int num) {
	if(st->i < MAX) {
		st->j = 1;
		st->a[st->i] = num;
		st->i += 2;
	}
	if(st->i == MAX || st->i == MAX + 1) {
		if(st->j < MAX) {
		st->a[st->j] = num;
		st->j += 2;
		}		
	}
}

int pop (stack *st) {
	int num;
	if(st->j > 1) {
		num = st->a[st->j];
		st->j -= 2;
	}
	if(st->j == 1) {
		st->j = 0;
	}
	if(st->j < 0) {
		st->j -= 1;
		st->i -= 2;
		num = st->a[st->i];
	}
	return num;	
}

int isempty (stack *st) {
	return st->i == 0;	
}

int isfull (stack *st) {
	return st->j == MAX || st->j == MAX + 1;
}

