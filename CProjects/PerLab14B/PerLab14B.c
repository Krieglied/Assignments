//Performance Lab 14B
//Robert John Graham III
//July 31, 2018

#include "PerLab14B.h"

//This explicit struct declaration is required, as trying to just use the header file results
//in an incomplete type error
struct Student
{
	char student_initials[256];
	char artist[256];
	char car[256];
	struct Student * next_node;
};

int main(void)
{
	//This is the list of students
	struct Student * listofStudents = (struct Student*)malloc(sizeof(struct Student));
	//These are the default value for the list
	strcpy(listofStudents->student_initials, " ");
	strcpy(listofStudents->artist, " ");
	strcpy(listofStudents->car, " ");
	listofStudents->next_node = NULL;
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
			listofStudents = input_student(listofStudents);
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
	//This struct will be the one maniulating the information
	struct Student * currentStudent = listofStudents;
	do {
		//Menu options
		printf("Please the menu option you wish to execute (Enter the number for the option): \n");
		printf("Print a student's information (1): \n");
		printf("Print a student's initals (2): \n");
		printf("Print a student's favorite artist (3): \n");
		printf("Print a student's favorite car (4): \n");
		printf("Print all students' information (5): \n");
		printf("Print all initials (6): \n");
		printf("Print all artists (7): \n");
		printf("Print all cars (8): \n");
		printf("Delete the end student (10): \n");
		printf("Delete a particular student (11): \n");
		printf("Exit(9): \n");
		fgets(buffer, INT_BUFF_SIZE, stdin);
		while (fgetc(stdin) != '\n');
		input = atoi(buffer);
		//previousStudent is used for deleting a particular student element
		struct Student * previousStudent = currentStudent;
		//If the input selected 1-4 or 11, then a particular node needs to be looked at
		if (input <= CAR || input == DELETE_STUDENT)
		{
			int counter = 0;
			//Counts the total number of elements
			do
			{
				counter++;
				if (currentStudent->next_node != NULL)
				{
					currentStudent = currentStudent->next_node;
				}
				
			} while (currentStudent->next_node != NULL);
			currentStudent = listofStudents;
			printf("Which student would you like to select? (Select number from 0 to %d)\n", counter);
			int input = 99;
			char * buffer[INT_BUFF_SIZE];
			fgets(buffer, INT_BUFF_SIZE, stdin);
			while (fgetc(stdin) != '\n');
			input = atoi(buffer);
			//Based on the user input, the particular node is moved to
			for (int i = 0; i < input; i++)
			{
				if (i < input - 1)
				{
					previousStudent = currentStudent->next_node;
				}
				currentStudent = currentStudent->next_node;
			}
		}
		switch (input)
		{
			//Prints the all information for the specified student
		case ALL:
			printf("PRINT STUDENT\n\n");
			print_student(currentStudent);
			printf("\n");
			break;
			//Prints the initials for the specified student
		case INITIALS:
			printf("PRINT INITALS\n\n");
			print_initials(currentStudent);
			printf("\n");
			break;
			//Prints the artist for the specified student
		case ARTIST:
			printf("PRINT ARTIST\n\n");
			print_artist(currentStudent);
			printf("\n");
			break;
			//Prints the car for the specified student
		case CAR:
			printf("PRINT CAR\n\n");
			print_car(currentStudent);
			printf("\n");
			break;
			//Prints the all information for all the students
		case ALL_STUDENTS:
			printf("PRINT ALL STUDENTS\n\n");
			print_all_students(currentStudent);
			printf("\n");
			break;
			//Prints the initials for all the students
		case ALL_INITIALS:
			printf("PRINT ALL INITIALS\n\n");
			print_all_initals(currentStudent);
			printf("\n");
			break;
			//Prints the artists for all the students
		case ALL_ARTISTS:
			printf("PRINT ALL ARTISTS\n\n");
			print_all_artists(currentStudent);
			printf("\n");
			break;
			//Prints the cars for all the students
		case ALL_CARS:
			printf("PRINT ALL CARS\n\n");
			print_all_cars(currentStudent);
			printf("\n");
			break;
			//Deletes the last element of the list
		case DELETE_END:
			printf("DELETING THE END STUDENT\n\n");
			delete_end(currentStudent);
			printf("\n");
			break;
			//Deletes the specified element from the list
		case DELETE_STUDENT:
			printf("DELETE A STUDENT\n\n");
			delete_student(currentStudent, previousStudent);
			printf("\n");
			break;
		default:
			break;
		}
		//Resets the manipulation variable back to the start of the list
		//If the user wishes to do more with the list
		currentStudent = listofStudents;
	}while (input != EXIT);
	return 0;
}