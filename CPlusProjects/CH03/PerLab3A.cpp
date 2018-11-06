//Performance Lab 3A
//Robert John Graham III
//August 10, 2018

#include "person.h"

//using namespace IQT;

int log_roster(std::vector<Person>&, std::ofstream&);
int generate_roster(std::vector<Person>&);

int main()
{
	std::ofstream outfile("roster.txt");
	std::vector<Person> roster;

	int roster_size = generate_roster(roster);
	int logged_count = log_roster(roster, outfile);

	if (roster_size == logged_count)
		std::cout << "Roster logged successfully";
	else
		std::cout << "Roster size and logged count mismatch. Error!" << std::endl;
	outfile.close();
	roster.clear();
	while (true);
	return 0;

}
//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic
int log_roster(std::vector<Person>& roster, std::ofstream& outfile)
{
	int count = 0;
	//The output file will be formatted with this header
	std::string heading = "FIRST NAME  LAST NAME  AGE  GENDER";
	outfile << heading << std::endl;
	while (!roster.empty())
	{
		//Each roster item will be added line by line
		outfile << roster.back().getFname() << "  " << roster.back().getLname() << "  " << roster.back().getAge() << "  " << roster.back().getGender() << std::endl;
		roster.pop_back();
		count++;
	}
	return count;
}

//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 
int generate_roster(std::vector<Person>& roster)
{
	int count = 0;
	int exit = 0;
	//The user input for the person's information
	while (!exit)
	{
		std::string fname, lname, gender, input;
		int age;
		std::cout << "Please enter in a Person, one element at a time." << std::endl;
		std::cout << "Please enter in a first name: " << std::endl;
		std::getline(std::cin, fname);
		std::cout << "Please enter in a last name: " << std::endl;
		std::getline(std::cin, lname);
		while (true)
		{
			//Reverify that the age is of the appropriate type
			std::cout << "Please enter in an age: " << std::endl;
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if (myStream >> age)
			{
				break;
			}
			std::cout << "Invalid number, please try again" << std::endl;
		}
		std::cout << "Please enter in a gender: " << std::endl;
		std::getline(std::cin, gender);
		while (true)
		{
			std::cout << "Will another person be put in? (1 for no, 0 for yes)" << std::endl;
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if (myStream >> exit)
			{
				break;
			}
			std::cout << "Invalid number, please try again" << std::endl;
		}
		//Using the information collected, input it into a Person object
		Person scrub (fname, lname, age, gender);
		//Pass the person object to the vector
		roster.push_back(scrub);
		count++;
	}
	return count;
}
