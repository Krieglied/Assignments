#include "UserInput.h"

//This explicit struct declaration is required, as trying to just use the header file results
//in an incomplete type error
struct Student
{
	char student_initials[256];
	char artist[256];
	char car[256];
	struct Student * next_node;
};

//If the user wants to input the student , they use this function
struct Student * input_student(struct Student * list)
{
	//Handles the buffer choice for the student's initials
	char init_buffer[INITIAL_BUFF_SIZE];
	printf("Enter in the student's initials(maximum length of 3): ");
	fgets(init_buffer, INITIAL_BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');

	//Handles the buffer choice for the student's favorite artist
	char artist_buffer[BUFF_SIZE];
	printf("Enter in the student's favorite artist(maximum length of 255) then press enter twice: ");
	fgets(artist_buffer, BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');

	//Handles the buffer choice for the student's dream car
	char car_buffer[BUFF_SIZE];
	printf("Enter in the student's favorite car(maximum length of 255) then press enter twice: ");
	fgets(car_buffer, BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');

	//The new struct to handle the student element
	struct Student * newStudent = (struct Student*)malloc(sizeof(struct Student));
	strcpy(newStudent->student_initials, init_buffer);
	strcpy(newStudent->artist, artist_buffer);
	strcpy(newStudent->car, car_buffer);
	//If the list of students is empty, then set the next node to NULL and set the list to the student element
	if (*list->student_initials == ' ')
	{
		newStudent->next_node = NULL;
		list = newStudent;
	}
	else
	{
		//Otherwise, the user is prompted if they want to add the element at the head or tail
		int input = 99;
		char choice_buffer[INT_BUFF_SIZE];
		printf("Do you wish to add to the head (press 0) or to the tail (press 1): ");
		fgets(choice_buffer, INT_BUFF_SIZE, stdin);
		while (fgetc(stdin) != '\n');
		input = atoi(choice_buffer);
		if (input)
		{
			//If the element is to added to the tail, the element will not have a next node
			newStudent->next_node = NULL;
			struct Student * tempList = list;
			//Here a temporary list is used to iterate to the last element
			while (tempList->next_node != NULL)
			{
				tempList = tempList->next_node;
			}
			//The list will add the student as the new next_node for its last element
			tempList->next_node = newStudent;
		}
		else
		{
			//Else, if the new element is added to the head, the next_node for the element will be 
			//The list that it is being added to.  Then set the list as the element.
			newStudent->next_node = list;
			list = newStudent;
		}
	}	
	return list;
}
//If the user doesn't want to input students, use these hardcoded values
struct Student * hardcode_student(void)
{
	struct Student * student0 = (struct Student*)malloc(sizeof(struct Student));
	struct Student * student1 = (struct Student*)malloc(sizeof(struct Student));
	struct Student * student2 = (struct Student*)malloc(sizeof(struct Student));
	struct Student * student3 = (struct Student*)malloc(sizeof(struct Student));
	struct Student * student4 = (struct Student*)malloc(sizeof(struct Student));

	char initials0[] = { "abc" };
	char initials1[] = { "daf" };
	char initials2[] = { "rjg" };
	char initials3[] = { "plo" };
	char initials4[] = { "tgh" };

	char artist_value0[] = { "Madonna\n" };
	char artist_value1[] = { "Michael Jackson\n" };
	char artist_value2[] = { "Paul McCartney\n" };
	char artist_value3[] = { "Elvis Presley\n" };
	char artist_value4[] = { "Roger Waters\n" };

	char car_value0[] = { "Camaro\n" };
	char car_value1[] = { "Veyron\n" };
	char car_value2[] = { "R8\n" };
	char car_value3[] = { "Porsche\n" };
	char car_value4[] = { "Mustang\n" };

	strcpy(student0->student_initials, initials0);
	strcpy(student1->student_initials, initials1);
	strcpy(student2->student_initials, initials2);
	strcpy(student3->student_initials, initials3);
	strcpy(student4->student_initials, initials4);

	strcpy(student0->artist, artist_value0);
	strcpy(student1->artist, artist_value1);
	strcpy(student2->artist, artist_value2);
	strcpy(student3->artist, artist_value3);
	strcpy(student4->artist, artist_value4);

	strcpy(student0->car, car_value0);
	strcpy(student1->car, car_value1);
	strcpy(student2->car, car_value2);
	strcpy(student3->car, car_value3);
	strcpy(student4->car, car_value4);

	student4->next_node = NULL;
	student3->next_node = student4;
	student2->next_node = student3;
	student1->next_node = student2;
	student0->next_node = student1;
	
	struct Student * listofStudents = student0;
	return listofStudents;
}
//To delete a student, the student position and the previous element are passed to the function
struct Student * delete_student(struct Student * student, struct Student * list)
{
	//Set the previous element's next node to the element after the student element
	list->next_node = student->next_node;
	//Free the memory allocated to student struct
	free(student);
}
//This function removes the last node
struct Student * delete_end(struct Student * list)
{
	//The two lists are used both find the last node and next to last node
	struct Student * tempList = list;
	struct Student * compareList = list;
	//If the last node has no next node, then the next to last node needs to be recorded
	while (compareList->next_node != NULL)
	{
		tempList = tempList->next_node;
		compareList = tempList->next_node;
	}
	//The next to last node needs its next node element set to NULL
	tempList->next_node = NULL;
	//Free the memory allocated to last node
	free(compareList);
}
