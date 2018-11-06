#include "Menu.h"

//This explicit struct declaration is required, as trying to just use the header file results
//in an incomplete type error
struct Student
{
	char student_initials[256];
	char artist[256];
	char car[256];
	struct Student * next_node;
};

//Prints the all the elements of a particular student
void print_student(struct Student * list)
{
	print_initials(list);
	print_artist(list);
	print_car(list);
	
}
//Print the initials of a student element
void print_initials(struct Student * list)
{
	printf("The student initals: %s\n", list->student_initials);
}
//Print the favorite artist of a student element
void print_artist(struct Student * list)
{
	printf("The student favorite artist: %s", list->artist);
}
//Print the dream car of a student element
void print_car(struct Student * list)
{
	printf("The student dream car: %s", list->car);
}
//Prints all students information in the list
void print_all_students(struct Student * list)
{
	print_student(list);
	//Iterates through the linked list until the last node (which has no next node)
	if (list->next_node != NULL)
	{
		print_all_students(list->next_node);
	}
}
//Prints all student's initials in the list
void print_all_initals(struct Student * list)
{
	print_initials(list);
	//Iterates through the linked list until the last node (which has no next node)
	if (list->next_node != NULL)
	{
		print_all_initals(list->next_node);
	}
}
//Prints all student's artists in the list
void print_all_artists(struct Student * list)
{
	print_artist(list);
	//Iterates through the linked list until the last node (which has no next node)
	if (list->next_node != NULL)
	{
		print_all_artists(list->next_node);
	}
}
//Prints all student's cars in the list
void print_all_cars(struct Student * list)
{
	print_car(list);
	//Iterates through the linked list until the last node (which has no next node)
	if (list->next_node != NULL)
	{
		print_all_cars(list->next_node);
	}
}