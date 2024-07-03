#pragma once

#include <iostream>
#include <string>

class PersonID
{
private:
	int number;
	int series;
public:
	int GetSeries() const
	{
		return this->series;
	}
	int GetNumber() const
	{
		return this->number;
	}
	std::string GetID() const
	{
		return std::to_string(series) + " " + std::to_string(number);
	}
};

class Person
{
private:
	PersonID personID{};
	std::string firstName = "";
	std::string secondName = "";
	std::string thirdName = "";
	std::string birthDay = "";
public:
	Person()
	{
	}
	Person(std::string firstName, std::string secondName, std::string thirdName, std::string birthDay)
	{
		this->firstName = firstName;
		this->secondName = secondName;
		this->thirdName = thirdName;
		this->birthDay = birthDay;
	}
	Person(std::string firstName, std::string secondName, std::string birthDay)
	{
		this->firstName = firstName;
		this->secondName = secondName;
		this->birthDay = birthDay;
	}
	Person(std::string firstName, std::string secondName)
	{
		this->firstName = firstName;
		this->secondName = secondName;
	}
	Person(const Person& other)
	{
		this->firstName = other.firstName;
		this->secondName = other.secondName;
	}
	std::string GetID() const
	{
		return personID.GetID();
	}
	int GetSeries() const
	{
		return personID.GetSeries();
	}
	int GetNumber() const
	{
		return personID.GetNumber();
	}
	std::string GetFullName() const
	{
		return this->firstName + " " + this->secondName + " " +this->thirdName;
	}
	std::string GetFirstName() const
	{
		return this->firstName;
	}
	std::string GetSecondName() const
	{
		return this->secondName;
	}
	Person operator+(const Person& other)
	{
		Person result(*this);
		result.firstName += other.firstName;
		result.secondName += other.secondName;
		result.thirdName += other.thirdName;
		result.birthDay += other.birthDay;
		return result;
	}
	bool operator == (const Person& other)
	{
		if (this->firstName == other.firstName && this->secondName == other.secondName && this->thirdName == other.thirdName && this->birthDay == other.thirdName)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend std::ostream& operator << (std::ostream& os, const Person& person)
	{
		if (person.thirdName == "" && person.birthDay == "")
		{
			os << person.firstName << " " << person.secondName;
		}
		else if (person.thirdName == "")
		{
			os << person.firstName << " " << person.secondName << " " << person.birthDay;
		}
		else
		{
			os << person.firstName << " " << person.secondName << " " << person.thirdName << " " << person.birthDay;
		}
		os << "ID: " << person.GetID();
		return os;
	}
	friend std::istream& operator >> (std::istream& is, Person& person)
	{
		if (person.firstName != "")
		{
			return is;
		}
		std::cout << "\nFirst name: ";
		is >> person.firstName;
		std::cout << "\nSecond name: ";
		is >> person.secondName;
		std::cout << "\nBirthDay: ";
		is >> person.birthDay;
		return is;
	}
};