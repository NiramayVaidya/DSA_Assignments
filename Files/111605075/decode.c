#include<stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
        int fd = open(argv[1], O_RDONLY);
        char name[40];
//	int count;
	long int mis;
        if(argc != 2) {
                printf("usage: ./mycat <filename>\n");
                return EINVAL;
        }
        if(fd == -1) {
                perror("mycat: open failed");
                return errno;
        }
//	count = 0;
/*        while(read(fd, &ch, 1)) {
		count++;
                printf("%d\t%c\t%d\n", ch, ch, count);
	}*/
	for(int i = 1; i <= 6; i++) {
		read(fd, &mis, sizeof(long int));
		read(fd, &name, 40);
		printf("%ld%s\n", mis, name);
	}
        close(fd);
        return 0;
}
