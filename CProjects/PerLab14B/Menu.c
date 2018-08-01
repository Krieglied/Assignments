#include "Menu.h"


struct Student
{
	char student_initials[256];
	char artist[256];
	char car[256];
	struct Student * next_node;
};

void print_student(struct Student * list, int action)
{
	printf("Which student would you like to print? (Select number from 0 to %d\n", sizeof(list));
	int input = 99;
	char * buffer[INT_BUFF_SIZE];
	fgets(buffer, INT_BUFF_SIZE, stdin);
	while (fgetc(stdin) != '\n');
	input = atoi(buffer);
	for (int i = 0; i < input; i++)
	{
		list = list->next_node;
	}
	switch (action) 
	{
	case INITIALS:
		print_initials(list);
		break;
	case ARTIST:
		print_artist(list);
		break;
	case CAR:
		print_car(list);
		break;
	}	
}
void print_initials(struct Student * list)
{
	printf("The student initals: %s\n", list->student_initials);
}
void print_artist(struct Student * list)
{
	printf("The student favorite artist: %s\n", list->artist);
}
void print_car(struct Student * list)
{
	printf("The student dream car: %s\n", list->car);
}
void print_all_students(struct Student * list)
{
	print_student(list, ALL);
	if (list->next_node != NULL)
	{
		print_all_students(list->next_node);
	}
}
void print_all_initals(struct Student * list)
{
	print_initials(list);
	if (list->next_node != NULL)
	{
		print_all_initals(list->next_node);
	}
}
void print_all_artists(struct Student * list)
{
	print_artist(list);
	if (list->next_node != NULL)
	{
		print_all_artists(list->next_node);
	}
}
void print_all_cars(struct Student * list)
{
	print_car(list);
	if (list->next_node != NULL)
	{
		print_all_cars(list->next_node);
	}
}