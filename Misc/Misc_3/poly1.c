#include <stdio.h>
#include "poly.h"

#define MAX 1024

typedef struct data {
        char polyname[MAX];
        poly pol[MAX];
}data;

int main() {
	FILE *fp;
	fp = fopen("./polydata1.txt", "r");
	if(fp == NULL)
		return -1;
	int x, i = 0, j;
	double temp, coeff, power;
	char ch, ch1;
        data d;
	while(fscanf(fp, "%c", &ch) == -1) {
                if(ch == 'p') {
                        fscanf(fp, "%c", &ch);
                        fscanf(fp, "%c", &ch1);
                        if(ch1 == '\n') {
                                for(j = 0; j < i; j++) {
                                        if(ch == d.polyname[j]) {
                                                printPoly(d.pol[j]);
                                                printf("\n");
                                                break;
                                        }
                                }
                                if(j == i)
                                        printf("to be commented- polynomial not found\n");
				else {
                                        while((fscanf(fp, "%c", &ch)) != '\n')
                                                ;
                        }
                }	
                else if(ch == 'e') {
                        fscanf(fp, "%c", &ch);
                        fscanf(fp, "%lf", &temp);
                        for(j = 0; j < i; j++) {
                                if(ch == d.polyname[j]) {
                                        printf("%.2lf", eval(d.pol[j], temp));
                                        printf("\n");
                                        while((fscanf(fp, "%c", &ch) != '\n'))
                                                ;
                                }						
                        }
                        printf("polynomial not found\n");
                        fscanf(fp, "%c", &ch);
                }
                else if(ch == 'r') {
                        ;
                }
                else if(ch == '#') {
                        if(ch > 'a' && ch < 'z') {
                                d.polyname[i] = ch;
                                fscanf(fp, "%c", &ch);
                                if(ch == '=') {
                                }
                                else {
                                        while((fscanf(fp, "%c", &ch)) != '\n')
                                                ;
                                }
                                if(ch < 'a' || ch > 'z') {
                                        fseek(fp, -1, SEEK_CUR);
                                        fscanf(fp, "%lf", &coeff);
                                        fscanf(fp, "%c", &ch);
                                        fscanf(fp, "%lf", &power);
                                        addEntry(&(d.pol[i]), coeff, power);
                                        while(fscanf(fp, "ch", &ch) != '\n') {
                                                fscanf(fp, "%lf", &coeff);
                                                fscanf(fp, "ch", &ch);
                                                fscanf(fp, "%lf", &power);
                                                addEntry(&(d.pol[i]), coeff, power);
                                }
                                i++;
                        }
                        else {
                                        for(j = 0; j < i; j++) {
                                                if(ch == polyname[j]) {
                                                        fscanf(fp, "%c", &ch);
                                                        if(ch == '+') {
                                                                fscanf(fp, "%c", &ch);
                                                                for(k = 0; k < i; k++) {
                                                                        if(ch == polyname[k]) {
                                                                                polyAdd(d.pol[j], d.pol[k]);
                                                                                printf("\n");
                                                                                fscanf(fp, "%c", &ch);
                                                                                break;
                                                                        }
                                                                }
                                                                printf("polynomial not found\n");
                                                        }
                                                        else if(ch == '*') {
                                                                fscanf(fp, "%c", &ch);
                                                                for(k = 0; k < i; k++) {
                                                                        if(ch == polyname[k]) {
                                                                                multPoly(d.pol[j], d.pol[k]);
                                                                                printf("\n");
                                                                                fscanf(fp, "%c", &ch);
                                                                                break;
                                                                        }
                                                                }
                                                                printf("polynomial not found\n");
                                                        }
                                                        else {
                                                                printf("invalid operation\n");
                                                                break;
                                                        }
                                                }
                                        }
                                }						
                        }
                        else {
                                printf("to be commented- invalid operation\n");
                                while((fscanf(fp, "%c", &ch) != '\n'))
                                        ;
                        }
        }
	return 0;
}
