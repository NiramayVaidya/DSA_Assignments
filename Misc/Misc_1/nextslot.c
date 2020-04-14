#include<stdio.h>
#include "oddstack.h"

int main() {
	int n, number = 0;
	stack sta;
	init(&sta);
	scanf("%d", &number);
	push(&sta, number);
	for(n = 0; number != -1; n++) {
		scanf("%d", &number);
		if(!isfull(&sta)) {
			push(&sta, number);
		}
	}
	for(n = 0; !isempty(&sta); n++) {
		printf("%d\t", pop(&sta));
	}
}

