// ----------------------------------
// This program will read an input of prerequisites
// from the user to determine their classes for the
// following semester based on the given input
// ----------------------------------

#include <iostream>
using namespace std;
const string STARS = "************************";

int main() {
	char ans;
	int csAns = 0;
	int maAns = 0;
	char semester;
	int actScore;
	int year;
	bool cs101_135 = false;
	bool cs155 = false;
	bool cs245 = false;
	bool cs255 = false;
	bool cs355 = false;
	bool cs315 = false;
	bool cs325 = false;
	bool ma112 = false;
	bool ma113 = false;
	bool ma125 = false;
	bool ma126 = false;
	bool ma331 = false;
	bool ma110 = false;

	cout << STARS << endl << endl;
	cout << "Welcome to Semester Strategist 1.0!" << endl << endl;
	cout << "Have you taken any CS Courses? (Y or N): ";
	cin >> ans;

	if (toupper(ans) == 'Y') {
		cout << "Enter the highest level CS course you have taken: ";
		cin >> csAns;
	}

	// Condition if CS class does not exist
	while ((csAns != 0 && csAns != 101 && csAns != 135 && csAns != 155) &&
	        (csAns != 245 && csAns != 255 && csAns != 315) &&
	        (csAns != 325 && csAns != 355)) {
		cout << "Please enter a valid CS Course: " << endl << endl;
		cout << "Enter the highest level CS Course you have taken: ";
		cin >> csAns;
		cout << endl;
	}


	cout << "Have you taken any Math Courses? (Y or N): ";
	cin >> ans;

	if(toupper(ans) == 'Y') {
		cout << "Enter the highest level Math Course you have taken: ";
		cin >> maAns;
	}

	// Condition if Math class does not exist
	while ((maAns != 0 && maAns != 110 && maAns != 112 && maAns != 113) && 
		  (maAns != 115 && maAns != 125 && maAns != 126) && 
		  (maAns != 331 && maAns != 325)) {
		cout << "Please enter a valid Math Course: " << endl << endl;
		cout << "Enter the highest level Math Course you have taken: ";
		cin >> maAns;
		cout << endl;
	}
	
	cout << "Enter your ACT Score: ";
	cin >> actScore;
	
	// Condition if ACT Score is Invalid
	if (actScore < 1 || actScore > 36) {
		cout << "Error: Please Enter a score in the range of 1-36" << endl;
		cout << endl;
		cout << "Enter your ACT Score: ";
		cin >> actScore;
	}

	cout << "Enter the upcoming semester (S for Spring, M for Summer, F for Fall) ";
	cin >> semester;
	semester = toupper(semester);

	// Condition if semester is invalid
	while (toupper(semester) != 'F' && toupper(semester) != 'M' && toupper(semester) != 'S') {
		cout << "Invalid Semester. Please try again. " << endl;
		cout << "Enter the upcoming semester (S for Spring, M for Summer, F for Fall) ";
		cin >> semester;
	}

	cout << "Enter the year of the enrolling semester: ";
	cin >> year;
	

	// CS Course Cases:

	// CS155 Case:
	if ((csAns == 101 || csAns == 135) && (maAns >= 112)) {
		cs155 = true;
	} else if (csAns == 0 && (maAns >= 125 || actScore >= 28)) {
		cs155 = true;
	}

	// CS 245 Case:
	if (csAns == 155 || csAns == 255 || csAns == 355)
		cs245 = true;
	else if (csAns == 0 && maAns == 112)
		cs245 = true;

	// CS 255 Case:
	if (csAns == 155) {
		cs255 = true;
	}

	// CS 355 Case:
	if (csAns == 255 && semester != 'S') {
		cs355 = true;
	}

	// CS 315 Case:
	if (csAns == 255 && semester == 'S' && year % 2 == 0) {
		cs315 = true;
	}

	// CS 325 Case:
	if (csAns == 255 && (semester == 'F' && (year % 2 == 1)))
		cs325 = true;

	// CS 101/135 Case:
	if (!cs155 && !cs245 && !cs255 && !cs355 && !cs315 && !cs325) {
		cs101_135 = true;
	}

	// MA Course Cases:

	//MA 112 Case:
	if (maAns == 110 || (maAns == 0 && actScore >= 22)) {
		ma112 = true;
	}
	// MA 113 Case:
	if (maAns == 112)
		ma113 = true;
	else if (maAns == 0 && actScore >=25 && actScore < 28)
		ma113 = true;

	// MA 125 Case:
	if (maAns == 113 || maAns == 115 || (actScore >= 28) && (semester != 'S')) {
		ma125 = true;

	// MA 126 Case:
	}
	if (maAns == 125 && semester != 'S') {
		ma126 = true;

	//MA 331 Case:
	}
	if (maAns >= 126 && (csAns == 245 || maAns == 325) && semester != 'S') {
		ma331 = true;
	}

	// MA 110 Case:
	
	if (!ma112 && !ma113 && !ma125 && !ma126 && !ma331)
		ma110 = true;

	// If the course evaluated to true it will output
	cout << endl << "Eligible CS Courses:" << endl;
	
	if (cs155)
		cout << "CS 155" << endl;

	if (cs245)
		cout << "CS 245" << endl;

	if (cs255)
		cout << "CS 255" << endl;

	if (cs325)
		cout << "CS 325" << endl;

	if (cs355)
		cout << "CS 355" << endl;

	if (cs315)
		cout << "CS 315" << endl;

	if (cs101_135)
		cout << "CS 101 or 135" << endl;

	cout << endl << "Eligible Math Courses:" << endl;
	
	if (ma112) {
		cout << "MA 112" << endl;
	}
	if (ma113) {
		cout << "MA 113" << endl;
	}
	if (ma125) {
		cout << "MA 125" << endl;
	}
	if (ma126) {
		cout << "MA 126" << endl;
	}
	if (ma331) {
		cout << "MA 331" << endl;
	}
	if (ma110) {
		cout << "MA 110" << endl;
	}

	return 0;
}
