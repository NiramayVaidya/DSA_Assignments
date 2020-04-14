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
	//argv[1] --> string
	//argv[2] --> filename;
	FILE *fp;
	char line[1024], *token, copyline[1024];
	fp = fopen(argv[2], "r");
	while(fgets(line, 1024, fp)){
		strcpy(copyline, line);
		token = strtok(line, ",");
		token = strtok(NULL, ",");
		token = strtok(NULL, ",");
		if(strcmp(token, argv[1]) == 0) {
			printf("%s", copyline);
		}
	}
	fclose(fp);
	return 0;
}
