//calculate buy and sell signals
#include "project_header.h"
#include "SMA.h"


#ifndef BuySellSignal_H
#define BuySellSignal_H

class BuySellSignal:public SMA{

vector<float> signal1;

void Signal(SMA obj1, SMA obj2){
    
    int t1, t2;
    if(obj1.data_temp.size() > obj2.data_temp.size()){
        t1 = obj2.data_temp.size();
        t2 = obj1.data_temp.size();
    }
    else{
        t2 = obj2.data_temp.size();
        t1 = obj1.data_temp.size();
    }
    
    //Buy and Sell Signal
    for(int i=1;i<t1-1;i++){
        if(obj1.data_temp[i-1]<obj2.data_temp[t2-t1-1+i] && obj1.data_temp[i+1]>obj2.data_temp[t2-t1+1+i]){
            signal1.push_back(-1);
        }
        else if(obj1.data_temp[i-1]>obj2.data_temp[t2-t1-1+i] && obj1.data_temp[i+1]<obj2.data_temp[t2-t1+1+i]){
            signal1.push_back(1);  
        }

        else
        signal1.push_back(0); 

    }


    //signal
    for(int i=1;i<signal1.size();i++){
        signal.push_back(signal1[i] - signal1[i-1]);
        
    }
    
}


void Signal(vector<float> input1, vector<float> input2){
    
    int t1, t2;
    if(input1.size() > input2.size()){
        t1 = input2.size();
        t2 = input1.size();
    }
    else{
        t2 = input2.size();
        t1 = input1.size();
    }
    
    //Buy and Sell Signal
    for(int i=1;i<t1-1;i++){
        if(input1[i-1]<input2[t2-t1-1+i] && input1[i+1]>input2[t2-t1+1+i]){
            signal1.push_back(-1);
        }
        else if(input1[i-1]>input2[t2-t1-1+i] && input1[i+1]<input2[t2-t1+1+i]){
            signal1.push_back(1);  
        }

        else
        signal1.push_back(0); 

    }


    //signal
    for(int i=1;i<signal1.size();i++){
        signal.push_back(signal1[i] - signal1[i-1]);
        
    }
    
}


public:

vector<float> signal;

void Signal_trigger(SMA obj1, SMA obj2){
Signal(obj1,obj2);
}

void Signal_trigger(vector<float> input1, vector<float> input2){
Signal(input1,input2);
}

void getsignal(){
   for(int i=1;i<signal.size();i++){
        cout<<i<<" "<<signal[i]<<endl;
    } 
}

};

#endif