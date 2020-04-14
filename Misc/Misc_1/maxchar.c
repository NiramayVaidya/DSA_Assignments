#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

typedef struct str {
	char ch;
	int num;
}str;

int main(int argc, char *argv[]) {
	int fd, i, j;
	char ch;
	str st[256], temp;
	if(argc != 2) {
		printf("uage: ./myprogram <filename>");
		return EINVAL;
	}
	fd = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("open failed.");
		return errno;
	}
	for(i = 0; i < 256; i++) {
		st[i].num = 0;
	}
	while(read(fd, &ch, sizeof(char))) {
		(st[ch].num)++;
		st[ch].ch = ch;
	}
	for(i = 0; i < 256; i++) {
		for(j = i + 1; j < 256; j++) {
			if(st[j].num < st[i].num) {
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
		}
	}
	printf("%c\n", st[255].ch);
	close(fd);
	return 0;
}	 
	 
