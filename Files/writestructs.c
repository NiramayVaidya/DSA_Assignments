#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

#define PERMS 777

typedef struct info {
        int id;
        char name[16];
        double score;
} info;

int main(int argc, char *argv[]) {
        int n, fd, i;
        info *temp;
        info *temp_1;
        scanf("%d", &n);
        temp = (info *)malloc(sizeof(info) * n);
        temp_1 = temp;
        fd = open(argv[1], O_WRONLY | O_CREAT, PERMS);
	if(argc != 2) {
		printf("usage: ./writestructs <filename>\n");
		return EINVAL;
	}
	if(fd == -1) {
		perror("open failed");
		return errno;
	}
        write(fd, &n, sizeof(int));
        for(i = 0; i < n; i++) {
                scanf("%d", &(temp->id));
//              fgets(temp->name, 16, stdin);
                scanf("%s", temp->name);
                scanf("%lf", &(temp->score));
                write(fd, &(temp->id), sizeof(int));
                write(fd, temp->name, 16);
                write(fd, &(temp->score), sizeof(double));
                temp++;
        }
        close(fd);
        free(temp_1);
        return 0;
}
