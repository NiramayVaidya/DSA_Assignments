#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define PERMS 777

int main(int argc, char* argv[]) {
	int fd, max_lim, i;
	double temp;
	if(argc != 2) {
		printf("Usage: ./fileforremdup <filename>\n");
		return EINVAL;
	}
	fd = open(argv[1], O_WRONLY | O_CREAT, PERMS);
	if(fd == -1) {
		perror("open failed.");
		return errno;
	}
	scanf("%d", &max_lim);
	for(i = 0; i < max_lim; i++) {
		scanf("%lf", &temp);
		write(fd, &temp, sizeof(double));
	}
	printf("\n");
	close(fd);
}
	
