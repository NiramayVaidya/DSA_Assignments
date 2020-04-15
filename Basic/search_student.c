#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[32];
	char surname[32];
	unsigned int age;
	char id[16];
	unsigned int score;
	float percentage;
} student;

void check_choice_correctness(int choice) {
	if (choice != 1 && choice != 2 && choice != 0) {
		printf("ERROR - Invalid input choice\n");
		exit(0);
	}
}

void print_student_info(student array[], int pos) {
	printf("Name - %s\n", array[pos].name);
	printf("Surname - %s\n", array[pos].surname);
	printf("Age - %d\n", array[pos].age);
	printf("Id - %s\n", array[pos].id);
	printf("Score - %d\n", array[pos].score);
	printf("Percentage - %f\n", array[pos].percentage);
}

int main() {
	int num;
	student roster[128];
	int position = 0;
	printf("Enter student information - 1\n");
	printf("Search student information - 2\n");
	printf("Exit program - 0\n");
	int choice;
	printf("Input choice - \n");
	scanf("%d", &choice);
	check_choice_correctness(choice);
	while (choice) {
		if (choice == 1) {
			if (position < 128) {
				printf("NOTE - Enter name, surname less than equal to 32 characters\n");
				printf("NOTE - Enter id less than equal to 16 alphanumeric characters\n");
				printf("NOTE - Enter age, score as non-negative integers\n");
				printf("NOTE - Enter percentage as a real number in decimal format\n");
				printf("Enter name - \n");
				scanf("%s", roster[position].name);
				printf("Enter surname - \n");
				scanf("%s", roster[position].surname);
				printf("Enter age - \n");
				scanf("%d", &roster[position].age);
				printf("Enter id - \n");
				scanf("%s", roster[position].id);
				printf("Enter score - \n");
				scanf("%d", &roster[position].score);
				printf("Enter percentage - \n");
				scanf("%f", &roster[position].percentage);
				position++;
			}
			else {
				printf("WARN - Student roster full\n");
				printf("WARN - No more vacancy in class\n");
			}
		}
		else {
			int search_choice;
			char string[32];
			unsigned int number;
			int i;
			printf("Search by - \n");
			printf("Name - 1\n");
			printf("Surname - 2\n");
			printf("Age - 3\n");
			printf("Id - 4\n");
			printf("Enter select choice - \n");
			scanf("%d", &search_choice);
			if (search_choice == 1) {
				printf("Enter search name - \n");
				scanf("%s", string);
				for (i = 0; i < position; i++) {
					if (!strcmp(string, roster[i].name)) {
						print_student_info(roster, i);
					}
				}
			}
			else if (search_choice == 2) {
				printf("Enter search surname - \n");
				scanf("%s", string);
				for (i = 0; i < position; i++) {
					if (!strcmp(string, roster[i].surname)) {
						print_student_info(roster, i);
					}
				}
			}
			else if (search_choice == 4) {
				printf("Enter search id - \n");
				scanf("%s", string);
				for (i = 0; i < position; i++) {
					if (!strcmp(string, roster[i].id)) {
						print_student_info(roster, i);
					}
				}
			}
			else if (search_choice == 3) {
				printf("Enter search age - \n");
				scanf("%d", &number);
				for (i = 0; i < position; i++) {
					if (number == roster[i].age) {
						print_student_info(roster, i);
					}
				}
			}
			else {
				printf("ERROR - Invalid input choice\n");
				exit(0);
			}
		}
		printf("Input choice - \n");
		scanf("%d", &choice);
		check_choice_correctness(choice);
	}
	return 0;
}
