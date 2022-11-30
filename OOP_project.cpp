#include "project_header.h" 
#include "filehandling.h" 
#include "userchoice.h"
#include "PnL.h"
#include "MACD.h"


int main()
{

	
	vector<float>date;        //vector for date field
	vector<float>price;       //vector for price field
    handlefile(date,price);

	/*
	switch (userchoice())
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
		pnlobj1.avgPnL();
	}
	
	default:
	{
		cout<<"\n Error: Please enter correct option"<<endl;
		break;
	}
	}
	*/

		// MACD Testing
		SMA obj1,obj2;
		obj1.put_data(price);
		obj2.put_data(price);
		obj1.SMA_trigger(26);
		obj2.SMA_trigger(12);
		
		MACD objj1;
		
		objj1.MACD_Signal(obj1,obj2);
		objj1.getsignal();
	
		SMA objsignal;
    	objsignal.put_data(objj1.MACD_line);
		objsignal.SMA_trigger(9);

		PnL tobj1;
		tobj1.Signal_trigger(objsignal.data_temp, objj1.MACD_line);
		tobj1.getsignal();
		tobj1.trigger_Positions(price);
		tobj1.trigger_PnL(price);
		tobj1.avgPnL();
		

}

