/* The user of the stack, should call init()
 * before any calls to push(), pop();
 *
 */
#include "stack.h"
void init(stack *s) {
	s->i = 0;
}
void push(stack *s, int num) {
	s->a[s->i++] = num;	
}
/* The caller should check isempty() before calling
 * pop()
 */
int pop(stack *s) {
	//return a[i--];
	int temp;
	temp = s->a[s->i-1];
	s->i--;
	return temp;
}
int isempty(stack *s) {
	return s->i == 0;
}
int isfull(stack *s) {
	return s->i == SIZE;	
}

