/*
* Name: Kevin Patchett
* Date: 4/21/2023
* Code: Case Study Group 4
* Version: 3.0
*/

// Calling libraries
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>

// Calling namespace as standard
using namespace std;

// Color Functions
void red() { printf("\033[1;31m"); }
void green() { printf("\033[1;32m"); }
void yellow() { printf("\033[1;33m"); }
void blue() { printf("\033[1;34m"); }
void purple() { printf("\033[1;35m"); }
void cyan() { printf("\033[1;36m"); }
void white() { printf("\033[1;37m"); }
void reset() { printf("\033[1;0m"); }

//Local Functions
void menu();
void submenu(int);
void xml_display(string, string);

// Global Variables
char menu_opt, submenu_opt;
ifstream file1, file2, file3, file4, file5, file_a1, file_a2, file_a3, file_a4, file_a5; // File and file_a are used for opening and reading files
int src_time; // Source time 
int c = 1; // ID counter
int label_1a, label_1b, label_1c, label_1d, label_1e;
string word; // FlightID's global variable
string flt_id; // FlightID
string comp_id; // computerID
string displayComp; // computerID's global variable
string text1, text2, text3, text4, text5, text_a1, text_a2, text_a3, text_a4, text_a5; // Used to convert text files into strings for displaying purposes
string label_2a, label_2b, label_2c, label_2d, label_2e;

class DataValidation {
	/*
	* Data Validation Class
	* Uses to make sure that the data the user has entered in is correct
	*/
private:
	int id;
public:
	DataValidation(int);
	virtual void test();
	virtual int get();
};

class ValidationSource : public DataValidation {
	/*
	* Polymorphed Class of Data Validation, used to handle the source time field of the information that the user has entered
	*/
private:
	int srcTime;
public:
	ValidationSource(int, int);
	int get_srcTime();
	void set_srcTime(int);
	void test();

};

class ValidationFlightID : public DataValidation {
	/*
	* Polymorphed Clsas of Data Validation, used to handle the flight ID field of the information that the user has entered
	*/
private:
	string flightID;
public:
	ValidationFlightID(int, string);
	string get_flightID();
	void set_flightID(string);
	void test();

};

class ValidationComputerID : public DataValidation {
	/*
	* Polymoprhed Class of Data Validation used to the handle the computer Id field of the information that he user has entered
	*/
private:
	string computerID;
public:
	ValidationComputerID(int, string);
	string get_computerID();
	void set_computerID(string);
	void test();

};

DataValidation::DataValidation(int _id) {
	/*
	* This function accepts an int as an argument
	* Constructor for Data Validation. Used to keep track of the times that the user has made a submimisson into the datavalidation field.
	* This function returns nothing
	*/
	id = _id;
}

void DataValidation::test() {
	/*
	* This function does not accept any arguments
	* This function checks to see that the id of datavalidation is consistent with the amount of times that a data validation class has been created
	*/
	if (c != id) {
		red();
		cout << "Something has gone wrong";
	}
	reset();
}

int DataValidation::get() {
	/*
	* This function does not accept any arguments
	* This function returns the id
	*/
	return id;
}

ValidationSource::ValidationSource(int _id, int _srcTime) : DataValidation(_id) {
	/*
	* This function accepts the id, and the source time from the information given. Datavalidation does the id for you
	* Polymorphed Class of data validation. Takes accepted arguements and applies to the private field.
	* This function does not return anything
	*/
	srcTime = _srcTime;
}

int ValidationSource::get_srcTime() {
	/*
	* This function accepts no arguments
	* This function returns source time
	*/
	return srcTime;
}

void ValidationSource::set_srcTime(int _srcTime) {
	/*
	* This function accepts an int to use as source time.
	* This function does not return anything
	*/
	srcTime = _srcTime;
}

