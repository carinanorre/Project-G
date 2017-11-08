#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void filereader();

void filereader()
{

	cout << "Reading values from uppsala.dat..." << endl; 
	
	vector<string> uppsaladata; //Creating a vector called uppsaladata to hold the values from the data file
	
	ifstream inFile;
	inFile.open("datasets/uppsala_tm_1722-2013.dat");
	
	string line;
	
	vector<Int_t> vecyear;
	vector<Int_t> vecmonth;
	vector<Int_t> vecday;
	vector<Float_t> vectemperature;
	vector<Float_t> vectemperature2;
	vector<Int_t> veccity;
	
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
		vectemperature2.push_back(temperature2);
		veccity.push_back(city);
		
	}
	
	vector<Int_t> notuppsala;
	//Need to somehow delete the data points that aren't taken from Uppsala
	for (size_t i=0; i < veccity.size(); i++) {
		if (veccity.at(i) > 1){	
			notuppsala.push_back(i);
		}
		else continue;
	}
	
	//for (size_t i = 0; i < notuppsala.size(); ++i) cout << notuppsala.at(i) << endl;

	//for (size_t i = 0; i < vecyear.size(); ++i) cout << vecyear.at(i) << endl;
	//for (size_t i = 0; i < vecmonth.size(); ++i) cout << vecmonth.at(i) << endl;
	//for (size_t i = 0; i < vecday.size(); ++i) cout << vecday.at(i) << endl;
	//for (size_t i = 0; i < vectemperature.size(); ++i) cout << vectemperature.at(i) << endl;
		//cout << vecyear.at(100000) << endl;
		
	//for (size_t i = 0; i < veccity.size(); ++i) cout << veccity.at(i) << endl;	
	
	for (size_t i=0; i < notuppsala.size(); ++i) {
		Int_t m;
		m=notuppsala.at(i);
		vecyear.erase(vecyear.begin() +m);
		vecmonth.erase(vecmonth.begin() +m);
		vecday.erase(vecday.begin() +m);
		vectemperature.erase(vectemperature.begin() +m);
		vectemperature2.erase(vectemperature2.begin() +m);
		veccity.erase(veccity.begin() +m);
	}
	
	inFile.clear();
	inFile.seekg(0, ios::beg); 
	
}
