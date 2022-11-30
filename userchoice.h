#include "project_header.h"

int userchoice(){
int choice;
	
	cout<<"Testing mean reversion strategy."<<endl;
	cout<<"What do you want to achieve today?"<<endl;
	cout<<"1: Moving Average Signals"<<endl;
	cout<<"2: Buy and Sell Signals"<<endl;
	cout<<"3: Daily Positions"<<endl;
	cout<<"4: Daily Profit and Loss"<<endl;
	cout<<"5: Average Profit and Loss of the Strategy"<<endl<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
return choice;
}