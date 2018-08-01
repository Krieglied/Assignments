#include "Menu.h"


struct Student
{
	char student_initials[256];
	char artist[256];
	char car[256];
	struct Student * next_node;
};

void print_student(struct Student * list)
{
	print_initials(list);
	print_artist(list);
	print_car(list);
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
	print_student(list);
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