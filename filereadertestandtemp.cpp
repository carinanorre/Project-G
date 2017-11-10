#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ROOT library objects
#include <TF1.h> // 1d function class
#include <TH1.h> // 1d histogram classes
#include <TStyle.h>  // style object
#include <TMath.h>   // math functions
#include <TCanvas.h> // canvas object
#include <TGraph.h> 
#include <TLegend.h>

double Gaussian(double*, double*);

void filereadertestandtemp();

void filereadertestandtemp()
{

	cout << "Reading values from uppsala.dat..." << endl; 
	
	//Opening the Uppsala data file
	ifstream inFile;
	inFile.open("datasets/uppsala_tm_1722-2013.dat");
	
	//Initiating the vectors where the data will be stored
	vector<Int_t> vecyear;
	vector<Int_t> vecmonth;
	vector<Int_t> vecday;
	vector<Float_t> vectemperature;
	vector<Float_t> vectemperature2;
	vector<Int_t> veccity;
	
	//Initiating the varible names for the data elements
	Int_t year;
	Int_t month;
	Int_t day;
	Float_t temperature;
	Float_t temperature2;
	Int_t city;
	
	//A while loop that runs through the data file, assigns each value it encounters to a new variable
	//The data is separated by spaces, so it automatically jumps values	
	while (inFile >> year >> month >> day >> temperature >> temperature2 >> city){
		
		if (city == 1) { //Only taking into account the lines of data that were recorded at Uppsala, as some came from different cities
		//Pushing back to each vector the corresponding data values
		vecyear.push_back(year);
		vecmonth.push_back(month);
		vecday.push_back(day);
		vectemperature.push_back(temperature);
		vectemperature2.push_back(temperature2);
		veccity.push_back(city);
		}
	}
	//Initializing a vector that will hold the indices of the vecyear where the year changes
	vector<Int_t> yearbreaker;
	yearbreaker.push_back(0); //Adding a zero to the beginning of the vector to be able to take into count the data from the start
	
	//A for loop that runs the length of the vecyear, and checks the consecutive values to see if the value of year is the same
	//If the consecutive values are not the same, the year has changed and we record that index 
	for (size_t i=0; i < vecyear.size()-1; ++i){ //The -1 is to stay in range, as j=i+1
		Int_t j=i+1;
		if (vecyear.at(i) < vecyear.at(j)){ //Checking the relation between consecutive year values
			yearbreaker.push_back(j);  //Pushing back the index at which the year changed to the larger value
			}
			else continue; //If the condition above is not met, the loop continues on to the next year value
		}
	
	vector<Int_t> cleanyears;
	for (size_t r=0; r < vecyear.size() -1; ++r){
		Int_t s=r+1;
		if (vecyear.at(r) < vecyear.at(s)){
			cleanyears.push_back(vecyear.at(r));
		}
	}
	//cleanyears.push_back(2013);
	//for (size_t t = 0; t < cleanyears.size(); ++t) cout << cleanyears.at(t) << endl;
	cout << cleanyears.size() << endl;
	
	//Initiazing a vector that will allow us to find which day of the year corresponds to the data point
	vector <Int_t> vecmonthdays;
	vecmonthdays.push_back(0);
	vecmonthdays.push_back(31); 
	vecmonthdays.push_back(60); //The values are cummulative
	vecmonthdays.push_back(91);
	vecmonthdays.push_back(121);
	vecmonthdays.push_back(152);
	vecmonthdays.push_back(182);
	vecmonthdays.push_back(213);
	vecmonthdays.push_back(244);
	vecmonthdays.push_back(274);
	vecmonthdays.push_back(305);
	vecmonthdays.push_back(335);
	
	//Initializing vectors to hold the days of the hottest temperatures and the coldest temperatures
	vector <Int_t> warmday;
	vector <Int_t> coldday;
	
	cout << "still working.." << endl;
	
	vector <Float_t> vecavg;
	
	vector <Float_t> vecavgdiff;
	
	for (size_t k=0; k < yearbreaker.size()-1; k++){
		
		Int_t l = yearbreaker.at(k);
		Int_t l1 = yearbreaker.at(k+1);
		
		Float_t max;
		max = -10;
		Float_t min;
		min = 70;
		Int_t n;
		n = -1;
		Int_t o;
		o = -1;
		
		Float_t sumtemp;
		Float_t avg;
		sumtemp = 0;
		Float_t sumtempdiff;
		sumtempdiff = 0;
		Float_t avgdiff;
		
		
		for (Int_t m=l; m < l1-1; m++){
			if (vectemperature.at(m) > max){ //Loop checking for the hottest temperature in each year
				max=vectemperature.at(m);
				n=m;//Reassigning the index to call it later
			}		
			if (vectemperature.at(m) < min){//Loop checking for the coldest temperature in each year
				min=vectemperature.at(m);
				o=m;//Again, reassigning the index to call it later
			}
			sumtemp += vectemperature.at(m); //Summing the temperatures in each year to later find the mean
			sumtempdiff += abs(vectemperature.at(m) - vectemperature2.at(m)); // Summing the absolute differences between the recorded
			//temperature and the temperature altered due to urban effect for each year to later take the mean
			
			
		}
		avg = sumtemp/(l1-l); //The average temperature each year
		vecavg.push_back(avg); //Vector containing the average temperatures each year
		
		//cout << vecavg.size() << endl;
		
		
		avgdiff = sumtempdiff/(l1-l); //The average temperature difference with urban effect each year
		vecavgdiff.push_back(avgdiff); //Vector with the temperature difference averages
		
		warmday.push_back(vecmonthdays.at(vecmonth.at(n)-1) + vecday.at(n)); // Finding the day of the year for the warm days
		//The vecmonth returns the number of the month, which corresponds to the index in vecmonthdays, and then returns the 
		//cummulative day value
		coldday.push_back(vecmonthdays.at(vecmonth.at(o)-1) + vecday.at(o)); //The same done for the cold days
	
	} 
	
	//cout << vecavg.size() << endl;

	//for (size_t i=0; i < vecavgdiff.size(); i++) cout << vecavgdiff.at(i) << endl;
	//for (size_t i=0; i < vecavg.size(); i++) cout << vecavg.at(i) << endl;
	
	
	
	//creating the histogram

	TH1D* htemp = new TH1D("WarmestDay", "Highest and Lowest Temperature Days; Day of the Year; Counts", 
		200, 0, 366);
	for (size_t i=0; i < warmday.size(); i++){
		htemp->Fill(warmday.at(i));
	}
	
	TH1D* htemp2 = new TH1D("WarmestDay", "Highest temperature days; Day of the Year; Counts", 
		200, 0, 366);
	for (size_t i=0; i < coldday.size(); i++){
		htemp2->Fill(coldday.at(i));
	}
	
	
	
		
	// create canvas for hTemp
	TCanvas* c1 = new TCanvas("c1", "Hottest and Coldest Days");
	htemp->Draw();
	htemp->SetFillColor(kRed-3);
	htemp->SetLineColor(kRed-3);
	htemp2->Draw("SAME");
	htemp2->SetFillColor(kBlue-4);
	htemp2->SetLineColor(kBlue-4);
	gStyle->SetOptStat(0); //Gets rid of the automatic stats box
	
	TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.87);
	leg->SetFillStyle(0); 
	leg->SetBorderSize(0);
	leg->AddEntry(htemp, "Warmest Days", "F");
	leg->AddEntry(htemp2,"Coldest Days", "F");
	leg->Draw();
	
	TF1* hotfunc = new TF1("Gaussian", Gaussian, 120, 270, 3);
	hotfunc->SetParameters(5, 200, 50); //Starting values for fitting
	hotfunc->SetLineColor(1);
	htemp->Fit(hotfunc, "Q0R");
	hotfunc->Draw("SAME");
	gStyle->SetOptStat(0);
	
	TF1* coldfunc1 = new TF1("Gaussian", Gaussian, 0, 120, 3);
	coldfunc1->SetParameters(5, 200, 60);
	coldfunc1->SetLineColor(1);
	coldfunc1->SetLineStyle(2);
	htemp2->Fit(coldfunc1, "Q0R");
	coldfunc1->Draw("SAME");
	gStyle-> SetOptStat(0);
	
	TF1* coldfunc2 = new TF1("Gaussian", Gaussian, 270, 366, 3);
	coldfunc2->SetParameters(5, 200, 50);
	coldfunc2->SetLineColor(1);
	coldfunc2->SetLineStyle(2);
	htemp2->Fit(coldfunc2, "Q0R");
	coldfunc2->Draw("SAME");
	
	// Save the canvas as a picture
	c1->SaveAs("Warmest_and_Coldest_day.jpg");

	//TEMP AVG
	TCanvas *c2 = new TCanvas("c2", "Mean Temperatures of each year", 200, 10, 700, 500);
	Double_t x[284], y[284];
	Int_t z=284;
	for (Int_t i=0; i < z; i++){
		x[i]=cleanyears.at(i);
		y[i]=vecavg.at(i);
	}
	TGraph* mean = new TGraph(z, x, y);
	mean->SetTitle("Mean Temperature Each Year;Year;Temperature");
	mean->SetFillColor(kRed);
	mean->SetLineColor(kRed);
	mean->Draw("AC");
	
	c2->SaveAs("AvgTemp.jpg");

	//TEMPDIFF
	TCanvas *c3 = new TCanvas("c3", "Mean Temperature Difference each year", 200, 10, 700, 500);
	Double_t a[284], b[284];
	Int_t c=284;
	for (Int_t i=0; i < c; i++){
		a[i]=cleanyears.at(i);
		b[i]=vecavgdiff.at(i);
	}
	TGraph* meandiff = new TGraph(c, a, b);
	meandiff->SetTitle("Mean Temperature Difference Each Year;Year;Temperature");
	meandiff->SetFillColor(kBlue);
	meandiff->SetLineColor(kBlue);
	meandiff->Draw("AC");
	
	c3->SaveAs("AvgTempDiff.jpg");

	
	

}
double Gaussian(double* x, double* par) {
		return par[0]*exp(-0.5*(x[0]*x[0] - 2*x[0]*par[1] + par[1]*par[1])/(par[2]*par[2]));
	}
