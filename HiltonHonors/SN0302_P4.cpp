// Student Number: 0302
// Course: CS155-03
// Due Date: 4/17/24
// Description: 



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayHotels();
int getHotelChoice();
bool readRoomPrices(int hotelChoice, string& hotelName, 
                    double& queen1Price, 
                    double& queen2Price, double& king1Price, 
                    double& king2Price, double& luxurySuite);
void displayRoomPrices(const string& hotelName, double queen1Price, double queen2Price,
                       double king1Price, double king2Price, double luxurySuite);
int getRoomChoice();
double getRoomCost(int roomType, double queen1Price, double queen2Price,
                   double king1Price, double king2Price, double luxurySuite);
int getNumRooms();
int getNumNights();
void addToOrder(int numNights, int numRooms, double roomCost, double& subtotal);
double calculateTaxes(double subtotal);



int main() {
    int selection;
    string hotelName;
    double queen1Price, queen2Price, king1Price, king2Price, luxurySuite;
    double roomCost;
    double subtotal = 0.0;

    do {
        displayHotels();
        selection = getHotelChoice();

        if (selection != 0) {
            if (!readRoomPrices(selection, hotelName, queen1Price, queen2Price, king1Price, king2Price, luxurySuite)) {
                cout << "Failed to read room prices. Exiting..." << endl;
                exit(1);
            }

            displayRoomPrices(hotelName, queen1Price, queen2Price, king1Price, king2Price, luxurySuite);

            int roomChoice = getRoomChoice();
            if (roomChoice != 0) {
                int numRooms = getNumRooms();
                int numNights = getNumNights();
                roomCost = getRoomCost(roomChoice, queen1Price, queen2Price, king1Price, king2Price, luxurySuite);
                addToOrder(numNights, numRooms, roomCost, subtotal);
                calculateTaxes(subtotal);
            }
        }
    } while (selection != 0);

    cout << endl << "Goodbye!" << endl;
    return 0;
}

void displayHotels(){
    cout << "WELCOME TO THE HILTON HONORS BOOKING SYSTEM!" << endl;
    cout << "Choose an option below:" << endl << endl;
    cout << "1. Embassy Suites" << endl;
    cout << "2. Hilton Garden" << endl;
    cout << "3. DoubleTree" << endl;
    cout << "0. End of the Day: Stop Processing" << endl << endl;
}

int getHotelChoice() {
    int choice;
    cout << "Enter the number of your selected hotel: ";
    cin >> choice;
    while (choice < 0 || choice > 3){
        cout << "INVALID CHOICE... PLEASE TRY AGAIN:" << endl;
        cout << "Enter the number of your selected hotel: ";
        cin >> choice;
    }
    return choice;
}

bool readRoomPrices(int hotelChoice, string& hotelName, 
                    double& queen1Price, 
                    double& queen2Price, double& king1Price, 
                    double& king2Price, double& luxurySuite) {
    string filename;
    switch (hotelChoice) {
        case 1:
            filename = "Embassy.txt";
            hotelName = "Embassy Suites";
            break;
        case 2:
            filename = "Hilton_Garden.txt";
            hotelName = "Hilton Garden";
            break;
        case 3:
            filename = "DoubleTree.txt";
            hotelName = "DoubleTree";
            break;
        default:
            cout << "Invalid hotel choice." << endl;
            return false;
    }
    ifstream inFile(filename);
    if (inFile.fail()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }
    inFile >> queen1Price >> queen2Price >> king1Price >> king2Price >> luxurySuite;
    inFile.close();
    return true;
}

void displayRoomPrices(const string& hotelName, double queen1Price, double queen2Price,
                       double king1Price, double king2Price, double luxurySuite) {
    cout << "Hotel: " << hotelName << endl;
    cout << "Room Prices:" << endl;
    cout << "1 - 1 Queen: $" << queen1Price << endl;
    cout << "2 - 2 Queens: $" << queen2Price << endl;
    cout << "3 - 1 King: $" << king1Price << endl;
    cout << "4 - 2 Kings: $" << king2Price << endl;
    cout << "5 - Luxury Suite: $" << luxurySuite << endl << endl;
}

int getRoomChoice(){
    int roomChoice;
    cout << "Enter the number of your selected room: ";
    cin >> roomChoice;
    while (roomChoice < 0 || roomChoice > 5){
        cout << "Error: Invalid Choice" << endl;
        cout << "Enter the number of your selected room: ";
        cin >> roomChoice;
    }
    return roomChoice;
}

double getRoomCost(int roomType, double queen1Price, double queen2Price,
                   double king1Price, double king2Price, double luxurySuite) {
    double roomCost = 0.0;
    switch(roomType) {
        case 1:
            roomCost = queen1Price;
            break;
        case 2:
            roomCost = queen2Price;
            break;
        case 3:
            roomCost = king1Price;
            break;
        case 4:
            roomCost = king2Price;
            break;
        case 5:
            roomCost = luxurySuite;
            break;
        default:
            cout << "Invalid room type selected." << endl;
    }
    return roomCost;
}

int getNumRooms(){
    int rooms;
    cout << "How many rooms will you need?: ";
    cin >> rooms;
    while (rooms < 1) {
        cout << "Please enter a valid number of rooms" << endl;
        cout << "How many rooms will you need?: ";
        cin >> rooms;
    }
    return rooms;
}

int getNumNights(){
    int nights;
    cout << "How many nights will you be staying?: ";
    cin >> nights;
    while (nights < 1) {
        cout << "Please enter a valid number of nights" << endl; 
        cout << "How many nights will you be staying?: ";
        cin >> nights;
    }
    return nights;
}

void addToOrder(int numNights, int numRooms, 
                double roomCost, double& subtotal) {
    double reservation = numNights * numRooms * roomCost;
    cout << "You have successfully booked the room(s) for " << numNights << " night(s)." << endl;
    cout << "Total Cost: $" << reservation << endl << endl;
    subtotal += reservation;
}

double calculateTaxes(double subtotal) {
	double taxDollarAmount;
	double salesTax = 0.04;
	
	taxDollarAmount = subtotal * salesTax;
	
	subtotal += taxDollarAmount;
	
	return subtotal;
}

