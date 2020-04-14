#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define TEMPS 777

int main(int argc, char *argv[]) {
	int fd, value, value_1, i;
	char ch, name[16];
	fd = open(argv[1], O_RDONLY, TEMPS);
	if (fd == -1) {
		perror("open failed.");
		return errno;
	}
	if(argc != 2) {
		printf("usage: ./readdata <filename>\n");
		return EINVAL;
	}
	read(fd, &value, sizeof(int));
	for(i = 0; i < value; i++) {
		read(fd, &value_1, sizeof(int));
		printf("%d\n", value_1);
	}
	read(fd, &value, sizeof(int));
	for(i = 0; i < value; i++) {
		read(fd, &value_1, sizeof(int));
		printf("%d ", value_1);
		read(fd, name, 16);
		printf("%s\n", name);
	}
	read(fd, &value, sizeof(int));
	for(i = 0; i < value; i++) {
		read(fd, &ch, sizeof(char));
		while(ch != '\0') {
			printf("%c", ch);
			read(fd, &ch, sizeof(char));
		}
		printf("\n");
	}
	close(fd);
}
