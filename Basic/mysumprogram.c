#include<stdio.h>

int main() {
	int i, input_num;
	int sum = 0;
	for(i = 0; ; i++) {
		scanf("%d", &input_num);
		printf("\n");
		if(input_num != -10000000) {
			sum = sum + input_num;
		}
		else {
			break;
		}
	}
printf("%d\n", sum);
return 0;
}
