#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Invalid number of input parameters\n");
		exit(0);
	}
	FILE *fp;
	int count = 0;
	int i;
	char c;
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File does not exist\n");
		exit(0);
	}
	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n') {
			count += 1;
		}
	}
	fclose(fp);
	for (i = 1; i <= count; i++) {
		printf("%d\n", i);
	}
	return 0;
}
