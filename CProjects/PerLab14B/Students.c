struct Student
{
	char student_initials[4];
	char artist[256];
	char car[256];
	struct Student * next_node;
};