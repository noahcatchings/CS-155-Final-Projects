//---------------------------
// SN0302
// CS 155 - 01
// Project 1
// Date Due: 02/14/24
// Resources: Zybook and ASCII Table Website (https://www.asciitable.com/)
// Description - This Program will convert the 
//               given binary number to a Decimal Number
//               as well as the character representation 
//               for the decimal value.
//---------------------------

#include <iostream>
#include <cmath>
using namespace std;

const string STARS = "***************************************";
const int BASE = 2;

int main(){
    int binNum;
    int enteredNum;
    int decNum = 0;
    char charRep;
    int powNum;
    int power = 0;

    cout << "Enter a single 8-bit binary number:" << endl;
    cin >> binNum;
    enteredNum = binNum;
    
    
    powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;						// Dividing the binary number by 10
    power++;							// allows us to remove the last digit
										// each Iteration.
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;			
    power++;                           // power++ raises the exponent by 1
	                                   // after last digit is removed.
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;			
    power++;
	
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;			
    power++;
	
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;			
    power++;
	
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;			
    power++;
	
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;			
    power++;
	
	powNum = binNum % 10;
    decNum += pow(BASE, power) * powNum;		
    binNum /= 10;	
				      				  // Since the char data type stays a character, I
	charRep = decNum;			      // initialize the character with the			
                                      // cooresponding ASCII value (decNum). 
                                  
    cout << STARS << endl;
    cout << "Binary Representation: " << "\t\t" << enteredNum << endl;
    cout << "Decimal Representation: " << "\t" << decNum << endl;
    cout << "Character Representation: " << "\t" << charRep << endl;
    cout << STARS << endl;

    return 0;
}
