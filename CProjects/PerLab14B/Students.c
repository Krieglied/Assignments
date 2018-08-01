#include "Students.h"

struct Student
{
	char student_initials[4];
	char artist[256];
	char car[256];
	struct Student * next_node;
};
int reassign_head(struct Student newStudent, struct Student * list)
{
	list = &newStudent;
	return 0;
}