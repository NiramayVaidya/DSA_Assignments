/* The user of the cstack, should call init()
 * before any calls to push(), pop();
 *
 */
#include "cstack.h"
void cinit(cstack *s) {
	s->i = 0;
}
void cpush(cstack *s, char num) {
	s->a[s->i++] = num;	
}
/* The caller should check isempty() before calling
 * pop()
 */
char cpop(cstack *s) {
	//return a[i--];
	char temp;
	temp = s->a[s->i-1];
	s->i--;
	return temp;
}
int cisempty(cstack *s) {
	return s->i == 0;
}
int cisfull(cstack *s) {
	return s->i == SIZE;	
}

