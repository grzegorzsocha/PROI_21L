#pragma once

class Person
{
private:
	std::string name;
public:
	Person();
	Person(std::string name);

	std::string getName();
	void setName();

	bool operator==(Person person);
	bool operator!=(Person person);
};
