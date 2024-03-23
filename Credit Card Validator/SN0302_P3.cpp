// ----------------------------------------------------------------------
// Student Number: 0302
// CS 155 - 01
// Due Date: 3/22/2024
// Resources: Zybooks, geeksforgeeks.org
// Description: This program will read credit card numbers
//				and will do a three step process of determining
//				the credit cards validity and will write invalid
//				cards to an invalid.csv file and will write valid
// 				cards to a valid.csv file. The three steps will be
// 				expiration date check, length and prefix check, and
// 				luhn's algorithm.
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string ccNum;
	string expDate, month, year;
	string line;
	string cardType;

	int commaLoc;
	int slashLoc;
	int sum;
	int cardLength;

	bool validLength = false;
	bool validDate = false;
	bool luhnValid = false;

	ifstream infile("payment.csv");
	ofstream invFile("invalid.csv");
	ofstream valFile("valid.csv");

	if (infile.fail()) {
		cout << "ERROR: PAYMENT FILE NOT FOUND" << endl;
	}

	if (invFile.fail()) {
		cout << "ERROR: INVALID FILE NOT FOUND" << endl;
	}

	if (valFile.fail()) {
		cout << "ERROR: VALID FILE NOT FOUND" << endl;
	}
	// Reading credit card information from payment.csv file
	while(getline(infile, line)) {

		// Extract Credit Card Number
		commaLoc = line.find(',');
		ccNum = line.substr(0, commaLoc);
		line.erase(0, commaLoc + 1);

		// Extract Expiration Date
		slashLoc = line.find('/');
		month = line.substr(0, slashLoc);
		line.erase(0, slashLoc + 1);

		year = line;

		// Validate Expiration Date
		int numMonth = stoi(month);
		int numYear = stoi(year);

		if (numMonth < 3 && numYear < 2024) {
			validDate = false;
		} else
			validDate = true;

		// Length Validation & type
		cardLength = ccNum.length();
		if (cardLength == 15 && (ccNum.substr(0, 2) == "34" || ccNum.substr(0, 2) == "37")) {
			cardType = "American Express";
			validLength = true;
		} else if ((cardLength == 13 || cardLength == 16) && ccNum[0] == '4') {
			cardType = "Visa";
			validLength = true;
		} else if (cardLength == 16 && ccNum.substr(0, 2) >= "51" && ccNum.substr(0, 2) <= "55") {
			cardType = "Mastercard";
			validLength = true;
		} else if (cardLength == 16 && ccNum.substr(0, 4) == "6011") {
			cardType = "Discover";
			validLength = true;
		} else if ((cardLength == 14 || cardLength == 16) && (ccNum.substr(0, 2) == "36" || ccNum.substr(0, 2) == "38")) {
			cardType = "Diners Club";
			validLength = true;
		} else if (cardLength >= 16 && ccNum.substr(0, 4) == "3528") {
			cardType = "JCB";
			validLength = true;
		} else {
			cardType = "Unknown card type";
			validLength = false;
		}

		// Luhn's Algorithm Validation
		sum = 0;
		bool doubleDigit = false;

		for (int i = ccNum.length() - 1; i >= 0; i--) {
			int digit = ccNum[i] - '0';

			if (doubleDigit) {
				digit *= 2;

				if (digit > 9) {
					digit = digit / 10 + digit % 10;
				}
			}

			sum += digit;
			doubleDigit = !doubleDigit;
		}

		luhnValid = (sum % 10 == 0);

		if (validLength && validDate && luhnValid) {
			valFile << ccNum << "/" << cardType << endl;
		} else {
			if (!validDate) {
				invFile << ccNum << ", " << "Expired" << endl;
			} else if (!validLength) {
				invFile << ccNum << ", " << "Failed Length Check" << endl;
			} else if (!luhnValid) {
				invFile << ccNum << ", " << "Failed Luhn's Algorithm" << endl;
			}
		}
	}

	infile.close();
	invFile.close();
	valFile.close();

	return 0;
}
