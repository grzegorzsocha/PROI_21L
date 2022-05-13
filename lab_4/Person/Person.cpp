#include <string>
#include "Person.h"

Person::Person()
{
	name = "";
}

Person::Person(std::string name)
{
	this->name = name;
}

std::string Person::getName()
{
	return name;
}

void Person::setName()
{
	this->name = name;
}

bool Person::operator==(Person person)
{
	if (name == person.getName())
		return true;
	return false;
}

bool Person::operator!=(Person person)
{
	if (name != person.getName())
		return true;
	return false;
}
