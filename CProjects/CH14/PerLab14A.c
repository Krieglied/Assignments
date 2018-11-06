//Performance Lab 14A
//Robert John Graham III
//July 31, 2018

#include "PerLab14A.h"

struct test
{
	char * sentence_ptr;
	char * searchWord_ptr;
	char * returnValue_ptr;
	int * default_errorCode_ptr;
	int expected_errorCode_ptr;
};

int main(void)
{
	int i = 0;
	int numTestsRun = 0;
	int numTestsPassed = 0;
	int putErrorCodeHere = DEFAULT_ERROR_CODE;
	char * tempReturnValue_ptr = NULL;
	char testChar1 = 0; // DEBUGGING
	char testChar2 = 0; // DEBUGGING

	/* TEST INPUT */
	// Three normal strings
	char testInput0[] = { "Good luck to you on this lab.\nI hope you do well." }; // Key: \n
	char testInput1[] = { "Normal test input.  'The' is the search key." }; // Key: The
	char testInput2[] = { "This is also normal input.  The 'bird' is the word." }; // Key: bird
	// Two strings that have duplicate keys
	char testInput3[] = { "This string is an example of a string that has two occurrences of the word 'is'." }; // Key: is
	char testInput4[] = { "The word 'the' is very common in the English language." }; // Key: the
	// Two strings that have multiple occurrences of the key
	char testInput5[] = { "Many English words are 'loan words', which is defined as 'a word that has been adopted from one language into another'." }; // Key: word
	char testInput6[] = { "The search keys don't have to be letters!  They could be any character or array of characters!  They could even be puntuation!  Maybe even non-printable characters!  Crazy, right?" }; // Key: "!  "
	// Two NULL strings to pass as sentence_ptr
	char * testInput7 = NULL; // Key: "Doesn't matter"
	char * testInput8 = NULL; // Key: "Don't bother"
	// Two real strings to pass alongside a NULL searchWord
	char testInput9[] = { "It's a shame to waste a perfectly good sentence." }; // Key:  NULL
	char testInput10[] = { "It's a shame to waste a perfectly good null-terminated string." }; // Key:  NULL
	// Two real strings to pass alongside a NULL errorCode
	char testInput11[] = { "At least electrons are free." }; // Key: are
	char testInput12[] = { "Even if they're not free, there is are a plethora of electrons freely available." }; // Key: e
	// Two strings that will pass more NULL search keys
	char testInput13[] = { "You can't find a key here!" }; // Key: NULL
	char testInput14[] = { "Take a picture!  It'll last longer." }; // Key: NULL
	// Two strings to pass long keys
	char testInput15[] = { "Now is the time for all good men to come to the aid of their country." }; // Key: "come to the aid"
	char testInput16[] = { "Sometimes it's hard to play the game the way it was intended to be played instead of following the game's rules as written." }; // Key: "play the game"
	// Edge cases that may break find_the_word()
	char testInput17[] = { "I hope you didn't find anything here!" }; // Key: '\0' (0x0)
	char testInput18[BUFF_SIZE] = { 0 }; // Key: "Don't do it!"
	char testInput19[] = { "Not a long string" }; // Key: "long string as a search key"
	char testInput20[] = { "part" }; // Key: "partial"
	char testInput21[BUFF_SIZE] = { 0 }; // Key: '\0' (0x0)
	// Two strings whose keys are non printable characters
	char testInput22[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x0 }; // Key: 0x8
	char testInput23[] = { 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x0 }; // Key: 0x1C
	// Two strings that include characters from the extended ASCII codes
	char testInput24[] = { '\n', 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, '\n', 0x7C, '$', '(', '5', ')', '$', 0x7C, '\n', 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, '\n', 0x0 }; // Key: 0xC4
	//	puts(testInput24); // DEBUGGING
	char testInput25[] = { 0xC4, 0x5C, 0x5F, 0x2, 0x5F, 0x2F, 0xC4, 0x0 }; // Key: 0x2F
	//	puts(testInput25); // DEBUGGING
	char testInput26[] = { "Sometimes keys are at the beggining of a string." }; // Key: "Sometime"
	char testInput27[] = { "When you lose an item, you always find it in the last place you look." }; // Key: "look."


	//Establish keys for search word
	char testKey0[] = { 10,0 };
	char testKey1[] = { "The" };
	char testKey2[] = { "bird" };
	char testKey3[] = { "is" };
	char testKey4[] = { "the" };
	char testKey5[] = { "word" };
	char testKey6[] = { "!  " };
	char testKey7[] = { "Doesn't matter" };
	char testKey8[] = { "Don't bother" };
	char * testKey9 = NULL;
	char * testKey10 = NULL;
	char testKey11[] = { "are" };
	char testKey12[] = { "e" };
	char * testKey13 = NULL;
	char * testKey14 = NULL;
	char testKey15[] = { "come to the aid" };
	char testKey16[] = { "play the game" };
	char testKey17[] = { 0x0, 0x0 };
	char testKey18[] = { "Don't do it!" };
	char testKey19[] = { "long string as a search key" };
	char testKey20[] = { "partial" };
	char testKey21[1] = { 0x0 };
	char testKey22[] = { 0x8, 0x0 };
	char testKey23[] = { 0x1C, 0x0 };
	char testKey24[] = { 0xC4, 0x0 };
	char testKey25[] = { 0x2F, 0x0 };
	char testKey26[] = { "Sometime" };
	char testKey27[] = { "look." };

	//Setting up the structs
	struct test testEntry1 = { testInput0, testKey0, &testInput0[29], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry2= { testInput1, testKey1, &testInput1[21], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry3 = { testInput2, testKey2, &testInput2[33], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry4 = { testInput3, testKey3, &testInput3[2], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry5 = { testInput4, testKey4, &testInput4[10], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry6 = { testInput5, testKey5, &testInput5[13], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry7 = { testInput6, testKey6, &testInput6[40], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry8 = { testInput7, testKey7, testInput7 , &putErrorCodeHere, ERROR_NULL_SENTENCE_POINTER };
	struct test testEntry9 = { testInput8, testKey8, testInput8 , &putErrorCodeHere, ERROR_NULL_SENTENCE_POINTER };
	struct test testEntry10 = { testInput9, testKey9, NULL , &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };
	struct test testEntry11 = { testInput10 , testKey10, NULL,&putErrorCodeHere , ERROR_NULL_SEARCH_POINTER };
	struct test testEntry12 = { testInput11, testKey11, NULL , NULL, DEFAULT_ERROR_CODE };
	struct test testEntry13 = { testInput12, testKey12, NULL, NULL, DEFAULT_ERROR_CODE };
	struct test testEntry14 = { testInput13, testKey13, NULL , &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };
	struct test testEntry15 = { testInput14, testKey14, NULL , &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };
	struct test testEntry16 = { testInput15, testKey15, &testInput15[36] , &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry17 = { testInput16, testKey16, &testInput16[23], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry18 = { testInput17, testKey17, NULL , &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };
	struct test testEntry19 = { testInput18, testKey18, NULL , &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };
	struct test testEntry20 = { testInput19, testKey19, NULL , &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };
	struct test testEntry21 = { testInput20, testKey20, NULL , &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };
	struct test testEntry22 = { testInput21, testKey21, NULL , &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };
	struct test testEntry23 = { testInput22, testKey22, &testInput22[7], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry24 = { testInput23 , testKey23, &testInput23[2], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry25 = { testInput24 , testKey24, &testInput24[17], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry26 = { testInput25 , testKey25, &testInput25[5], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry27 = { testInput26 , testKey26, &testInput26[0], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	struct test testEntry28 = { testInput27 , testKey27, &testInput27[64], &putErrorCodeHere, ERROR_CODE_SUCCESS };
	//Array of structs to be passed to the function
	struct test tests[28] = { testEntry1, testEntry2, testEntry3 , testEntry4 , testEntry5 , testEntry6 , testEntry7,
		testEntry8 , testEntry9 , testEntry10 , testEntry11 , testEntry12 , testEntry13 , testEntry14,
		testEntry15 , testEntry16 , testEntry17 , testEntry18 , testEntry19 , testEntry20 , testEntry21,
		testEntry22 , testEntry23 , testEntry24 , testEntry25 , testEntry26 , testEntry27 , testEntry28 };

	/* CALCULATE THE NUMBER OF TESTS */
	int numTotalTests = sizeof(tests) / sizeof(tests[0]);
	//	printf("The length of the test array is: %d \n", sizeof(testInputArray)/sizeof(testInputArray[0])); // DEBUGGING

	/* EXECUTE THE TESTS */
	for (i = 0; i < numTotalTests; i++)
	{
		/* 0. TEST HEADER */
		printf("\n");
		printf("************\n");
		printf("* TEST #%02d *\n", i);
		printf("************\n");
		//Passes the sentence ptr, search word ptr, and the default error value ptr
		tempReturnValue_ptr = find_the_word((tests + i)->sentence_ptr, (tests + i)->searchWord_ptr, (tests + i)->default_errorCode_ptr);

		/* 1. TEST RETURN VALUE */
		numTestsRun++;
		printf("\tReturn Value Test:\t");
		if (tempReturnValue_ptr == (tests + i)->returnValue_ptr)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected pointer:\t%p\n", (tests + i)->returnValue_ptr);
			printf("\t\tReceived pointer:\t%d\n", tempReturnValue_ptr);
		}

		/* 2. TEST ERROR CODE */
		numTestsRun++;
		printf("\tError Code Test:\t");
		if (putErrorCodeHere == (tests + i)->expected_errorCode_ptr)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected error code:\t%d\n", (tests + i)->expected_errorCode_ptr);
			printf("\t\tReceived error code:\t%d\n", putErrorCodeHere);
			if (putErrorCodeHere == DEFAULT_ERROR_CODE)
			{
				puts("\t\tError code not even updated!");
			}
		}

		putErrorCodeHere = DEFAULT_ERROR_CODE; // Reset error code
	}

	if (numTestsRun)
	{
		printf("\n\n\n*******************************\n");
		printf("Out of the %d tests that ran...\n", numTestsRun);
		printf("%d tests passed.\n", numTestsPassed);
		printf("*******************************\n");
	}
	while (1);
	return 0;
}

char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
{
	//If sentence_ptr is NULL, *searchWord_ptr is NULL, or	*errorCode_ptr is NULL, NULL is return
	//Error_ptr is set to a value for sentence or searchWord ptr is NULL
	if (!sentence_ptr || !searchWord_ptr || errorCode_ptr == NULL)
	{
		if (!sentence_ptr)
		{
			*errorCode_ptr = ERROR_NULL_SENTENCE_POINTER;
		}
		if (!searchWord_ptr)
		{
			*errorCode_ptr = ERROR_NULL_SEARCH_POINTER;
		}
		return NULL;
	}
	//These reset ptr need to be used for each iteration
	char * reset_search_ptr = searchWord_ptr;
	char * reset_sentence_ptr = sentence_ptr;
	//int found is treated as boolean value, set to 1 once a match is found
	int found = 0;
	//Iterate through the sentence array
	while (*sentence_ptr != '\0')
	{
		//If a character match is found
		if (*sentence_ptr == *searchWord_ptr)
		{
			//First store the sentence and searchWord, in case of need of reset
			reset_search_ptr = searchWord_ptr;
			reset_sentence_ptr = sentence_ptr;
			//Cycle through rest of sentence
			while (*sentence_ptr != '\0')
			{
				//If the character doesn't match, cancel this iteration
				if (!(*sentence_ptr == *searchWord_ptr))
				{
					break;
				}
				//If characters do, iterate both ptrs
				*sentence_ptr++;
				*searchWord_ptr++;
				//If search ptr is at the end, then searchWord has been found
				//Set found to 1
				//Break loop
				if (*searchWord_ptr == '\0')
				{
					found = 1;
					break;
				}
			}
			//Check if iteration found the searchWord
			//If not, set the ptrs for sentence and searchWord back to their original states
			if (!found)
			{
				sentence_ptr = reset_sentence_ptr;
				searchWord_ptr = reset_search_ptr;
			}
			//Match Found!
			//Set errorcode to SUCCESS and return the sentence_ptr from this position on
			else
			{
				*errorCode_ptr = ERROR_CODE_SUCCESS;
				return reset_sentence_ptr;
			}
		}
		//Reset searchWord ptr
		reset_search_ptr = searchWord_ptr;
		*sentence_ptr++;
		//Sentence ptr gets iterate and that becomes the new standard
		reset_sentence_ptr = sentence_ptr;
	}
	//Full iteration was done and searchWord not found
	*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
	return NULL;
}