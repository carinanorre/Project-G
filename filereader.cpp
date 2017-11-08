#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//"datasets/smhi-openda_Karlstad.csv"

void filereader();

void filereader()
{

	cout << "Reading values from uppsala.dat..." << endl; 
	vector<string> uppsaladata; //Creating a vector called uppsaladata to hold the values from the data file
	ifstream inFile;
	inFile.open("datasets/uppsala_tm_1722-2013.dat");
	//inFile.open("test");
	string line;
	
	vector<Int_t> vecyear;
	vector<Int_t> vecmonth;
	vector<Int_t> vecday;
	vector<Float_t> vectemperature;
	
	if (inFile){
		Float_t data;
		Int_t year;
		Int_t month;
		Int_t day;
		Float_t temperature;
		Float_t temperature2;
		Int_t city;
		
		while (inFile >> year >> month >> day >> temperature >> temperature2 >> city){
			//cout << year << ", " << month << ", " << day << ", " << temperature << endl;
			vecyear.push_back(year);
			vecmonth.push_back(month);
			vecday.push_back(day);
			vectemperature.push_back(temperature);
			
		}
		
		
	}
	for (size_t i = 0; i < vecyear.size(); ++i) cout << vecyear.at(i) << endl;
	for (size_t i = 0; i < vecmonth.size(); ++i) cout << vecmonth.at(i) << endl;
	for (size_t i = 0; i < vecday.size(); ++i) cout << vecday.at(i) << endl;
	for (size_t i = 0; i < vectemperature.size(); ++i) cout << vectemperature.at(i) << endl;
		//cout << vecyear.at(100000) << endl;
	inFile.clear();
	inFile.seekg(0, ios::beg); 
	
}
