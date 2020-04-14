#include<stdio.h>
#include<math.h>

void print(int curr, int num, int size);

int main() {
	int num, i, size;
	scanf("%d", &num);
	for (i = 0; ; i++) {
		if ((int)pow((double)2, (double)i) > num) {
			size = i;
			break;
		}
	}
	print(0, num, size);
}

void print(int curr, int num, int size) {
	int i, val;
	if (curr == num + 1) {
		return;
	}
	for (i = size - 1; i >= 0; i--) {
		val = curr >> i;
		if (val & 1) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
	print(curr + 1, num, size);
}
