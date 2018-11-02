#pragma once
/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA4
* Due Date: Feb, 23rd, 2018
* Description: Basic Fitness Application in C++
* Sources: This header file was inspired by O'Fallons Bank Program and I got help from Alissa Horst
		   for the stream overloads
*******************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class DietPlan
{
public:
	DietPlan(int newCalories = 0, string newName = "", string newDate = "");
	DietPlan(const DietPlan &copyDietPlan);
	~DietPlan();

	DietPlan & operator= (const DietPlan &rhs);

	// getters / accessors
	int getCalories() const;
	string getName() const;
	string getDate() const;

	// setters / mutators
	void setCalories(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();

private:
	int m_calories;
	string m_name;
	string m_date;
};

// Alissa Horst helped me create these in the FIZ
std::ostream & operator << (std::ostream &lhs, DietPlan &rhs); // Displays to screen
std::fstream & operator << (std::fstream &lhs, DietPlan &rhs); // Writes to the file
std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs); // Reads in from file