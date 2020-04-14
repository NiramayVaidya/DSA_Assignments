#include<stdio.h>
#include<string.h>

int main() {
	char name_1[16];
	int i, j, temp;
	struct student
	{
	char name[16];
	int age;
	double marks;
	};
	struct student records[10];
	for(i = 0; ; i++) {
		scanf("%s %d %lf", records[i].name, &records[i].age, &records[i].marks);
		if (records[i].age == -1) {
			break;
		}
	}
	scanf("%s", name_1);
	for(j = 0; ; j++) {
		temp = strcmp(name_1, records[j].name);
		if(temp == 0) {
			printf("%s %d %.0lf\n", records[j].name, records[j].age, records[j].marks);
			break;
		}
	}
}

