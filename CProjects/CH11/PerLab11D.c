/////////////////////////////////////////////Yoder, Graham, Mahaffey, Mane///////////////////////////////////////////
////////////////////////////////////////////////////27/July/2018/////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 6 /////////////////////////////////////////////
////////////////////////////////////////////// MULTI-DIMENSIONAL ARRAYS /////////////////////////////////////////////
//////////////////////////////////////////////////// "Tic Tac Toe" //////////////////////////////////////////////////
////////////////////////////////////////////////////// Stub Code ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Replicate a tic tac toe grid using a two-dimensional char array of global scope (for ease of use)
// Define the following prototype functions in main(void) according to their specifications:
//     int printTheGrid(void);
//     int any_plays_left(void);
//     char did_someone_win(void);
//     int what_is_your_play(char currentPlayer, int gridLocation);
// Loop through those functions, in the order listed above and below, taking input until:
//     Someone wins *or*
//     There are no more selections (stalemate)
// Check for bad input (e.g., Selection 99) and reported errors (e.g., what_is_your_play() should return -1 on
//     an invalid selection)
// Direct reference to array elements (e.g., myArray[0][1]) is authorized.  In other words, pointer arithmetic
//     is not mandatory.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

/*
 * FUNCTION:   int print_the_grid(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, 1
 *             On failure, 0
 *
 * NOTES:      This function should first print out a tic tac toe legend:
 *              1 | 2 | 3
 *             -----------
 *              4 | 5 | 6
 *             -----------
 *              7 | 8 | 9
 *
 *             Then, this function should print out the current state of the 2D char array in a similar format:
 *                |   | X
 *             -----------
 *              X | O |  
 *             -----------
 *                |   |  
 */
int print_the_grid(void);

/*
 * FUNCTION:   int any_plays_left(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the number of available choices
 *             On failure, 0
 *
 * NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
 */
int any_plays_left(void);

/*
 * FUNCTION:   char did_someone_win(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
 *             On failure, 0
 *
 * NOTES:      There are 8 possible win conditions:
 *                 Top row, middle row, bottom row
 *                 Left column, middle column, right column
 *                 Backslash, "Frontslash" (TM pending)
 */
char did_someone_win(void);

/*
 * FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
 *
 * ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
 *             int gridLocation should indicate the position on the grid to place "currentPlayer" as
 *                 defined by whomever defined print_the_grid().
 *
 * RETURNS:	   On a successful choice, 1
 *             If the user chooses a location that has already been taken, 0
 *             On failure, -1
 *
 * NOTES:      Verify that gridLocation has not already been chosed before accepting the play
 *             If the play is valid, record the selection within the 2D tic tac toe array
 */
int what_is_your_play(char currentPlayer, int gridLocation);
int switchPlayer(player);
/* TIC TAC TOE char array */
char ticTacToeGrid[3][3];
char sampleGrid[3][3] = { '1','2','3','4','5','6','7','8','9'};

int main(void)
{
	int numOfPlays=10; //sets number of plays for a nine space grid
	char winner = '\0';
	char player = 'O';
	int choice;
	int results;
	//char choice2[1] ;
	for (int i = 0; i < sizeof(ticTacToeGrid) / sizeof(ticTacToeGrid[i]); i++)
	{
		for (int j = 0; j < sizeof(ticTacToeGrid[i]) / sizeof(ticTacToeGrid[i][j]); j++)
		{
			ticTacToeGrid[i][j] = ' ';
		}
	}

	/* PRINT THE LEGEND AND CURRENT STATUS OF THE GAME */
	print_the_grid();
	while (winner == '\0' && numOfPlays >1) {
		/* DETERMINE IF THERE ARE NO MORE MOVES LEFT */
		numOfPlays = any_plays_left();
		printf("%d plays available. \n", numOfPlays);
		/* DID SOMEONE WIN?  INFORM THE PLAYERS AND END THE GAME */
		

		/* OTHERWISE, ALLOW THE NEXT PLAYER TO MAKE A MOVE */
		player = switchPlayer(player);
		printf("%c please make your choice:", player);
		_flushall();
		scanf("%d", &choice);
		results = what_is_your_play(player, choice);

		if (results == 0)//User input validation
		{
			player = switchPlayer(player);
			printf("Your choice was bad, please choose again! \n");
			continue;
		}

		winner = did_someone_win();
		printf("\n\n");
		print_the_grid();


	}
	if (winner)//Finish Game
	{
		printf("Player %c has won the game: \n", winner);
	}
	if (numOfPlays == 1)
	{
		printf("\nNo moves left!");
	}

	while(1);//Leave window open
	return 0;
}

/*
 * FUNCTION:   int printTheGrid(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, 1
 *             On failure, 0
 *
 * NOTES:      This function should first print out a tic tac toe legend:
 *              1 | 2 | 3
 *             -----------
 *              4 | 5 | 6
 *             -----------
 *              7 | 8 | 9
 *
 *             Then, this function should print out the current state of the 2D char array in a similar format:
 *                |   | X
 *             -----------
 *              X | O |
 *             -----------
 *                |   |
 */
