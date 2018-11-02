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

class ExercisePlan
{
public:
	ExercisePlan(int newSteps = 0, string newName = "", string newDate = "");
	ExercisePlan(const ExercisePlan &copyExercisePlan);
	~ExercisePlan();

	ExercisePlan & operator= (const ExercisePlan &rhs);

	// getters / accessors
	int getSteps() const;
	string getName() const;
	string getDate() const;

	// setters / mutators
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();

private:
	int m_steps;
	string m_name;
	string m_date;
};

// Alissa Horst helped me create these in the FIZ
std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs); // Displays to screen
std::fstream & operator << (std::fstream &lhs, ExercisePlan &rhs); // Writes to the file
std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs); // Reads in from file