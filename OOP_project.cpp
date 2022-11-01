#include "project_header.h" 


//class for SMA calculation
class SMA{

// private function for average calculation
float average(vector<float> data, int days){
	float average;
	for(int i=0;i<days;i++){
		average += data[i];
	}
	return average;
}

//public function for SMA calculation
public:
vector<float> SMA_20(vector<float> data,int days){
 
 float avg = average(data,days);
 return data;
}
};


int main()
{
string date_temp, price_temp; //variables from file are here
	vector<float>date;        //vector for date field
	vector<float>price;       //vector for price field

	string file = "AMZN.csv";
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
		cout << "Number of entries: " << i-1 << endl;
	}
    
	else cout << "Unable to open file"; //if the file is not open output
    
    
    for(int j=0;j<i;j++){       // check for values in the file
    cout<<date[j]<<"\t"<<price[j]<<endl;
    }

	SMA obj1;
	obj1.SMA_20(price,20);


}

