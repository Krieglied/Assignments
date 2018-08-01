#define _CRT_SECURE_NO_WARNINGS 1

#include "UserInput.h"
#include "Students.h"



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
	char init_buffer[INITIAL_BUFF_SIZE];
	printf("Enter in the student's initials(maximum length of 3): ");
	fgets(init_buffer, INITIAL_BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');

	char artist_buffer[BUFF_SIZE];
	printf("Enter in the student's favorite artist(maximum length of 255) then press enter twice: ");
	fgets(artist_buffer, BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');

	char car_buffer[BUFF_SIZE];
	printf("Enter in the student's favorite car(maximum length of 255) then press enter twice: ");
	fgets(car_buffer, BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');

	struct Student newStudent = { init_buffer, artist_buffer, car_buffer, &list};
	reassign_head(newStudent, &list);
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

	char artist_value0[] = { "Madonna" };
	char artist_value1[] = { "Michael Jackson" };
	char artist_value2[] = { "Paul McCartney" };
	char artist_value3[] = { "Elvis Presley" };
	char artist_value4[] = { "Roger Waters" };

	char car_value0[] = { "Camaro" };
	char car_value1[] = { "Veyron" };
	char car_value2[] = { "R8" };
	char car_value3[] = { "Porsche" };
	char car_value4[] = { "Mustang" };

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