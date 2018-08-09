//Bonus Lab Encode
//Robert John Graham III
//August 9, 2018

#include <iostream>
#include <fstream>
#include <string>

int main()
{
<<<<<<< HEAD
	//Input text file
	std::ifstream file("textInput.txt");
	std::string line;
	std::string input;
	if (file.is_open())
	{
		//The file is looked at,line by line
		while (std::getline(file, line))
		{
			for(const auto& item : line)
			{
				input += (char)(item + 3);
			}
			input += '\n';
		}
	}
	file.close();
	std::ofstream encodedfile("encodedText.txt");
	if(encodedfile.is_open())
	{
		encodedfile << input;
		encodedfile.close();
	}
	return 0;
=======
        //Input text file
        std::ifstream file("textInput.txt");
        std::string line;
        std::string input;
        if (file.is_open())
        {
                //The file is looked at,line by line
                while (std::getline(file, line))
                {
                        for(const auto& item : line)
                        {
                                input += (char)(item + 3);
                        }
                        input += '\n';
                }
        }
        file.close();
        std::ofstream encodedfile("encodedText.txt");
        if(encodedfile.is_open())
        {
                encodedfile << input;
                encodedfile.close();
        }
        return 0;
>>>>>>> ce12194730bf8c3b89182bbf5a7517e133d05db2
}
