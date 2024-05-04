//compute notional values
//compute PnL

#include "project_header.h"
#include "Position.h"

#ifndef PnL_H
#define PnL_H

class PnL:public Position{

vector<int> notional;

void PnL_cal(vector<float> price_temp){

//notional
int k1=0;
for(int i=(price_temp.size() - quantity_temp.size());i<price_temp.size();i++){
 notional.push_back(-price_temp[i]*quantity_temp[k1]);
 k1++;
}

//cummulative notional
for(int i=1;i<notional.size();i++){
    notional[i] = notional[i-1] + notional[i];
    //cout<<notional[i]<<endl;
}

//profit and loss daily
int k2=0;
int PnL;
for(int i=(price_temp.size() - quantity_temp.size());i<price_temp.size();i++){
 PnL = notional[k2] - (price_temp[i]*quantity_temp[i]);
 PnL_value.push_back(PnL);
 k2++;
}


}


public:
vector<int> PnL_value;
void trigger_PnL(vector<float> price_temp){
        PnL_cal(price_temp);    
}

void getPnL(){
    for(int i=0;i<PnL_value.size();i++){
        cout<<i+1<<" "<<PnL_value[i]<<endl;
    }

}

void avgPnL(){
    float PnL_avg = 0;
    for(int i=0;i<PnL_value.size();i++)
        PnL_avg += PnL_value[i];
    cout<<PnL_avg/PnL_value.size()<<endl;

}

};

#endif