void ValidationSource::test() {
	/*
	* This overloaded function does not accept any arguments
	* This function tests the srcTime based on the parameters given to us and returns the message depending on the outcome of the test.
	* This function returns nothing.
	*/
	if ((srcTime > 0) && (srcTime <= 235959)) {

		blue();
		cout << "data.............................................................OK" << endl;
		reset();
	}
	else {
		src_time = 0;
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
}

ValidationFlightID::ValidationFlightID(int _id, string _flightID) : DataValidation(_id) {
	/*
	* Accepts an int and a string
	* This polymorphed function works for the flight id, acceping an int and a string. 
	* This function returns nothing
	*/
	flightID = _flightID;
}

string ValidationFlightID::get_flightID() {
	/*
	* This function does not accept any arguments
	* This function returns flight id
	*/
	return flightID;
}

void ValidationFlightID::set_flightID(string _flightID) {
	/*
	* This function accepts a string to assign to the flight id field.
	* This function does not return anything
	*/
	flightID = _flightID;
}

void ValidationFlightID::test() {
	/*
	* This overloaded function does not accept anything
	* This function checks the flight id and returns if it was correct or incorrect
	* This function does not return anything
	*/

	DataValidation::test();
	string firstLetter;

	word = flightID;
	firstLetter = flightID.at(0);
	if ((firstLetter == "A") || (firstLetter == "B") || (firstLetter == "C") || (firstLetter == "D") || (firstLetter == "E") || (firstLetter == "F")
		|| (firstLetter == "G") || (firstLetter == "H") || (firstLetter == "I") || (firstLetter == "J") || (firstLetter == "K") || (firstLetter == "L")
		|| (firstLetter == "M") || (firstLetter == "N") || (firstLetter == "O") || (firstLetter == "P") || (firstLetter == "Q") || (firstLetter == "R")
		|| (firstLetter == "S") || (firstLetter == "T") || (firstLetter == "U") || (firstLetter == "V") || (firstLetter == "W") || (firstLetter == "X")
		|| (firstLetter == "Y") || (firstLetter == "Z")) {
		blue();
		cout << "data.............................................................OK" << endl;
		reset();
	}
	else {
		word = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	};
}

ValidationComputerID::ValidationComputerID(int _id, string _computerID) : DataValidation(_id) {
	/*
	* Accepts an int and a string
	* This polymorphed function works for the flight id, acceping an int and a string.
	* This function returns nothing
	*/
	computerID = _computerID;
}

string ValidationComputerID::get_computerID() {
	/*
	* This function does not accept anything
	* This function returns computerID
	*/
	return computerID;
}

void ValidationComputerID::set_computerID(string _computerID) {
	/*
	* this function accepts a string, and applies to the field of computerID
	* This function does not return anything
	*/
	computerID = _computerID;
}

void ValidationComputerID::test() {
	/*
	* This overloaded function does not accept any arguments
	* This function tests the comptuerid based on the parameters given to us and returns the message depending on the outcome of the test.
	* This function returns nothing.
	*/

	DataValidation::test();
	string letterOne;
	string letterTwo;
	string letterThree;

	displayComp = computerID;
	letterOne = computerID.at(0);
	letterTwo = computerID.at(1);
	letterThree = computerID.at(2);

	if (((letterOne != "0" || letterOne != "1" || letterOne != "2" || letterOne != "3" || letterOne != "4" || letterOne != "5" ||
		letterOne != "6" || letterOne != "7" || letterOne != "8" || letterOne != "9" || letterOne != "10") &&
		(letterTwo == "I" || letterTwo == "O") &&
		(letterThree == "I" || letterThree == "O"))) {

		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
	else if (((letterOne != "0" || letterOne != "1" || letterOne != "2" || letterOne != "3" || letterOne != "4" || letterOne != "5" ||
		letterOne != "6" || letterOne != "7" || letterOne != "8" || letterOne != "9" || letterOne != "10") &&
		(letterTwo == "0" || letterTwo == "1" || letterTwo == "2" || letterTwo == "3" || letterTwo == "4" || letterTwo == "5" ||
			letterTwo == "6" || letterTwo == "7" || letterTwo == "8" || letterTwo == "9" || letterTwo == "10" || letterTwo == "A" ||
			letterTwo == "B" || letterTwo == "C" || letterTwo == "D" || letterTwo == "E" || letterTwo == "F" ||
			letterTwo == "G" || letterTwo == "H" || letterTwo == "J" || letterTwo == "K" || letterTwo == "L" || letterTwo == "M" ||
			letterTwo == "N" || letterTwo == "P" || letterTwo == "Q" || letterTwo == "R" || letterTwo == "S" || letterTwo == "T" ||
			letterTwo == "U" || letterTwo == "V" || letterTwo == "W" || letterTwo == "X" || letterTwo == "Y" || letterTwo == "Z") &&
		(letterThree == "I" || letterThree == "O"))) {

		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
	else if (((letterOne != "0" || letterOne != "1" || letterOne != "2" || letterOne != "3" || letterOne != "4" || letterOne != "5" ||
		letterOne != "6" || letterOne != "7" || letterOne != "8" || letterOne != "9" || letterOne != "10") &&
		(letterTwo == "I" || letterTwo == "O") &&
		(letterThree == "0" || letterThree == "1" || letterThree == "2" || letterThree == "3" || letterThree == "4" || letterThree == "5" ||
			letterThree == "6" || letterThree == "7" || letterThree == "8" || letterThree == "9" || letterThree == "10" || letterThree == "A" ||
			letterThree == "B" || letterThree == "C" || letterThree == "D" || letterThree == "E" || letterThree == "F" ||
			letterThree == "G" || letterThree == "H" || letterThree == "J" || letterThree == "K" || letterThree == "L" || letterThree == "M" ||
			letterThree == "N" || letterThree == "P" || letterThree == "Q" || letterThree == "R" || letterThree == "S" || letterThree == "T" ||
			letterThree == "U" || letterThree == "V" || letterThree == "W" || letterThree == "X" || letterThree == "Y" || letterThree == "Z"))) {

		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "I" || letterTwo == "O") &&
		(letterThree == "I" || letterThree == "O"))) {

		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "0" || letterTwo == "1" || letterTwo == "2" || letterTwo == "3" || letterTwo == "4" || letterTwo == "5" ||
			letterTwo == "6" || letterTwo == "7" || letterTwo == "8" || letterTwo == "9" || letterTwo == "10" || letterTwo == "A" ||
			letterTwo == "B" || letterTwo == "C" || letterTwo == "D" || letterTwo == "E" || letterTwo == "F" ||
			letterTwo == "G" || letterTwo == "H" || letterTwo == "J" || letterTwo == "K" || letterTwo == "L" || letterTwo == "M" ||
			letterTwo == "N" || letterTwo == "P" || letterTwo == "Q" || letterTwo == "R" || letterTwo == "S" || letterTwo == "T" ||
			letterTwo == "U" || letterTwo == "V" || letterTwo == "W" || letterTwo == "X" || letterTwo == "Y" || letterTwo == "Z") &&
		(letterThree == "I" || letterThree == "O"))) {

		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "I" || letterThree == "O") &&
		(letterThree == "0" || letterThree == "1" || letterThree == "2" || letterThree == "3" || letterThree == "4" || letterThree == "5" ||
			letterThree == "6" || letterThree == "7" || letterThree == "8" || letterThree == "9" || letterThree == "10" || letterThree == "A" ||
			letterThree == "B" || letterThree == "C" || letterThree == "D" || letterThree == "E" || letterThree == "F" ||
			letterThree == "G" || letterThree == "H" || letterThree == "J" || letterThree == "K" || letterThree == "L" || letterThree == "M" ||
			letterThree == "N" || letterThree == "P" || letterThree == "Q" || letterThree == "R" || letterThree == "S" || letterThree == "T" ||
			letterThree == "U" || letterThree == "V" || letterThree == "W" || letterThree == "X" || letterThree == "Y" || letterThree == "Z")))
	{
		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect>>" << endl;
		reset();
	}
	else if (((letterOne == "A" || letterOne == "B" || letterOne == "C" || letterOne == "D" || letterOne == "E" || letterOne == "F" ||
		letterOne == "G" || letterOne == "H" || letterOne == "J" || letterOne == "K" || letterOne == "L" || letterOne == "M" ||
		letterOne == "N" || letterOne == "P" || letterOne == "Q" || letterOne == "R" || letterOne == "S" || letterOne == "T" ||
		letterOne == "U" || letterOne == "V" || letterOne == "W" || letterOne == "X" || letterOne == "Y" || letterOne == "Z") &&
		(letterTwo == "0" || letterTwo == "1" || letterTwo == "2" || letterTwo == "3" || letterTwo == "4" || letterTwo == "5" ||
			letterTwo == "6" || letterTwo == "7" || letterTwo == "8" || letterTwo == "9" || letterTwo == "10") &&
		(letterThree == "0" || letterThree == "1" || letterThree == "2" || letterThree == "3" || letterThree == "4" || letterThree == "5" ||
			letterThree == "6" || letterThree == "7" || letterThree == "8" || letterThree == "9" || letterThree == "10"))) {

		displayComp = "wrong-data";
		red();
		cout << "data.............................................................<<incorrect pattern>>" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "0" || letterTwo == "1" || letterTwo == "2" || letterTwo == "3" || letterTwo == "4" || letterTwo == "5" ||
			letterTwo == "6" || letterTwo == "7" || letterTwo == "8" || letterTwo == "9" || letterTwo == "10") &&
		(letterThree == "0" || letterThree == "1" || letterThree == "2" || letterThree == "3" || letterThree == "4" || letterThree == "5" ||
			letterThree == "6" || letterThree == "7" || letterThree == "8" || letterThree == "9" || letterThree == "10"))) {

		blue();
		cout << "data.............................................................OK" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "0" || letterTwo == "1" || letterTwo == "2" || letterTwo == "3" || letterTwo == "4" || letterTwo == "5" ||
			letterTwo == "6" || letterTwo == "7" || letterTwo == "8" || letterTwo == "9" || letterTwo == "10") &&
		(letterThree == "A" || letterThree == "B" || letterThree == "C" || letterThree == "D" || letterThree == "E" || letterThree == "F" ||
			letterThree == "G" || letterThree == "H" || letterThree == "J" || letterThree == "K" || letterThree == "L" || letterThree == "M" ||
			letterThree == "N" || letterThree == "P" || letterThree == "Q" || letterThree == "R" || letterThree == "S" || letterThree == "T" ||
			letterThree == "U" || letterThree == "V" || letterThree == "W" || letterThree == "X" || letterThree == "Y" || letterThree == "Z")))
	{
		blue();
		cout << "data.............................................................OK" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "A" || letterTwo == "B" || letterTwo == "C" || letterTwo == "D" || letterTwo == "E" || letterTwo == "F" ||
			letterTwo == "G" || letterTwo == "H" || letterTwo == "J" || letterTwo == "K" || letterTwo == "L" || letterTwo == "M" ||
			letterTwo == "N" || letterTwo == "P" || letterTwo == "Q" || letterTwo == "R" || letterTwo == "S" || letterTwo == "T" ||
			letterTwo == "U" || letterTwo == "V" || letterTwo == "W" || letterTwo == "X" || letterTwo == "Y" || letterTwo == "Z") &&
		(letterThree == "0" || letterThree == "1" || letterThree == "2" || letterThree == "3" || letterThree == "4" || letterThree == "5" ||
			letterThree == "6" || letterThree == "7" || letterThree == "8" || letterThree == "9" || letterThree == "10"))) {

		blue();
		cout << "data.............................................................OK" << endl;
		reset();
	}
	else if (((letterOne == "0" || letterOne == "1" || letterOne == "2" || letterOne == "3" || letterOne == "4" || letterOne == "5" ||
		letterOne == "6" || letterOne == "7" || letterOne == "8" || letterOne == "9" || letterOne == "10") &&
		(letterTwo == "A" || letterTwo == "B" || letterTwo == "C" || letterTwo == "D" || letterTwo == "E" || letterTwo == "F" ||
			letterTwo == "G" || letterTwo == "H" || letterTwo == "J" || letterTwo == "K" || letterTwo == "L" || letterTwo == "M" ||
			letterTwo == "N" || letterTwo == "P" || letterTwo == "Q" || letterTwo == "R" || letterTwo == "S" || letterTwo == "T" ||
			letterTwo == "U" || letterTwo == "V" || letterTwo == "W" || letterTwo == "X" || letterTwo == "Y" || letterTwo == "Z") &&
		(letterThree == "A" || letterThree == "B" || letterThree == "C" || letterThree == "D" || letterThree == "E" || letterThree == "F" ||
			letterThree == "G" || letterThree == "H" || letterThree == "J" || letterThree == "K" || letterThree == "L" || letterThree == "M" ||
			letterThree == "N" || letterThree == "P" || letterThree == "Q" || letterThree == "R" || letterThree == "S" || letterThree == "T" ||
			letterThree == "U" || letterThree == "V" || letterThree == "W" || letterThree == "X" || letterThree == "Y" || letterThree == "Z"))) {

		blue();
		cout << "data.............................................................OK" << endl;
		reset();
	}
}

