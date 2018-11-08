//Robert John Graham III
//August 30, 2018

#include "StudentCode.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

/**
 * !!!!!!!!!!!!!!!!!!!!!!!!!!! HEY! LISTEN !!!!!!!!!!!!!!!!!!!!!!
 * WHAT IS NQUEENS PROBLEM?
 * REFERENCE: https://developers.google.com/optimization/cp/queens
 * 
 * 
 * Parameters:
 * @param nq - An object that implements the NQueens interface
 * @param n_start - The number to start calculating at
 * @param n_stop - The number to stop calculating at
 * @return A std::map containing: A key for each number in the range, with a value of the number of solutions calculated.
 *
 * Quick Overview:
 * The purpose of this exercise is to calculate the number of solutions to the N Queens problem, over a range
 * of numbers for N. The purpose of the N Queens problem is to determine how many queens can (legally) be placed on
 * a hypothetical chess board of NxN squares, without being able to attack each other.
 *
 * Methods:
 * The NQueens interface (from the grader namespace) provides two methods:
 *  1.) the is_valid() method, which takes a const reference to a std::vector, and returns true if
 *      the numbers in the vector are a valid solution for the N Queens problem, and false otherwise.
 *  2.) the next_permutation() method, which takes a reference to a vector, and attempts to generate the next
 *      permutation. If it succeeds, it will return true. If no more permutations exist, it will return false instead.
 *
 * High Level:
 *  At a high level, you will need to iterate over all of the permutations for each number in the range requested (from
 *  n_start to n_stop), get a count of valid solutions for each, and store the pair of N and the count of solutions in
 *  the map that will be returned when the function completes.

 ** TIPS: 
 * Don't get too worked up about how NQueens works. Especially the math part. This is all taken care for you. 
 * Focus more on utilizing methods that already exist. 
 * nq is how you will access the NQueens interface and all of it's methods, reference GraderCode
 * You will be provided with a n_start and n_stop, reference above what they are
     * Virtualize n_start as the first NxN board we are going to test. 
	 * Virtalize n_stop as the last NxN board we are going to test
	 * So let's say n_start is 3 and n_stop is 6... we will test boards 3x3, 4x4, 5x5, 6x6
 * By test, I simply mean see how many different variations of queens we can fit on a board that can't attack each other
     * A queen can attack horizontally, vertically, and diagonally... but who cares? That's not your job to figure out. Let the class handle it. 
 * We are returning the total NUMBER OF SOLUTIONS... not how many total queens can fit. Reference the google reference above
     * For a 1x1... only 1 queen can ever fit on a board. But for the rest of the sizes, assume you need at least two queens
	   to count as a solution. So some board sizes. will have 0 solutions. Reference comments in GraderCode.cpp for number of solutions per board size
 * The map m provided will be used to store the board size (key) and number of solutions for that size (value)
     * So using the n_start 3 to n_stop 6 we referenced above.... your map should be:
	     * 3:0, 4:2, 5:10, 6:4

 ** INSTRUCTIONS:
 * Print out the start and stop given
 * Iterate through the board sizes n_start, n_stop
 	* Create a vector who's size is the current board size you are going to test (Think of this vector as a chessboard) 
	 	* So if you are given a board size of 4, your vector will be of size 4
		* Populate that vector starting at 1 to N, N being the size of the vector, ex: 1,2,3,4, ...N
		* This vector will be used in your methods, it must always start at 1
 	* Using the methods next_permutation() and is_valid()... 
    	* Itterate through each permutation, then check if that permutation is a valid solution
		* Increase count for for all valid permutations
		* Once all permutations are attempted and all solutions are found for a given board size, 
		populate your map with the correct key (board size) and value (solutions)
		* Print out the board size just tested and how many solutions it has
		* Itterate to the next board size and repeat steps above
		* When the map is entirely populated, return the map. 
		* HEY, LISTEN! You can also just print out the map before returning rather than printing it out like so above. 
			* Though this method is more suited for a final version. Printing out each board size and it's solutions one at a time
			can give you debugging information quicker. (This program does take awhile to run.)
	* When you are finished, call an instructor over and run the code for him. Wait for instruction. 
 *
 *
 */
std::map<uint32_t, uint32_t> get_solutions(grader::NQueens& nq, uint32_t n_start, uint32_t n_stop) {
	std::map<uint32_t, uint32_t> m;
	std::cout << "Start given: " << n_start << std::endl;
	std::cout << "Stop given: " << n_stop << std::endl;
	//Vector that will hold the values from 1 to N (board size)
	std::vector<uint32_t> currentBoard;
	//Counter for valid solutions
	int numberOfSolutions = 0;
	for (int i = n_start; i <= n_stop; i++)
	{
		//The board must be clear of any previous data
		currentBoard.clear();
		//The vector will be populated with 1 to N (board size)
		for (int j = 1; j <= i; j++)
		{
			currentBoard.push_back(j);
		}
		do
		{
			//Check to see if current board configuration is a valid solution
			if (nq.is_valid(currentBoard))
			{
				//It is, so increment numberOfSolutions
				numberOfSolutions++;
			}
			//next_permutation changes the board to a new configuration to be checked, or returns false
			//if no more unique configurations exist
		} while (nq.next_permutation(currentBoard));
		std::cout << "Board size of " << i << " has " << numberOfSolutions << " solutions." << std::endl;
		//Once all configurations are check for validity, store that value into the map
		m.emplace(i, numberOfSolutions);
		//Reset counter for next size of board
		numberOfSolutions = 0;
	}
	//Return all the board sizes requested and their number of solutions
	return m;
}
