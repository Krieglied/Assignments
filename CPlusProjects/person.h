//Performance Lab 3A
//Robert John Graham III
//August 10, 2018

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Person 
{
private:
	std::string fname, lname, gender;
	int age;
public:
	Person(std::string f, std::string l, int a, std::string g)
	{
		fname = f;
		lname = l;
		age = a;
		gender = g;
	}
	~Person()
	{
	}
	void setFname(std::string f)
	{
		fname = f;
	}
	void setLname(std::string l)
	{
		lname = l;
	}
	void setAge(int a)
	{
		age = a;
	}
	void setGender(std::string g)
	{
		gender = g;
	}
	std::string getFname()
	{
		return fname;
	}
	std::string getLname()
	{
		return lname;
	}
	int getAge()
	{
		return age;
	}
	std::string getGender()
	{
		return gender;
	}
};
