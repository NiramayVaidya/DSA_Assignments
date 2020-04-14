#include<stdio.h>

int main() {
	int i, j, k, num_1, num_2, temp, array_1[50], array_2[50];
	scanf("%d%d", &num_1, &num_2);
	for(i = 0; i < 50 ; i++) {
		array_1[i] = num_1 * (i + 1);
		array_2[i] = num_2 * (i + 1);
	}
	for(j = 0; j < 50; j++) {
		for(k = 0; k < 50; k++) {
			if(array_1[j] == array_2[k]) {
				temp = array_1[j];
				break;
			}
		}
		if(temp == array_1[j]) {
			break;
		}
	}
	printf("%d\n", temp);
	return 0;
}
