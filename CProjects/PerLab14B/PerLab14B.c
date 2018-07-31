//Performance Lab 14B
//Robert John Graham III
//July 31, 2018

#include "PerLab14B.h"

int main(void)
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

	printf("%s\n", init_buffer);
	printf("%s\n", artist_buffer);
	printf("%s\n", car_buffer);
	while (1);
	return 0;
}

/*if (!(strchr(temp, '\n')))
{
	printf("Too many characters \n");
	while (fgetc(stdin) != '\n');
}*/