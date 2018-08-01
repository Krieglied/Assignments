#include "UserInput.h"
#include "Students.h"

//This explicit struct declaration is required, as trying to just use the header file results
//in an incomplete type error
struct Student
{
	char * student_initials;
	char * artist;
	char * car;
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

	struct Student student4 = { &initials4 , &artist_value4 , &car_value4, NULL};
	struct Student student3 = { &initials3 , &artist_value3 , &car_value3, &student4 };
	struct Student student2 = { &initials2 , &artist_value2 , &car_value2, &student3 };
	struct Student student1 = { &initials1 , &artist_value1 , &car_value1, &student2 };
	struct Student student0 = { &initials0 , &artist_value0 , &car_value0, &student1 };
	
	struct Student * listofStudents = &student0;
	return listofStudents;
}