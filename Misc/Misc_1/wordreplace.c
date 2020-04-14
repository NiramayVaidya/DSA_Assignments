#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {
	int fd, i = 0, j, count = 0;
	char orig[32], ch;
	if(argc != 4) {
		printf("usage: ./myprogram <filename> <find> <replace>\n");
		return EINVAL;
	}
	fd = open(argv[1], O_RDONLY | O_WRONLY, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("open failed.");
		return errno;
	}
	while(read(fd, &ch, sizeof(char))) {
		if(ch != ' ') {
			orig[i] = ch;
			count++;
			i++;
		}
		else {
			count++;
			orig[i] = '\0';
			if(!strcmp(argv[2], orig)) {
				if (strlen(argv[2]) > strlen(argv[3])) {
                        	        lseek(fd, -(strlen(orig) + 1), 1);
                                	for(j = 0; j < strlen(argv[3]); j++) {
                                	        ch = *argv[3];
                                	        write(fd, &ch, sizeof(char));
                                	        argv[3]++;
                                	}
					lseek(fd, strlen(argv[2]) - strlen(argv[3]), 1);
					while(read(fd, &ch, sizeof(char))) {
						lseek(fd, -(strlen(argv[2]) - strlen(argv[3] + 1)), 1);
						write(fd, &ch, sizeof(char));
						lseek(fd, strlen(argv[2]) - strlen(argv[3]), 1);
					}
					lseek(fd, count - (strlen(argv[2] - strlen(argv[3]))), 0);
					strcpy(orig, "");
					i = 0;
				}
				else if(strlen(argv[2]) < strlen(argv[3])) {
					lseek(fd, 0, 2);
					while(read(fd, &ch, sizeof(char))) {
						lseek(fd, strlen(argv[3]) - strlen(argv[2]) - 1, 1);
						write(fd, &ch, sizeof(char));
						lseek(fd, -(strlen(argv[3]) - strlen(argv[2]) + 2), 1);
					}
					lseek(fd, count + (strlen(argv[3]) - strlen(argv[2])), 0);
					strcpy(orig, "");
					i = 0;
				}
				else {
					lseek(fd, -(strlen(argv[2] + 1)), 1);
					for(j = 0; j < strlen(argv[2]); j++) {
						ch = *argv[3];
						write(fd, &ch, sizeof(char));
						argv[3]++;
					}
					lseek(fd, 1, 1);
					strcpy(orig, "");
					i = 0;
				}
			}
		}
	}	
	close(fd);
	return 0;
}
