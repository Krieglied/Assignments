#define _CRT_SECURE_NO_WARNINGS 1

#include "Students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_BUFF_SIZE 2
#define INITIAL_BUFF_SIZE 4
#define BUFF_SIZE 256

struct Student * input_student(struct Student * list);
struct Student * hardcode_student(void);
struct Student * delete_student(struct Student * student, struct Student * list);
struct Student * delete_end(struct Student * list);