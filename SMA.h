#include "project_header.h"
//class for SMA calculation
class SMA{

// private function for average calculation
float average(vector<float> data, int days){
	float average=0;
	for(int i=0;i<days;i++){
		average += data[i];
	}
	cout<< average/4<<endl;
	return average/4;
}

//public function for SMA calculation
public:
vector<float> SMA_n(vector<float> data,int days){
 
 float avg = average(data,days);
 return data;
}
};
