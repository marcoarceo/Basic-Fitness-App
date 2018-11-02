#pragma once
/*******************************************************************************************
* Programmer: Marco Arceo
* Class: CptS 122, Spring 2018; Lab Section
* Programming Assignment: PA4
* Due Date: Feb, 23rd, 2018
* Description: Basic Fitness Application in C++
* Sources: This portion was made using previous code, learncpp.com, and FIZ TA's
*******************************************************************************************/

#include <array>
#include <vector> // learncpp.com (An introduction to std::vector)
#include <Windows.h>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::vector;
using std::array;

class Wrapper
{
public:
	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018 (In Lab)
	* Description: Runs the app, provides a outline
	* Sources: Previous Main code from PA 4
	*******************************************************************************************/
	void runApp();

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018 (In Lab)
	* Description: Loads in one single day of the plan
	* Sources: Used code from the overload function
	*******************************************************************************************/
	void loadDailyPlan(fstream &file, DietPlan &plan); // Diet
	void loadDailyPlan(fstream &file, ExercisePlan &plan); // Exercise

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018 (In Lab)
	* Description: Loads all the daily plans into the vector, uses a for loop
	* Sources: Got help from Elijah Craig and used cplusplus.com to create the for loop
	*******************************************************************************************/
	void loadWeeklyPlan(fstream &file, vector<DietPlan> &plan); // Diet
	void loadWeeklyPlan(fstream &file, vector<ExercisePlan> &plan); // Exercise

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018 (In Lab)
	* Description: Displays one single plan
	* Sources: Used my understanding of arrays and manipulated it to create this
	*******************************************************************************************/
	void displayDailyPlan(int i, vector<DietPlan> &plan); // Diet
	void displayDailyPlan(int i, vector<ExercisePlan> &plan); // Exercise

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018 (In Lab)
	* Description: Displays the weekly plan
	* Sources: Created a new for loop that i got from stack overflow because my loop from 
			   loadingWeeklyPlan() wasnt working to iterate
	*******************************************************************************************/
	void displayWeeklyPlan(vector<DietPlan> &plan); // Diet
	void displayWeeklyPlan(vector<ExercisePlan> &plan); // Exercise

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018 (In Lab)
	* Description: Stores one single plan to the file
	* Sources: Used my understanding of writing to a file and manipulated the loadDailyPlan()
	*******************************************************************************************/
	void storeDailyPlan(fstream &file, DietPlan &plan); // Diet
	void storeDailyPlan(fstream &file, ExercisePlan &plan); // Exercise

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018
	* Description: Stores the weekly plan to the file
	* Sources: Used the for loop for displaying and called the storeDailyPlan()
	*******************************************************************************************/
	void storeWeeklyPlan(fstream &file, vector<DietPlan> &plan); // Diet
	void storeWeeklyPlan(fstream &file, vector<ExercisePlan> &plan); // Exercise

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 23rd, 2018
	* Description: Allows the user to edit one single plan
	* Sources: Used some ideas Elijah Craig gave me before the lab ended, it calls the editGoal member function
	*******************************************************************************************/
	void editDailyPlan(vector<DietPlan> &plan);
	void editDailyPlan(vector<ExercisePlan> &plan);

	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018
	* Description: Displays the menu and validates the users inputs
	* Sources: Previous Main code from PA 4
	*******************************************************************************************/
	void displayMenu();
	int getOption();
	int determineOption();

private:
	/*******************************************************************************************
	* Programmer: Marco Arceo
	* Date: Feb, 22nd, 2018
	* Description: Declares the vectors that will store the plans
	* Sources: Used TA code from Lab and used stackoverflow as well as learncpp.com for the vectors
	*******************************************************************************************/
	vector<DietPlan> weeklyDiet;
	vector<ExercisePlan> weeklyExercise;
	// array<DietPlan, 7> weeklyPlan;
	// array<ExercisePlan, 7> weeklyPlan
};
