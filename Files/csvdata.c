#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	char line[1024], *token, copyline[1024];
	fp = fopen(argv[2], "r");
	if(fp == NULL) {
		perror("fopen failed");
		return errno;
	}
	while(fgets(line, 1024, fp)) {
		strcpy(copyline, line);
		token = strtok(line, ",");
		token = strtok(NULL, ",");
		token = strtok(NULL, ",");
		if(strcmp(token, argv[1]) == 0)
			printf("%s", copyline);
	}	
	return 0;
}
