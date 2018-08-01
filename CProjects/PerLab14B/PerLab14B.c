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

	if (input == 0)
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
	else if (input == 1)
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
		case 1:
			printf("PRINT STUDENT\n");
			print_student(currentStudent);
			break;
		case 2:
			printf("PRINT INITALS\n");
			print_initials(currentStudent);
			break;
		case 3:
			printf("PRINT ARTIST\n");
			print_artist(currentStudent);
			break;
		case 4:
			printf("PRINT CAR\n");
			print_car(currentStudent);
			break;
		case 5:
			printf("PRINT ALL STUDENTS\n");
			print_all_students(currentStudent);
			break;
		case 6:
			printf("PRINT ALL INITIALS\n");
			print_all_initals(currentStudent);
			break;
		case 7:
			printf("PRINT ALL ARTISTS\n");
			print_all_artists(currentStudent);
			break;
		case 8:
			printf("PRINT ALL CARS\n");
			print_all_cars(currentStudent);
			break;
		default:
			break;
		}
	}while (input != 9);
	return 0;
}

/*if (!(strchr(temp, '\n')))
{
	printf("Too many characters \n");
	while (fgetc(stdin) != '\n');
}*/