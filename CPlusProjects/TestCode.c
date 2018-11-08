//Robert John Graham III
//August 30, 2018

#include <Windows.h>
#include <stdio.h>
#include "TestCode.h"

/////////////////////////////////////////////////////////////
// Test 1: For this task, you will receive two pointers to NULL terminated strings: 
//		   a 'sentence', and a 'word'. The objective will be to delete (in place) the first 
//		   occurrence of 'word' in the sentence. 
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
//		- the provided 'word' is not part of 'sentence': should return ERROR_NOT_FOUND (1168)
/////////////////////////////////////////////////////////////

int deleteWord(char* sentence, char* word)
{
	//If match is 0, then the characters in sentence and word match
	//If match is 1, then they don't
	int match = 0;
	//If either the sentence or the word is null, can't evaluate
	if (sentence == NULL || word == NULL)
	{
		return ERROR_INVALID_PARAMETER;
	}
	//Evaluate on each character within the sentence
	for (int i = 0; i < strlen(sentence); i++)
	{
		//If a character starts the match, need to evaluate characters after that one
		if (sentence[i] == word[0])
		{
			for (int j = 1; j < strlen(word); j++)
			{
				//If any following characters don't match, break out of the for loop
				if (sentence[i + j] != word[j])
				{
					match = 1;
					break;
				}
			}
			//If they match, move from the end of the word, towards the beginning of its position
			//Within the sentence
			if (match == 0)
			{
				int start = i;
				for (int k = i + strlen(word); k < strlen(sentence); k++)
				{
					sentence[start] = sentence[k];
					start++;
				}
				sentence[start] = '\0';
				return ERROR_SUCCESS;
			}
		}
	}
	//If function has gotten to this point, no match found
	return ERROR_NOT_FOUND;
}


/////////////////////////////////////////////////////////////
// Test 3 (part one): This task will involve allocating a buffer
//				of (sizeOfData) bytes, and reading up to that amount
//				into it from the file specified in 'filename'. Additionally,
//				the data in the file has been pseudo-encryped (poorly) with a single-
//				byte XOR, which you will be required to undo (the byte that the buffer
//				was XOR'd against will be provided in 'key'). Finally, assuming the task
//				was successful, (and all pointers are valid) the pointer to the resulting 
//				buffer should be stored in the area referenced by buffPtr.
//
// Expected Return Values:
//			- task was completed successfully: ERROR_SUCCESS (0)
//			- bad input was provided: ERROR_INVALID_PARAMETER (87)
//			- you were unable to allocate enough memory: ERROR_OUTOFMEMORY (14)
//			- you were unable to open the file: ERROR_OPEN_FAILED (110)
/////////////////////////////////////////////////////////////
int decodeFromFile(char* filename, unsigned int sizeOfData, unsigned char key, void** buffPtr)
{
	//If any of the parameters are NULL, return ERROR_INVALID_PARAMETER
	if (filename == NULL || sizeOfData == NULL || key == NULL || buffPtr == NULL)
	{
		return ERROR_INVALID_PARAMETER;
	}
	FILE *fptr;
	char *buffer;
	buffer = (char *)malloc(sizeOfData);
	//If buffer can't be allocated , return ERROR_OUTOFMEMORY
	if (buffer == NULL)
	{
		return ERROR_OUTOFMEMORY;
	}
	fptr = fopen(filename, "r");
	//If file can't be opened , return ERROR_OPEN_FAILED
	if (fptr == NULL) 
	{
		return ERROR_OPEN_FAILED;
	}
	int length = 0;
	//While the input is less than the size of the buffer, bring in the characters
	while (length < sizeOfData)
	{
		buffer[length] = fgetc(fptr) ^ key;
		length++;
	}
	//Set the buffer ptr equal to the address of buffer
	*buffPtr = buffer;
	//CLOSE THE FILE YOU IDIOT
	fclose(fptr);
	return ERROR_SUCCESS;
}

/////////////////////////////////////////////////////////////
// Test 3 (part two): The second part of the task; this simply requires you
//				  to appropriately free the buffer allocated in the last task
//				  (if possible).
//
// Expected Return Values:
//			- the task completed successfully: TRUE
//			- the task failed/bad input: FALSE
/////////////////////////////////////////////////////////////
BOOL freeDecodedBuffer(void* buffer)
{
	//There is a problem is the buffer is already null
	if (buffer == NULL)
	{
		return FALSE;
	}
	else
	{
		//Free up the memory for the pointer
		free(buffer);
		return TRUE;
	}
}
