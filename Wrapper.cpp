#include "Wrapper.h"

void Wrapper::runApp()
{ // Implemented my main function from the previous PA
	bool flag = true;
	int option = 0;
	fstream dietplan, exerciseplan;

	while (flag)
	{
		do
		{
			cout << "Make sure to load both plans before closing!\n" << endl;
			option = determineOption();
			switch (option)
			{
			case 1:
				// Loads the weekly plan for the Diet
				dietplan.open("DietPlan.txt");
				loadWeeklyPlan(dietplan, weeklyDiet);
				dietplan.close();
				break;

			case 2:
				// Loads the weekly plan for the Exercise
				exerciseplan.open("ExercisePlan.txt");
				loadWeeklyPlan(exerciseplan, weeklyExercise);
				exerciseplan.close();
				break;

			case 3:
				// Stores the weekly plan for the Diet
				dietplan.open("DietPlan.txt");
				storeWeeklyPlan(dietplan, weeklyDiet);
				dietplan.close();
				break;

			case 4:
				// Stores the weekly plan for the Exercise
				exerciseplan.open("ExercisePlan.txt");
				storeWeeklyPlan(exerciseplan, weeklyExercise);
				exerciseplan.close();
				break;

			case 5:
				// Displays the weekly plan for the Diet
				displayWeeklyPlan(weeklyDiet);
				break;

			case 6:
				// Displays the weekly plan for the Exercise
				displayWeeklyPlan(weeklyExercise);
				break;

			case 7 :
				// Edits the weekly plan for the Diet
				editDailyPlan(weeklyDiet);
				break;

			case 8:
				// Edits the weekly plan for the Exercise
				editDailyPlan(weeklyExercise);
				break;

			case 9:
				// Stores all the information before closing the program
				dietplan.open("DietPlan.txt");
				storeWeeklyPlan(dietplan, weeklyDiet);
				dietplan.close();
				exerciseplan.open("ExercisePlan.txt");
				storeWeeklyPlan(exerciseplan, weeklyExercise);
				exerciseplan.close();
				cout << "Good bye!" << endl;
				Sleep(2000);
				flag = false;
				break;
			}
			system("cls");
		} while (option > 0 && option < 9);
	}
}

void Wrapper::loadDailyPlan(fstream &file, DietPlan &plan)
{ // Implemented a similar idea to the overstream function

	if (file.is_open())
	{
		file >> plan;
	}
}

void Wrapper::loadDailyPlan(fstream &file, ExercisePlan &plan)
{ // Implemented a similar idea to the overstream function

	if (file.is_open())
	{
		file >> plan;
	}
}

void Wrapper::loadWeeklyPlan(fstream &file, vector<DietPlan> &plan)
{ // Calls the loadDailyPlan into a for loop to populate the vector

	DietPlan temp;
	if (file.is_open())
	{
		for (int i = 0; weeklyDiet.size() < 7; i++) // cplusplus.com, also Elijah Craig
		{
			loadDailyPlan(file, temp);
			this->weeklyDiet.push_back(temp);
			// cout << weeklyDiet[i] << endl;
			// Sleep(2000);
		}
		cout << "Your Weekly Diet Plan has successfully loaded..." << endl;
		Sleep(3000);
	}
	else
	{
		cout << "The file was unable to be accessed, may be closed or empty." << endl;
	}
}

void Wrapper::loadWeeklyPlan(fstream &file, vector<ExercisePlan> &plan)
{ // Calls the loadDailyPlan into a for loop to populate the vector

	ExercisePlan temp;
	if (file.is_open())
	{
		for (int i = 0; weeklyExercise.size() < 7; i++) // cplusplus.com, also Elijah Craig
		{
			loadDailyPlan(file, temp);
			this->weeklyExercise.push_back(temp);
			// cout << weeklyExercise[i] << endl;
			// Sleep(2000);
		}
		cout << "Your Weekly Exercise Plan has successfully loaded..." << endl;
		Sleep(3000);
	}
	else
	{
		cout << "The file was unable to be accessed, may be closed or empty." << endl;
	}
}

void Wrapper::storeDailyPlan(fstream &file, DietPlan &plan)
{ // Implemented similar code to the overstream operator

	if (file.is_open())
	{
		file << plan;
		file << "\n";
	}
}

void Wrapper::storeDailyPlan(fstream &file, ExercisePlan &plan)
{ // Implemented similar code to the overstream operator

	if (file.is_open())
	{
		file << plan;
		file << "\n";
	}
}

void Wrapper::storeWeeklyPlan(fstream &file, vector<DietPlan> &plan)
{ // Calls the storeDailyPlan into a for loop to store it to the file

	if (file.is_open())
	{
		for (auto i : weeklyDiet) // Stack Overflow, my for loop for loading wouldnt work
		{
			storeDailyPlan(file, i);
			//cout << i << endl;
			//Sleep(2000);
		}
		cout << "Your Weekly Diet Plan has successfully stored..." << endl;
		Sleep(3000);
	}
}

