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
	int fd, fdw;
	char ch;
	if(argc != 3) {
		printf("usage: ./mycp <filename> <filename>\n");
		return EINVAL;
	}
 	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("mycat: open failed on argv[1]");
		return errno;
	}
 	fdw = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR);
	if(fdw == -1) {
		perror("mycat: open failed on argv[2]");
		return errno;
	}
	
	/* file was opened successfully */
	/* fd is the handle on the file */
	while(read(fd, &ch, 1))	
		write(fdw, &ch, 1);
	close(fd);
	close(fdw);
	return 0;
}
