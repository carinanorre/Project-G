#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void filereadertest();

void filereadertest()
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
		if (city == 1){
			vecyear.push_back(year);
			vecmonth.push_back(month);
			vecday.push_back(day);
			vectemperature.push_back(temperature);
			vectemperature2.push_back(temperature2);
			veccity.push_back(city);
		}
		
	}
	cout << vecyear.size() << endl;
	
	
	//for (size_t i = 0; i < vecyear.size(); ++i) cout << vecyear.at(i) << endl;
	//for (size_t i = 0; i < vecmonth.size(); ++i) cout << vecmonth.at(i) << endl;
	//for (size_t i = 0; i < vecday.size(); ++i) cout << vecday.at(i) << endl;
	//for (size_t i = 0; i < vectemperature.size(); ++i) cout << vectemperature.at(i) << endl;	
	
	vector<Int_t> yearbreaker;
	yearbreaker.push_back(0);
	
	for (size_t i=0; i < vecyear.size() -1 ; ++i){
		Int_t j=i+1;
		if (vecyear.at(i) < vecyear.at(j)){
			//yearbreaker.push_back(j); 
			cout << vecyear.at(j) << endl;
			//cout << j << endl;
			//cout << vecmonth.at(j) << ", " << vecday.at(j) << endl;
		}
			
		else continue;
	}
		
		Int_t l;
		for (size_t k=0; k < yearbreaker.size() + 1; k++){
			l= yearbreaker.at(k);
			//for (vectemperature.at(l); vectemperature.at(l+1))
			cout << 
	
	//cout << vecmonth.at(j) << vecday.at(j) << endl;
	
	
	inFile.clear();
	inFile.seekg(0, ios::beg); 
	
}
