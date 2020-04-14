#include "estack.h"

void init (stack *s) {	
	s->i = 0;
}

void push (stack *s, int num) {
	if(isfull(*s)) {
	s->a[s->i++] = num;
}	
