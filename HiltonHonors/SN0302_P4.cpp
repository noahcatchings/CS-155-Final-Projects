// Student Number: 0302
// Course Section - CS155 - 03
// Due Date: x/x/xx
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
	double& king2Price, double&luxurySuite);
void displayRoomPrices(const string& hotelName, double queen1Price, double queen2Price,
                       double king1Price, double king2Price, double luxurySuite);
int getRoomChoice();
double getRoomCost(int roomType, double queen1Price, double queen2Price,
                   double king1Price, double king2Price, double luxurySuite);
void printReceipt(const string& hotelName, int numRooms, int numNights,
    double roomPrice, double subtotal, double taxFee, ofstream& outputFile);

int main() {
	int selection;
	int roomNum;
	int roomChoice;
	string hotelName;
    double queen1Price, queen2Price, king1Price, king2Price, luxurySuite;
    
    
	displayHotels();
	selection = getHotelChoice();
	
	if (!readRoomPrices(selection, hotelName, queen1Price, queen2Price, king1Price, king2Price, luxurySuite)) {
        cout << "Failed to read room prices. Exiting..." << endl;
        exit(1);
    }
    
    displayRoomPrices(hotelName, queen1Price, queen2Price, king1Price, king2Price, luxurySuite);
    
    roomChoice = getRoomChoice();
	do{
		switch(roomChoice){
			case 1: 
				double getRoomCost(int roomType, double queen1Price, double queen2Price,
                   double king1Price, double king2Price, double luxurySuite);
				break;
			case 2:
				double getRoomCost(int roomType, double queen1Price, double queen2Price,
                double king1Price, double king2Price, double luxurySuite);
				break;
			case 3: 
				double getRoomCost(int roomType, double queen1Price, double queen2Price,
                double king1Price, double king2Price, double luxurySuite);
				break;
			case 4:
				double getRoomCost(int roomType, double queen1Price, double queen2Price,
                double king1Price, double king2Price, double luxurySuite);
				break;
			case 5:
				double getRoomCost(int roomType, double queen1Price, double queen2Price,
                double king1Price, double king2Price, double luxurySuite);
				break;
			case 0:
				cout << "Goodbye!" << endl;
				exit(1);
			default:
				cout << "Invalid Choice. Please Try Again" << endl;
				exit(1);
			}
		} while(roomChoice != 0);
			
		
	
	return 0;
}

void displayHotels(){
	int choice; 
	
	cout << "WELCOME TO THE HILTON HONORS BOOKING SYSTEM!" << endl;
	cout << "Choose an option below:" << endl << endl;
	
	cout << "1. Embassy Suites" << endl;
	cout << "2. Hilton Garden" << endl;
	cout << "3. DoubleTree" << endl;
	cout << "0. End of the Day: Stop Processing" << endl;
	
	cout << endl;
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
    cout << "5 - Luxury Suite: $" << luxurySuite << endl;
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
	
void printReceipt(const string& hotelName, int numRooms, int numNights,
                  double roomPrice, double subtotal, double taxFee, ofstream& outputFile) {
                  	
    double totalAmount = subtotal + taxFee;
    ofstream outFile("OutNDC.txt"); 
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file " << outputFile << endl;
        exit(1);
    }
        
    double totalAmount = subtotal + taxFee;
    outFile << "Hotel Name: " << hotelName << endl;
    outFile << "Number of Rooms: " << numRooms << endl;
    outFile << "Number of Nights: " << numNights << endl;
    outFile << "Room Price: $" << roomPrice << endl;
    outFile << "Subtotal: $" << subtotal << endl;
    outFile << "Tax Fee: $" << taxFee << endl;
    outFile << "Total Amount: $" << totalAmount << endl;
    outFile.close();
}
	
	
			
