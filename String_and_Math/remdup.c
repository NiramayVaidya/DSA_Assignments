#include<stdio.h>
#include<string.h> 
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define PERMS 777

int removeduplicate(double a[], int n);

int main(int argc, char* argv[]) {
	int fd, i, value;	
	double temp;
	double arr[1024];
	if(argc != 2) {
		printf("usage: ./remdup <filename>\n");
		return EINVAL;
	}
	fd = open(argv[1], O_RDONLY, PERMS);	
	if(fd == -1) {
		perror("open failed");
		return errno;
	}
	i = 0;
	while(read(fd, &temp, sizeof(double))) {
		arr[i] = temp;
		i++;
	}
	value = removeduplicate(arr, i - 1);
	close(fd);
	printf("%d\n", value);
	return 0;
}		

int removeduplicate(double a[], int n) {
	int i, j, k;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(a[i] == a[j]) {
				for(k = j; k < n; k++) {
					a[k] = a[k + 1];
				}
				n = n - 1;
			}
		}
	}
	return n;
}

