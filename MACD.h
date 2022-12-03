//calculate MACD

#include "project_header.h"
#include "SMA.h"

#ifndef MACD_H
#define MACD_H

class MACD:public SMA{

public:
vector<float> MACD_line;
//vector<float> MACD_signal;




//vector<float> signal;

void MACD_Signal(SMA obj1, SMA obj2){
    
    
    int t1 = obj1.data_temp.size();
    int t2 = obj2.data_temp.size();
    
    
    //MACD line
    for(int i=0;i<t1;i++){
        MACD_line.push_back(obj1.data_temp[i]-obj2.data_temp[t2-t1+i]);
    }

    //MACD signal
    

    //Buy/Sell Signal
    
    /*
    for(int i=1;i<t1-1;i++){
        if(objsignal.data_temp[i-1]<MACD_line[t2-t1-1+i] && objsignal.data_temp[i+1]>MACD_line[t2-t1+1+i]){
            MACD_signal.push_back(-1);
        }
        else if(objsignal.data_temp[i-1]>MACD_line[t2-t1-1+i] && objsignal.data_temp[i+1]<MACD_line[t2-t1+1+i]){
            MACD_signal.push_back(1);  
        }

        else
        MACD_signal.push_back(0); 

    }
    //signal
    for(int i=1;i<MACD_signal.size();i++){
        signal.push_back(MACD_signal[i] - MACD_signal[i-1]);
        
    }
*/

    

}

void getsignal(){
   for(int i=1;i<MACD_line.size();i++){
        cout<<i<<" "<<MACD_line[i]<<endl;
    } 
}


};

#endif