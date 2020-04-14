#include<stdio.h>
#include<string.h>

int stringreplace(char* text, char* orig, char* new);

int main() {
	char text[128], orig[128], new[128];;
        int count;
        while(scanf("%s%s%s", text, orig, new) != -1) {
                count = stringreplace(text, orig, new);
                printf("%d %s\n", count, text);
        }
        return 0;
}

int stringreplace(char* text, char* orig, char* new) {
        int l_1 = strlen(text);
        int l_2 = strlen(orig);
        int l_3 = strlen(new);
        int i, count = 0;
        char *ptr;
        char *ptr_1;
        if(l_2 == l_3) {
                ptr = text;
                while((ptr = strstr(ptr, orig))) {
                        count++;
                        for(i = 0; i < l_3; i++) {
                                *(ptr + i) = *(new + i);
                        }
                        ptr = ptr + l_3;
                }
                return count;
        }
        else if(l_2 > l_3) {
                ptr = text;
                while((ptr = strstr(ptr, orig))) {
                        count++;
                        for(i = 0; i < l_3; i++) {
                                *(ptr + i) = *(new + i);
                        }
                        ptr_1 = ptr;
                        ptr = ptr + l_2;
                        while(*ptr) {
                                *(ptr - (l_2 - l_3)) = *ptr;
                                ptr = ptr + 1;
                        }
                        *(ptr - (l_2 - l_3)) = *ptr;
                        ptr = ptr_1 + l_3;
                }
                return count;
        }
        else if(l_2 < l_3) {
                ptr = text;
                while((ptr = strstr(ptr, orig))) {
                        count++;
                        ptr_1 = ptr;
                        ptr = text + l_1;
                        while((ptr_1 + l_2 - 1) != ptr) {
                        *(ptr + (l_3 - l_2)) = *ptr;
                        ptr = ptr - 1;
                        }
                        ptr = ptr_1;
                        for(i = 0; i < l_3; i++) {
                                *(ptr + i) = *(new + i);
                        }
                        ptr = ptr_1 + l_3;
                        l_1 = strlen(text);
                }
                return count;
        }
}

