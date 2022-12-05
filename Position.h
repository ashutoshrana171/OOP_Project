// calculate daily positions with signal data

#include "project_header.h"
#include "BuySell_signal.h"


#ifndef Position_H
#define Position_H

class Position: public BuySellSignal{

void Daily_Quantity(vector<float> price_temp){

float amount;
int quantity;
cout<<"Enter investment amount: ";
cin>>amount;

int k=0;
for(int i=(price_temp.size() - signal.size());i<price_temp.size();i++){
 quantity = (amount/price_temp[i])*signal[k];
 quantity_temp.push_back(quantity);
 k++;
}

Daily_Position();
}


void Daily_Position(){
    position_temp.push_back(0);
    
    for(int i=1;i<quantity_temp.size();i++)
    position_temp.push_back(position_temp[i-1] + quantity_temp[i]);
}

public:

vector<int> quantity_temp;
vector<int> position_temp;

void trigger_Positions(vector<float>price_temp){
    Daily_Quantity(price_temp);
}

void getpositions(){
    for(int i=0;i<position_temp.size();i++){
        cout<<i+1<<" "<<position_temp[i]<<endl;
    }
}
};

#endif