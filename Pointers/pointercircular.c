#include<stdio.h>
#include<stdlib.h>

typedef struct data {
        char name;
        struct data *q;
} data;

int main() {
        char ch;
        data *p, *r, *ptr;
        p = (data *)malloc(sizeof(data));
		ptr = p;
        scanf("%c", &(ptr->name));
        scanf("%c", &ch);
        while(ptr->name != '\n') {
                ptr->q = (data *)malloc(sizeof(data));
                r = ptr;
                ptr = ptr->q;
                free(r);
                scanf("%c", &(ptr->name));
                if(ptr->name != '\n') {
                        scanf("%c", &ch);
                }
        }
        ptr->q = p;
        free(ptr);
        return 0;
}

