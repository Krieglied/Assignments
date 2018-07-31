//Performance Lab 13A
//Robert John Graham III
//July 30, 2018

/*
Haystack Needle Lab

Purpose:
Remove the needle from the haystack
AKA: Move the substring from the string using memory operators and functions

*/
// TODO: Include any needed headers
#include <stdio.h>          // For printf and such
#include <stdlib.h>         // For malloc()


int haystack_needle(char *haystack, char *needle, char *buffer);

int main()
{
	  char string[] = "This is my brand new sentence";
	  char substring[] = " brand new";
	  char * buffer_ptr;
	  // TODO: Create a char buffer named *buffer using malloc \
	  ensure it is large enough to hold string[] + a nul-terminator
	  buffer_ptr = (char *)malloc(strlen(string + 1));

	  // TODO: Ensure buffer was created
	  if (buffer_ptr == NULL)
	  {
		  printf("ERROR: Not enough memory!");
		  return 1;
	  }
	  //Function call
	  haystack_needle(string, substring, buffer_ptr);
	  // TODO: Give back the memory from buffer
	  free(buffer_ptr);
	  buffer_ptr = NULL;
	  
	  // TODO: Print out the modified string
	  printf("The modified string: %s", string);
	  while (1);
	  return 0;
}

/*
Arguments:
-haystack --- pointer to string to search
-needle   --- pointer to substring to search inside of haystack
-buffer   --- pointer to a buffer

PURPOSE:
haystack_needle takes the arguments above and searches the haystack
for the needle. Once it finds the needle... it removes it from the haystack.

Return:
return 0 on success
return -1 on error .... only needed if userinput is enabled.
*/
int haystack_needle(char *haystack, char *needle, char *buffer)
{
    int needleLength = strlen(needle);
	char * mark_position = strstr(haystack, needle);
    // TODO: Using strstr() find the needle in the haystack (substring in string)\
    the pointer that is returned is pointing to the substring within the string \
    Set that pointer to a new char pointer called *mark_position

	strcpy(buffer, mark_position + needleLength);
    // TODO: Using strcpy(), store the needle into the buffer... \
    you are not authorized to use the variable needle.

    // TODO: Using memmove, overwrite the haystack (string)... effectivly removing the needle \
    // HINT: start at the mark_position... that is after all where we need to start replacing.
	memmove(mark_position, buffer, strlen(buffer) + 1);
    return 0;
}
