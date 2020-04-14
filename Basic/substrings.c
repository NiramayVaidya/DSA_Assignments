#include<stdio.h>
#include<string.h>

int main() {
	char strings[20][20], substring[20];
	char *check;
	int i, j;
	for(i = 0; i < 20; i++) {
		fgets(strings[i], 20, stdin);
		if(strings[i][0] == '\n') {
			break;
		}
	}
	scanf("%s", substring);
	for(j = 0; j < 20; j++) {
		check = strstr(strings[j], substring);
		if(check != '\0') {
			check = &strings[j][0];
			printf("%s", check);
		}
		else {
			continue;
		}
	}
	return 0;

		
}