int print_the_grid(void)
{
	for (int i = 0; i < sizeof(sampleGrid) / sizeof(sampleGrid[i]); i++)//Loop to print a sample grid containing the values that can be selected and their positions
	{
		for (int j = 0; j < sizeof(sampleGrid[i]) / sizeof(sampleGrid[i][j]); j++)
		{
			printf(" %c ", sampleGrid[i][j]);
			if ((j + 1) < sizeof(sampleGrid[i]) / sizeof(sampleGrid[i][j]))
			{
				printf("|");
			}
		}
		if ((i + 1) < sizeof(sampleGrid) / sizeof(sampleGrid[i]))
		{
			printf("\n-----------\n");
		}
	}
	printf("\n\n\n");
	for (int i = 0; i < sizeof(ticTacToeGrid) / sizeof(ticTacToeGrid[i]); i++)//Loop to print the current game playing field
	{
		for (int j = 0; j < sizeof(ticTacToeGrid[i]) / sizeof(ticTacToeGrid[i][j]); j++)
		{
			printf(" %c ", ticTacToeGrid[i][j]);
			if ((j + 1) < sizeof(ticTacToeGrid[i]) / sizeof(ticTacToeGrid[i][j]))
			{
				printf("|");
			}
		}
		if ((i + 1) < sizeof(ticTacToeGrid) / sizeof(ticTacToeGrid[i]))
		{
			printf("\n-----------\n");
		}
	}

	printf("\n");
	return 1; 
}


int switchPlayer(player)//Switch turns from one player to another
{
	if (player == 'X')//If player is X switch it
	{
		player = 'O';
	}
	else
	{
		player = 'X';//Otherwise make it so
	}
	return player;
}
/*
 * FUNCTION:   int any_plays_left(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the number of available choices
 *             On failure, 0
 *
 * NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
 */
int any_plays_left(void)//checks to see if there are possible moves left
{
	char * gridPointer = ticTacToeGrid;
	int counter =0;
	for (int i = 0; i < 9; i++)//decriments the counter so that you cannot have more moves than spaces
	{
		if (*(gridPointer + i) == ' ')
		{
			counter++;
		}

	}
	if (counter > 9 || counter < 0)
	{
		return 0;
	}
	return counter;//returns number of moves left in game
}

/*
 * FUNCTION:   char did_someone_win(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
 *             On failure, 0
 *
 * NOTES:      There are 8 possible win conditions:
 *                 Top row, middle row, bottom row
 *                 Left column, middle column, right column
 *                 Backslash, "Frontslash" (TM pending)
 */
char did_someone_win(void)//using if statments to check for any possible win scenarios and returns the the winning players Symbol
{
	int i = 0;
	char * gridPointer = ticTacToeGrid;
	char * reset_gridPointer = gridPointer;
	if ((*gridPointer == *(gridPointer + 3)) && (*(gridPointer + 3) == *(gridPointer + 6))&& *(gridPointer) != ' ')
	{
		return ticTacToeGrid[0][0];
	}
	if ((*(gridPointer + 1) == *(gridPointer + 4)) && (*(gridPointer + 4) == *(gridPointer + 7)) && *(gridPointer + 1) != ' ')
	{
		return ticTacToeGrid[0][1];
	}
	if ((*gridPointer == *(gridPointer + 1)) && (*(gridPointer + 1) == *(gridPointer + 2)) && *(gridPointer) != ' ')
	{
		return ticTacToeGrid[0][0];
	}
	if ((*(gridPointer + 2) == *(gridPointer + 5)) && (*(gridPointer + 5) == *(gridPointer + 8)) && *(gridPointer + 2) != ' ')
	{
		return ticTacToeGrid[0][2];
	}
	if ((*(gridPointer + 3) == *(gridPointer + 4)) && (*(gridPointer + 4) == *(gridPointer + 5)) && *(gridPointer + 3) != ' ')
	{
		return ticTacToeGrid[3][0];
	}
	if ((*(gridPointer + 6) == *(gridPointer + 7)) && (*(gridPointer + 7) == *(gridPointer + 8)) && *(gridPointer + 6) != ' ')
	{
		return ticTacToeGrid[6][0];
	}
	if ((*gridPointer == *(gridPointer + 4)) && (*(gridPointer + 4) == *(gridPointer + 8)) && *(gridPointer) != ' ')
	{
		return ticTacToeGrid[0][0];
	}
	if ((*(gridPointer + 2) == *(gridPointer + 4)) && (*(gridPointer + 4) == *(gridPointer + 6)) && *(gridPointer + 2) != ' ')
	{
		return ticTacToeGrid[0][2];
	}
	return '\0';//returns null if there is no win condition met to continue game
}

/*
 * FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
 *
 * ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
 *             int gridLocation should indicate the position on the grid to place "currentPlayer" as
 *                 defined by whomever defined print_the_grid().
 *
 * RETURNS:	   On a successful choice, 1
 *             If the user chooses a location that has already been taken, 0
 *             On failure, -1
 *
 * NOTES:      Verify that gridLocation has not already been chosed before accepting the play
 *             If the play is valid, record the selection within the 2D tic tac toe array
 */
int what_is_your_play(char currentPlayer, int gridLocation)
{
	char * gridPointer = ticTacToeGrid;
	if (gridLocation < 1 || gridLocation >9)//user input validation
	{
		return -1;
	}
	if (*(gridPointer + gridLocation - 1) != ' ')//check to see if space occupied
	{
		return 0;
	}
	
	*(gridPointer + gridLocation - 1) = currentPlayer;//make selected location equal to either X or O depending on player
	return 1; 
}
