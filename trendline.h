//to graph stuff out
/* TO DO:
improve with matplotlib
timescale graphs and data
*/

#ifndef trendline_H
#define trendline_H
#include "project_header.h"

class trendline{
    public:
    
    vector<float> pricedata;
    
    void put_data(vector<float> data){
            for(int i=0;i<data.size();i++)
            pricedata.push_back(data[i]);
    }

    void get_data(){
        for(int i=0;i<pricedata.size();i++)
            cout<<pricedata[i]<<endl;
    }

};

#endif