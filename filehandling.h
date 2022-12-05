#include "project_header.h" 

#ifndef filehandling_H
#define filehandling_H

void handlefile(vector<float>& date, vector<float>& price){
string file = "AMZN.csv";
string date_temp, price_temp; //variables from file are here
int i = 0;
ifstream filename(file); //opening the file.

if (filename.is_open()) //if the file is open
	{
		
		//ignore first line
		string line;
		getline(filename, line);

		while (!filename.eof()) //while the end of file is NOT reached
		{
			
			getline(filename, date_temp, ',');
			date.push_back(stof(date_temp));
			getline(filename, price_temp, '\n');
			price.push_back(stof(price_temp));
			i += 1;
		}

		filename.close(); //closing the file
		//cout << "Number of entries: " << i-1 << endl;
	}
    
	else cout << "Unable to open file"; //if the file is not open output
    
}

#endif