#include "project_header.h" 
#include "filehandling.h" 
#include "SMA.h"

int main()
{

	
	vector<float>date;        //vector for date field
	vector<float>price;       //vector for price field
    handlefile(date,price);

	SMA obj1;
	obj1.SMA_n(price,20);
	obj1.SMA_n(price,10);
	

}

