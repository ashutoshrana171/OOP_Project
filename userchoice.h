#include "project_header.h"

#ifndef userchoice_H
#define userchoice_H


int userchoice(int choice2){
int choice1;
	
	
	
	if (choice2==1)
	{
	cout<<"1: Moving Average Signals"<<endl;
	cout<<"2: Buy and Sell Signals"<<endl;
	cout<<"3: Daily Positions"<<endl;
	cout<<"4: Daily Profit and Loss"<<endl;
	cout<<"5: Average Profit and Loss of the Strategy"<<endl<<endl;
	cout<<"Enter your choice: ";
	}
	
	else if (choice2==2)
	{
	cout<<"MACD will use SMA signals of n=26 and n=12"<<endl;
	cout<<"2: Buy and Sell Signals"<<endl;
	cout<<"3: Daily Positions"<<endl;
	cout<<"4: Daily Profit and Loss"<<endl;
	cout<<"5: Average Profit and Loss of the Strategy"<<endl<<endl;
	cout<<"Enter your choice: ";
	}
	
	else{
		cout<<"Error: Invalid choice";
	}
	
	cin>>choice1;
return choice1;
}

#endif
