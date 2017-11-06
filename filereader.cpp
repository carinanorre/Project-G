#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//"datasets/smhi-openda_Karlstad.csv"

//void filereader();

//void filereader()
int main(){

	
	cout << "Reading values from uppsala.dat..." << endl; 
	vector<string> uppsaladata; //Creating a vector called uppsaladata to hold the values from the data file
	ifstream inFile;
	inFile.open("datasets/uppsala_tm_1722-2013.dat");
	string line;
	
	if (inFile){
		float data;
		
		while (getline(inFile, line)) {
			uppsaladata.push_back(line);
		}
	}
	//for (size_t i = 0; i < uppsaladata.size(); ++i) cout << uppsaladata.at(i) << endl;
	
	//cout << uppsaladata.at(1) << endl;
	
	int year;
	int month;
	int day;
	float temperature;
	
	vector<int> vecyear;
	vector<int> vecmonth;
	vector<int> vecday;
	vector<float> vectemperature;
	
	for (size_t i = 0; i < uppsaladata.size(); ++i){
		inFile >> year >> month >> day >> temperature;
		vecyear.push_back(year);
		vecmonth.push_back(month);
		vecday.push_back(day);
		vectemperature.push_back(temperature);
		
	}
	
	for (size_t i = 0; i < vecyear.size(); ++i) cout << vecyear.at(i) << endl;
	
	//cout << vecyear.at(4) << endl;
	/*ifstream open("datasets/smhi-openda_Karlstad.csv");
	
	if(!open.is_open()) cout << "ERROR: File Open" << endl;
	
	string year;
	string month;
	string day;
	string time;
	string temperature;
	
	while(open.good()){
		
		getline(open.year,'-');
		getline(open.month,'-');
		getline(open.day,';');
		getline(open.time,';');
		getline(open.temperature,';');
	
	}*/
	
}