void Wrapper::storeWeeklyPlan(fstream &file, vector<ExercisePlan> &plan)
{ // Calls the storeDailyPlan into a for loop to store it to the file

	if (file.is_open())
	{
		for (auto i  : weeklyExercise) // Stack Overflow, my for loop for loading wouldnt work
		{
			storeDailyPlan(file, i);
			//cout << i << endl;
			//Sleep(2000);
		}
		cout << "Your Weekly Exercise Plan has successfully stored..." << endl;
		Sleep(3000);
	}
}

void Wrapper::displayDailyPlan(int i, vector<DietPlan> &plan)
{ // Used my understanding of c++ and arrays 

	cout << weeklyDiet[i] << endl;
}

void Wrapper::displayDailyPlan(int i, vector<ExercisePlan> &plan)
{ // Used my understanding of c++ and arrays

	cout << weeklyExercise[i] << endl;
}

void Wrapper::displayWeeklyPlan(vector<DietPlan> &plan)
{ // Calls the displayDailyPlan into a for loop to display the plan

	int index = 0;
	for (auto i : weeklyDiet) // Same for loop as above
	{
		displayDailyPlan(index, weeklyDiet);
		index++;
		Sleep(2000);
	}
	cout << "That was your Exercise Plan for the week..." << endl;
	Sleep(3000);
}

void Wrapper::displayWeeklyPlan(vector<ExercisePlan> &plan)
{ // Calls the displayDailyPlan into a for loop to display the plan

	int index = 0;

	for (auto i : weeklyExercise) // Same for loop as above
	{
		displayDailyPlan(index, weeklyExercise);
		index++;
		Sleep(2000);
	}
	cout << "That was your Exercise Plan for the week..." << endl;
	Sleep(3000);
}

void Wrapper::editDailyPlan(vector<DietPlan> &plan)
{ // Lets the user choose a day and calls the editGoal member function

	int choice = 0;

	cout << "1.) Monday" << endl;
	cout << "2.) Tuesday" << endl;
	cout << "3.) Wednesday" << endl;
	cout << "4.) Thursday" << endl;
	cout << "5.) Friday" << endl;
	cout << "6.) Saturday" << endl;
	cout << "7.) Sunday\n" << endl;

	do
	{
		cout << "Enter the numerical value for the day you wish to edit: " << endl;
		cin >> choice;
		system("cls");
	} while (choice < 1 || choice > 8);

	weeklyDiet[choice - 1].editGoal();
	cout << "The change has been made to your weekly Diet plan..." << endl;
	Sleep(3000);
}

void Wrapper::editDailyPlan(vector<ExercisePlan> &plan)
{ // Lets the user choose a day and calls the editGoal member function

	int choice = 0;

	cout << "1.) Monday" << endl;
	cout << "2.) Tuesday" << endl;
	cout << "3.) Wednesday" << endl;
	cout << "4.) Thursday" << endl;
	cout << "5.) Friday" << endl;
	cout << "6.) Saturday" << endl;
	cout << "7.) Sunday\n" << endl;

	do
	{
		cout << "Enter the numerical value for the day you wish to edit: " << endl;
		cin >> choice;
		system("cls");
	} while (choice < 1 || choice > 8);

	weeklyExercise[choice - 1].editGoal();
	cout << "The change has been made to your weekly Exercise plan..." << endl;
	Sleep(3000);
}

void Wrapper::displayMenu()
{ // Displays the menu
	cout << "1.) Load Weekly Diet Plan" << endl;
	cout << "2.) Load Weekly Exercise Plan" << endl;
	cout << "3.) Store Weekly Diet Plan" << endl;
	cout << "4.) Store Weekly Exercise Plan" << endl;
	cout << "5.) Display Weekly Diet Plan" << endl;
	cout << "6.) Display Weekly Exercise Plan" << endl;
	cout << "7.) Edit Daily Diet Plan" << endl;
	cout << "8.) Edit Daily Exercise Plan" << endl;
	cout << "9.) Exit Program" << endl;
}

int Wrapper::getOption()
{ // Gets the users option
	int option = 0, status = 0;
	cout << "\nEnter your option: " << endl;
	cin >> option;
	status = option;
	if (status = 0)
	{
		cout << "Failed at reading the option" << endl;
	}
	return option;
}

int Wrapper::determineOption()
{ // Determines if the option is valid
	int option = 0;

	do
	{
		displayMenu();
		option = getOption();
		system("cls");
	} while ((option < 1) || (option > 9));

	return option;
}