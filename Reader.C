#include <iostream>
#include <fstream>

using namespace std;

void reader_of_files();


void reader_of_files() 
{
	ifstream file;
	file.open("uppsala_tm_1722-2013.dat");
	string helpString;
	Int_t year;
	Int_t month;
	Int_t day;
	Double_t temp;
	Double_t atemp;
	string line;
	
	TH1D* hPhi = new TH1D("hPhi", "ROOT func generated v2 distribution; x; Counts", 
		100, 0, 2*TMath::Pi());
	
	

	
while (getline(file, line)) {
		vecline.push_back(line);
}



	Int_t length=vecline.size();
	
	Int_t vecline 	
	vector <Int_t> vecyear;
	vector <Int_t> vecmonth;
	vector <Int_t> vecday;
	vector <Double_t> vectemp;
	vector <Double_t> vecatemp;
	
for (Int_t i=0; i < length; i++){

	file >> year[i] >> month[i] >> day[i] >> temp[i] >> atemp[i] >> helpString;
	
	vecyear.push_back(year[i]);
	vecmonth.push_back(month[i]);
	vecday.push_back(day[i]);
	vecatemp.push_back(atemp[i]);
	vectemp.push_back(temp[i]);
	//vectemp.push_back(helpString[i]);
}
	

/*

for (size_t i=11; i < 426155; i++){
	
	cout << vecyear.at(i) << endl;
	cout << vecmonth.at(i) << endl;
	cout << vecday.at(i) << endl;
	cout << vectime.at(i) << endl;
	cout << vectemp.at(i) << endl;
}



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
	
	
//	cout << vecyear.at(i) << endl;
	
	/*
	cout << vecmonth.at(i) << endl;
	cout << vecday.at(i) << endl;
	cout << vectime.at(i) << endl;
	cout << vectemp.at(i) << endl;
	*/

cout << vecday.size() << endl;
cout << vecyear.size() << endl;
cout << vectemp.size() << endl;

cout << vectemp.at(0) << endl;
cout << vecatemp.at(0) << endl;
cout << vecyear.at(0) << endl;
cout << vecmonth.at(0) << endl;
cout << vecday.at(0) << endl;

}

