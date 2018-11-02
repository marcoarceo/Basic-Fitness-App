#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(int newSteps, string newName, string newDate)
{
	m_steps = newSteps;
	m_name = newName;
	m_date = newDate;
}

// Ask how to make copy
ExercisePlan::ExercisePlan(const ExercisePlan &copyExercisePlan)
{
	m_steps = copyExercisePlan.getSteps();
	m_name = copyExercisePlan.getName();
	m_date = copyExercisePlan.getDate();
}

ExercisePlan::~ExercisePlan()
{
	// Plan is not created using dynamic memory
}

ExercisePlan & ExercisePlan::operator= (const ExercisePlan &rhs)
{
	if (this != &rhs)
	{
		m_steps = rhs.getSteps();
		m_name = rhs.getName();
		m_date = rhs.getDate();
	}

	return *this;
}

////////////////////////////////////////////////////////////////////////////////
int ExercisePlan::getSteps() const
{
	return m_steps;
}

string ExercisePlan::getName() const
{
	return m_name;
}

string ExercisePlan::getDate() const
{
	return m_date;
}
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

void ExercisePlan::setSteps(int newSteps)
{
	m_steps = newSteps;
}

void ExercisePlan::setName(string newName)
{
	m_name = newName;
}
void ExercisePlan::setDate(string newDate)
{
	m_date = newDate;
}
////////////////////////////////////////////////////////////////////////////////

void ExercisePlan::editGoal()
{
	int newSteps;

	cout << "Enter your new step goal: " << endl;
	cin >> newSteps;
	setSteps(newSteps);
}

std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs) // Displays to screen
{
	lhs << "Plan: " << rhs.getName() << endl;
	lhs << "Step Goal: " << rhs.getSteps() << endl;
	lhs << "Date: " << rhs.getDate() << endl;

	return lhs;
}

std::fstream & operator << (std::fstream &lhs, ExercisePlan &rhs) // Writes to the file
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs) // Reads in from file
{
	string name = "", date = "";
	int steps = 0;

	lhs >> name;
	rhs.setName(name);

	lhs >> steps;
	rhs.setSteps(steps);

	lhs >> date;
	rhs.setDate(date);

	return lhs;
}