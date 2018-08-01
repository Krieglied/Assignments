//Performance Lab 14B
//Robert John Graham III
//July 31, 2018

#include "PerLab14B.h"

struct Student
{
	char student_initials[256];
	char artist[256];
	char car[256];
	struct Student * next_node;
};

int main(void)
{
	struct Student * listofStudents = (struct Student*)malloc(sizeof(struct Student));
	//Inital user input to select manual input or to use precoded values
	printf("Would you like to input students (press 0) or use hardcoded values (press 1): ");
	int input = 99;
	char * buffer[INT_BUFF_SIZE];
	fgets(buffer, INT_BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');
	input = atoi(buffer);

	if (input == INPUT_STUDENTS)
	{
		do
		{
			//Once selection is inputted, ask user if there is another student to put in
			listofStudents = input_student(&listofStudents);
			printf("Would you like to input another student (1 for yes, 0 for no): ");
			fgets(buffer, INT_BUFF_SIZE, stdin);
			while (fgetc(stdin) != '\n');
			input = atoi(buffer);
		} while (input);
	}
	else if (input == HARDCODE)
	{
		//Grab the hardcoded list of valuess
		listofStudents = hardcode_student();
	}
	else
	{
		printf("Your selection was in ERROR.");
	}
	//struct Student * currentStudent = (struct Student*)malloc(sizeof(struct Student));
	struct Student * currentStudent = listofStudents;
	do {
		printf("Please the menu option you wish to execute (Enter the number for the option): \n");
		printf("Print a student's information (1): \n");
		printf("Print a student's initals (2): \n");
		printf("Print a student's favorite artist (3): \n");
		printf("Print a student's favorite car (4): \n");
		printf("Print all students' information (5): \n");
		printf("Print all initials (6): \n");
		printf("Print all artists (7): \n");
		printf("Print all cars (8): \n");
		printf("Exit(9): \n");
		fgets(buffer, INT_BUFF_SIZE, stdin);
		while (fgetc(stdin) != '\n');
		input = atoi(buffer);
		switch (input)
		{
		case ALL:
			printf("PRINT STUDENT\n\n");
			print_student(currentStudent, ALL);
			printf("\n");
			break;
		case INITIALS:
			printf("PRINT INITALS\n\n");
			print_initials(currentStudent, INITIALS);
			printf("\n");
			break;
		case ARTIST:
			printf("PRINT ARTIST\n\n");
			print_artist(currentStudent, ARTIST);
			printf("\n");
			break;
		case CAR:
			printf("PRINT CAR\n\n");
			print_car(currentStudent, CAR);
			printf("\n");
			break;
		case ALL_STUDENTS:
			printf("PRINT ALL STUDENTS\n\n");
			print_all_students(currentStudent);
			printf("\n");
			break;
		case ALL_INITIALS:
			printf("PRINT ALL INITIALS\n\n");
			print_all_initals(currentStudent);
			printf("\n");
			break;
		case ALL_ARTISTS:
			printf("PRINT ALL ARTISTS\n\n");
			print_all_artists(currentStudent);
			printf("\n");
			break;
		case ALL_CARS:
			printf("PRINT ALL CARS\n");
			print_all_cars(currentStudent);
			printf("\n");
			break;
		default:
			break;
		}
	}while (input != EXIT);
	return 0;
}