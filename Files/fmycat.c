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
	char ch[3];
	int x, i;
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(argc != 2) {
		printf("usage: ./mycat <filename>\n");
		return EINVAL;
	}
	while(x= fread(ch, 1, 3, fp)) {
		for(i = 0; i < x; i++)
			putchar(ch[i]);
	}
	fclose(fp);
	return 0;
}
