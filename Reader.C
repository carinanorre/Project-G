#include <iostream>
#include <fstream>

using namespace std;

void reader_of_files();


void reader_of_files() 
{
	ifstream file;
	file.open("smhi-openda_Karlstad.csv");
	string helpString;
	string breaker = ";" ;
	Int_t year;
	Int_t month;
	Int_t day;
	Int_t hour;
	Double_t temperature;
	//const char* dash;
	string line;
	
	vector <string> vecyear;
	vector <Int_t> vecmonth;
	vector <Int_t> vecday;
	vector <Int_t> vectime;
	vector <Double_t> vectemp;
/*	
while (file >> line ) {
	file >> year >> helpString >> month >> helpString >> day >> helpString >> hour >> helpString;
	
	vecyear.push_back(year);
	vecmonth.push_back(month);
	vecday.push_back(day);
	vectime.push_back(hour);
	vectemp.push_back(temperature);
}
*/	

/*

for (size_t i=11; i < 426155; i++){
	
	cout << vecyear.at(i) << endl;
	cout << vecmonth.at(i) << endl;
	cout << vecday.at(i) << endl;
	cout << vectime.at(i) << endl;
	cout << vectemp.at(i) << endl;
}

*/

for (size_t i=0; i < vecday.size(); i++){
	fstream file;
	file.open("smhi-openda_Karlstad.csv");
	getline(file,line);
	string delimiter = "-";
	string years;
	years = line.substr(0, line.find(delimiter));
	cout << line << endl;
	
	vecyear.push_back(line);
	/*
	vecmonth.push_back(month);
	vecday.push_back(day);
	vectime.push_back(hour);
	vectemp.push_back(temperature);
	*/
	
	
	cout << vecyear.at(i) << endl;
	
	/*
	cout << vecmonth.at(i) << endl;
	cout << vecday.at(i) << endl;
	cout << vectime.at(i) << endl;
	cout << vectemp.at(i) << endl;
	*/
}
cout << vecday.size() << endl;
}

