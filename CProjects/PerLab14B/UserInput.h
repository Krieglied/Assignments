#include "Students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFF_SIZE 4
#define BUFF_SIZE 256

struct Student * input_student(struct Student * list);
struct Student * hardcode_student(void);