#include "trendline.h"
//class for SMA calculation

#ifndef SMA_H
#define SMA_H

class SMA:public trendline{

// private function for average calculation

float average(vector<float> pricedata, int days){
	float avg=0;
	for(int i=0;i<days;i++){
		avg += pricedata[i];

	}
	return avg/days;
} 

//function for SMA calculation
void SMA_n(int days){
 
 
 // set average to data[days-1]
 data_temp.push_back(average(pricedata,days));
 //cout<<"average"<<data_temp[0]<<endl;
 
 //apply SMA strategy
 int k=0;
 float smaprice;
 for(int j=days; j<pricedata.size(); j++){
    smaprice = (data_temp[k] - (2*data_temp[k])/(days+1)) + (pricedata[j]*2)/(days+1);
    data_temp.push_back(smaprice);
    k++;
 }

}


public:

vector<float> data_temp;

//overloaded function for indicators
void SMA_trigger(int day){
    SMA_n(day);
}

void SMA_trigger(){
    int day;
    cout<<"Enter day count of SMA signal: ";
    cin>>day;
    SMA_n(day);
}

void get_data(){
    cout<<"Day"<<"\t"<<"Price"<<endl;
    for(int i=0;i<data_temp.size();i++){
        cout<<(i+1)<<"\t"<<data_temp[i]<<endl;
    }
}

};

#endif