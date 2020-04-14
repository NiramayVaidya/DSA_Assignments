#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define PERMS 777
typedef struct info {
	int id;
	char name[16];
	double score;
} info;

int main(int argc, char *argv[]) {
	int n, fd, i;
	fd = open(argv[1], O_RDONLY, PERMS);
	if(argc != 3) {
		printf("usage: ./readstructs <filename> <double_value>\n");
		return EINVAL;
	}
	if(fd == -1) {
		perror("open failed");
		return errno;
	}
	read(fd, &n, sizeof(int));
	info *temp;
	info *temp_1;
	temp = (info *)malloc(sizeof(info) * n);
	temp_1 = temp;
	for(i = 0; i < n; i++) {
		read(fd, &(temp->id), sizeof(int));
		read(fd, temp->name, 16);
		read(fd, &(temp->score), sizeof(double));
		if(atof(argv[2]) == temp->score) {
			printf("%.2lf\n", temp->score);
		}
		temp++;
	}
	close(fd);
	free(temp_1);
	return 0;
}
