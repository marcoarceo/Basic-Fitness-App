#include "DietPlan.h"

DietPlan::DietPlan(int newCalories, string newName, string newDate)
{
	m_calories = newCalories;
	m_name = newName;
	m_date = newDate;
}

DietPlan::DietPlan(const DietPlan &copyDietPlan)
{
	m_calories = copyDietPlan.getCalories();
	m_name = copyDietPlan.getName();
	m_date = copyDietPlan.getDate();
}

DietPlan::~DietPlan()
{
	// Plan is not created using dynamic memory
}

DietPlan & DietPlan::operator= (const DietPlan &rhs)
{ 
	if (this != &rhs)
	{
		m_calories = rhs.getCalories();
		m_name = rhs.getName();
		m_date = rhs.getDate();
	}

	return *this;
}

////////////////////////////////////////////////////////////////////////////////
int DietPlan::getCalories() const
{
	return m_calories;
}

string DietPlan::getName() const
{
	return m_name;
}

string DietPlan::getDate() const
{
	return m_date;
}
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

void DietPlan::setCalories(int newCalories)
{
	m_calories = newCalories;
}

void DietPlan::setName(string newName)
{
	m_name = newName;
}
void DietPlan::setDate(string newDate)
{
	m_date = newDate;
}
///////////////////////////////////////////////////////////////////////////////

void DietPlan::editGoal()
{
	int newCalories;

	cout << "Enter your new calorie goal: " << endl;
	cin >> newCalories;
	setCalories(newCalories);
}

std::ostream & operator << (std::ostream &lhs, DietPlan &rhs) // Displays to screen
{
	lhs << "Plan: " << rhs.getName() << endl;
	lhs << "Calorie Goal: " << rhs.getCalories() << endl;
	lhs << "Date: " << rhs.getDate() << endl;

	return lhs;
}

std::fstream & operator << (std::fstream &lhs, DietPlan &rhs) // Writes to the file
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs) // Reads in from file
{
	string name = "", date = "";
	int calories = 0;

	lhs >> name;
	rhs.setName(name);

	lhs >> calories;
	rhs.setCalories(calories);

	lhs >> date;
	rhs.setDate(date);

	return lhs;
}