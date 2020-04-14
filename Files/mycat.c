#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY);	
	char ch;
	if(argc != 2) {
		printf("usage: ./mycat <filename>\n");
		return EINVAL;
	}
	if(fd == -1) {
		perror("mycat: open failed");
		return errno;
	}
	/* file was opened successfully */
	/* fd is the handle on the file */
	while(read(fd, &ch, 1))	
		putchar(ch);
	close(fd);
	return 0;
}
