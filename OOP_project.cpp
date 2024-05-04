#include "project_header.h" 
#include "filehandling.h" 
#include "userchoice.h"
#include "PnL.h"
#include "MACD.h"


int main()
{

	int choice2;
	vector<float>date;        //vector for date field
	vector<float>price;       //vector for price field
    handlefile(date,price);

	// choice of trading strategy
	cout<<"Choose a trading strategy:"<<endl;
	cout<<"1. Mean Reversion"<<endl;
	cout<<"2. MACD technical indicator"<<endl;
	cout<<"Enter your choice:";
	cin>> choice2;
	try
	{
		if(choice2!=1 && choice2!=2)
		throw true;
	}
	catch(bool temp)
	{
		cout<<"Please enter correct choice";
		return 0;
	}
	
	
	cout<<endl<<endl<<"What do you want to achive today?"<<endl;

	//mean reversion strategy
	if(choice2==1){
	switch (userchoice(1))
	{
	case 1:
	{
		SMA obj1;
		obj1.put_data(price);
		obj1.SMA_trigger();
		obj1.get_data();
		break;
	}

	case 2:
	{
		SMA obj1,obj2;
		obj1.put_data(price);
		obj2.put_data(price);
		obj1.SMA_trigger();
		obj2.SMA_trigger();

		BuySellSignal objj1;
		objj1.Signal_trigger(obj1,obj2);
		objj1.getsignal();

		break;
	}

	case 3:
	{
		SMA obj1,obj2;
		obj1.put_data(price);
		obj2.put_data(price);
		obj1.SMA_trigger();
		obj2.SMA_trigger();
		
		

		Position pobj1;
		pobj1.Signal_trigger(obj1,obj2);
		pobj1.trigger_Positions(price);
		pobj1.getpositions();

		break;
	}

	case 4:
	{
		SMA obj1,obj2;
		obj1.put_data(price);
		obj2.put_data(price);
		obj1.SMA_trigger();
		obj2.SMA_trigger();
		
		PnL pnlobj1;
		pnlobj1.Signal_trigger(obj1,obj2);
		pnlobj1.trigger_Positions(price);
		pnlobj1.trigger_PnL(price);
		pnlobj1.getPnL();
		
		break;
	}

	case 5:
	{
		
		SMA obj1,obj2;
		obj1.put_data(price);
		obj2.put_data(price);
		obj1.SMA_trigger();
		obj2.SMA_trigger();
		
		PnL pnlobj1;
		pnlobj1.Signal_trigger(obj1,obj2);
		pnlobj1.trigger_Positions(price);
		pnlobj1.trigger_PnL(price);
		cout<<"Average PnL of the strategy is: ";
		pnlobj1.avgPnL();
		break;
	}
	
	default:
	{
		cout<<"\n Error: Please enter correct option"<<endl;
		break;
	}
	}
	}

	//MACD strategy
	if(choice2==2){
		
		SMA obj1,obj2;
		obj1.put_data(price);
		obj2.put_data(price);
		obj1.SMA_trigger(26);
		obj2.SMA_trigger(12);	
		
		MACD objj1;
		SMA objsignal;
		PnL tobj1;
		objj1.MACD_Signal(obj1,obj2);
		objsignal.put_data(objj1.MACD_line);
		objsignal.SMA_trigger(15);
		tobj1.Signal_trigger(objsignal.data_temp, objj1.MACD_line);
		
		switch (userchoice(2))
		{
		case 2: {
		tobj1.getsignal();
		break;
		}
		
		case 3:
		{
		
		tobj1.trigger_Positions(price);
		tobj1.getpositions();
		break;
		}
		case 4:
		{
		tobj1.trigger_Positions(price);
		tobj1.trigger_PnL(price);
		tobj1.getPnL();
		break;
		}

		case 5:
		{
		tobj1.trigger_Positions(price);
		tobj1.trigger_PnL(price);
		cout<<"Average PnL of the strategy is: ";
		tobj1.avgPnL();
		break;}
			
			default:{
			cout<<"\n Error: Please enter correct option"<<endl;
			break;
			}
		}
	}

}