int main() {

	int validateID = 1;

	do {
		cout << system("cls");
		menu();
		if (menu_opt == '1') {


			DataValidation* source[3];
			DataValidation* flight[3];
			DataValidation* computer[3];

			cout << "[I] Enter sourceTime field [hhmmss] : "; cin >> src_time;
			source[0] = new ValidationSource(validateID, src_time);
			source[0]->test();
			cout << "[II] Enter flightID                 : "; cin >> flt_id;
			flight[0] = new ValidationFlightID(validateID, flt_id);
			flight[0]->test();
			cout << "[III] Enter computerID              : "; cin >> comp_id;
			computer[0] = new ValidationComputerID(validateID, comp_id);
			computer[0]->test();

			blue();
			cout << "Would you like to return to the Main Menu [Y/N]? "; cin >> menu_opt;
		}

		else if (menu_opt == '2') {

			xml_display(word, displayComp);
			cout << "-----------------------------------------------------------------" << endl;
			cyan();
			cout << "Would you like to return to the Main Menu [Y/N]? "; cin >> menu_opt;
		}
		else if (menu_opt == '3') {
			int fileChoice;
		
			do {
				
				cout << system("cls");
				cout << "            << FILE SELECTION >>" << endl;
				cout << "Please enter the Scenario you wish to use (1-5): "; cin >> fileChoice;

				if (fileChoice <= 0 || fileChoice >= 6) {
					red();
					cout << "Please make a valid choice.";
					reset();
					cout << "Please enter the Scenario you wish to use (1-5): "; cin >> fileChoice;
				}


				submenu(fileChoice);
				
				if (submenu_opt == '1' || submenu_opt == '2') {
					if (submenu_opt == '1') {
						if (fileChoice == 1) {
							file1.open("", ios::in);
							if (file1.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							white();
							cout << "READING-INPUT FILE" << endl;
							cout << "------------------" << endl;
							while (!file1.eof()) {
								getline(file1, text1);
								cout << text1 << endl;
							}
							cout << "--------------------------------------------------------------------------" << endl;
							cyan();
						}
						else if (fileChoice == 2) {
							file2.open("", ios::in);
							if (file2.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							white();
							cout << "READING-INPUT FILE" << endl;
							cout << "------------------" << endl;
							while (!file2.eof()) {
								getline(file2, text2);
								cout << text2 << endl;
							}
							cout << "--------------------------------------------------------------------------" << endl;
							cyan();
						}
						else if (fileChoice == 3) {
							file3.open("", ios::in);
							if (file3.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							white();
							cout << "READING-INPUT FILE" << endl;
							cout << "------------------" << endl;
							while (!file3.eof()) {
								getline(file3, text3);
								cout << text3 << endl;
							}
							cout << "--------------------------------------------------------------------------" << endl;
							cyan();
						}
						else if (fileChoice == 4) {
							file4.open("", ios::in);
							if (file4.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							white();
							cout << "READING-INPUT FILE" << endl;
							cout << "------------------" << endl;
							while (!file4.eof()) {
								getline(file4, text4);
								cout << text4 << endl;
							}
							cout << "--------------------------------------------------------------------------" << endl;
							cyan();
						}
						else if (fileChoice == 5) {
							file5.open("", ios::in);
							if (file5.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							white();
							cout << "READING-INPUT FILE" << endl;
							cout << "------------------" << endl;
							while (!file5.eof()) {
								getline(file5, text5);
								cout << text5 << endl;
							}
							cout << "--------------------------------------------------------------------------" << endl;
							cyan();
						}
						cout << "-----------------------------------------------------------------" << endl;
						cyan();
						cout << "Would you like to return to the Sub Menu [Y/N]? "; cin >> submenu_opt;
					}

					else if (submenu_opt == '2') {
						if (fileChoice == 1) {
							file_a1.open("", ios::in);
							if (file_a1.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							cout << "ANALYSIS-INPUT FILE" << endl;
							cout << "Log file-[October 2021]" << endl;
							cout << "=========================================================================" << endl;

							while (!file_a1.eof()) {
								getline(file_a1, text_a1);
								cout << "ASCII-MESSAGE => [" << text_a1 << "]" << endl;
								label_1a = text_a1.find("07D") + 4;
								label_2a = text_a1.at(label_1a);

								if (label_2a == "D") {
									cyan();
									cout << "[D2306] <<CoorStatusTime>.....................................Flight has departed from airport KSAV" << endl;
									reset();
								}
								else {
									green();
									cout << "Log File....................................................... << missing coordinates status >> " << endl;
									reset();
								}

							}

							file_a1.close();
						}

						else if (fileChoice == 2) {
							file_a2.open("", ios::in);
							if (file_a2.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							cout << "ANALYSIS-INPUT FILE" << endl;
							cout << "Log file-[October 2021]" << endl;
							cout << "=========================================================================" << endl;

							while (!file_a2.eof()) {
								getline(file_a2, text_a2);
								cout << "ASCII-MESSAGE => [" << text_a2 << "]" << endl;
								label_1b = text_a2.find("07D") + 4;
								label_2b = text_a2.at(label_1b);

								if (label_2b == "D") {
									cyan();
									cout << "[D2306] <<CoorStatusTime>.....................................Flight has departed from airport KSAV" << endl;
									reset();
								}
								else {
									green();
									cout << "Log File....................................................... << missing coordinates status >> " << endl;
									reset();
								}

							}

							file_a2.close();
						}

						else if (fileChoice == 3) {
							file_a3.open("", ios::in);
							if (file_a3.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							cout << "ANALYSIS-INPUT FILE" << endl;
							cout << "Log file-[October 2021]" << endl;
							cout << "=========================================================================" << endl;

							while (!file_a3.eof()) {
								getline(file_a3, text_a3);
								cout << "ASCII-MESSAGE => [" << text_a3 << "]" << endl;
								label_1c = text_a3.find("07D") + 4;
								label_2c = text_a3.at(label_1c);

								if (label_2c == "D") {
									cyan();
									cout << "[D2306] <<CoorStatusTime>.....................................Flight has departed from airport KSAV" << endl;
									reset();
								}
								else {
									green();
									cout << "Log File....................................................... << missing coordinates status >> " << endl;
									reset();
								}

							}

							file_a3.close();
						}

						else if (fileChoice == 4) {
							file_a4.open("", ios::in);
							if (file_a4.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							cout << "ANALYSIS-INPUT FILE" << endl;
							cout << "Log file-[October 2021]" << endl;
							cout << "=========================================================================" << endl;

							while (!file_a4.eof()) {
								getline(file_a4, text_a4);
								cout << "ASCII-MESSAGE => [" << text_a4 << "]" << endl;
								label_1d = text_a4.find("07D") + 4;
								label_2d = text_a4.at(label_1d);

								if (label_2d == "D") {
									cyan();
									cout << "[D2306] <<CoorStatusTime>.....................................Flight has departed from airport KSAV" << endl;
									reset();
								}
								else {
									green();
									cout << "Log File....................................................... << missing coordinates status >> " << endl;
									reset();
								}

							}

							file_a4.close();
						}

						else if (fileChoice == 5) {
							file_a5.open("", ios::in);
							if (file_a5.fail()) {
								red();
								cout << "============ << Wrong file cannot open >> =============" << endl;
								reset();
								exit(3);
							}

							cout << "ANALYSIS-INPUT FILE" << endl;
							cout << "Log file-[October 2021]" << endl;
							cout << "=========================================================================" << endl;

							while (!file_a5.eof()) {
								getline(file_a5, text_a5);
								cout << "ASCII-MESSAGE => [" << text_a5 << "]" << endl;
								label_1e = text_a5.find("07D") + 4;
								label_2e = text_a5.at(label_1e);

								if (label_2e == "D") {
									cyan();
									cout << "[D2306] <<CoorStatusTime>.....................................Flight has departed from airport KSAV" << endl;
									reset();
								}
								else {
									green();
									cout << "Log File....................................................... << missing coordinates status >> " << endl;
									reset();
								}

							}

							file_a5.close();
						}
					}

					cout << "-----------------------------------------------------------------" << endl;
					cyan();
					cout << "Would you like to return to the Sub Menu [Y/N]? "; cin >> submenu_opt;

				}
				

				else if (submenu_opt == '3') {

					cout << "Thank you for using our file system" << endl;

					submenu_opt = 'n';
					menu_opt = 'y';

				}

				


			} while (submenu_opt == 'Y' || submenu_opt == 'y');

			cout << "-----------------------------------------------------------------" << endl;
			cyan();
			cout << "Would you like to return to the Main Menu [Y/N]? "; cin >> menu_opt;

		}

	} while (menu_opt == 'Y' || menu_opt == 'y');
	
	return 0;
}

void menu() {

	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "*                           << MAIN MENU >>                                   *" << endl;
	cout << "*  [OPTIONS]                                                                  *" << endl;
	cout << "*  [1] INPUT-DISPLAY VALIDATION                                               *" << endl;
	cout << "*  [2] DISPLAY INPUT-DATA                                                     *" << endl;
	cout << "*  [3] OPEN SUB-MENU                                                          *" << endl;
	cout << "*  [4] EXIT                                                                   *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
	cout << "Enter Option number [] ->"; cin >> menu_opt;

}

void submenu(int choice) {
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "*                            << SUB MENU >>                                   *" << endl;
	cout << "*  [OPTIONS - SCENARIO " << choice << "]                     * " << endl;
	cout << "*  [1] READ INPUT DATA                                                        *" << endl;
	cout << "*  [2] ANALYSIS INPUT-DATA                                                    *" << endl;
	cout << "*  [3] BACK TO MAIN MENU                                                      *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
	cout << "Enter Option number [] ->"; cin >> submenu_opt;
}

void xml_display(string _word, string _displayComp) {
	purple();
	cout << "DISPLAY-DATA IN XML FORMAT" << endl;
	cout << "--------------------------" << endl;
	red();
	cout << "Time of arrival date          =>     <sourceTime_00e1>  " << src_time << "     </sourceTime__00e1>" << endl;
	cout << "The Aircraft Identification   =>     <flightID_02a   >  " << _word << "     </flightId_02a>" << endl;
	cout << "The Computer Identification   =>     <computerId_02d >  " << _displayComp << "  </computerId_02d>" << endl;
	cout << "_______________________________________________________________________________________________" << endl;

}