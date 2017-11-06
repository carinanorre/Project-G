#include <iostream>
#include <fstream>

using namespace std;

void reader_of_file();


void reader_of_file() 
{
	fstream file;
	file.open("smhi-openda_Karlstad.csv");
	string line;
	
	vector <string> vecline;
	while (file >> line) {
		vecline.push_back(line);
		
	
}
	for (size_t i=104; i<426155; i++){
		if (vecline.at(i) == "19"*) {
			cout << "element is a year" << endl;
	}
		else if (vecline.at(i) == "20"*) {
			cout << "element is a year" << endl;
	}
		else {
			cout << "element is not a year :(" << endl;
			vecline.erase(vecline.begin() + i);
	}
	
}
	//cout << vecline.size()<< endl;
	
/*	
	for (size_t i=60; i<104; i++){
		cout << vecline.at(i) << endl;
		
		//cout << vecline.at(vecline.size()-i) << endl;

}	
*/
cout << vecline.size() << endl;
	file.close();
}

