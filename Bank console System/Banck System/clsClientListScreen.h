#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsUser.h"


using namespace std;

class clsClientListScreen : protected clsScreen 
{

private:

	static void _PrintClientRecord(clsBankClient Client)
	{

		cout<<setw(8)<<left<<""<<"| "<<left<<setw(15)<<Client.AccountNumber();
		cout<<"| "<<setw(20)<<left<<Client.FullName();
		cout<<"| "<<setw(12)<<left<<Client.Email;
		cout<<"| "<<setw(20)<<left<<Client.Phone;
		cout<<"| "<<setw(10)<<left<<Client.PinCode;
		cout<<"| "<<setw(12)<<left<<Client.AccountBalance;

	}

public:

	static void ShowClientsList()
{
		
		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pListClient))
		{
			return;
		}

	
	
		vector<clsBankClient>vClients = clsBankClient::GetClientList();

		string Title = " Client List Screen" ;
		string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vClients.size()) + ") Client(s)";
		
		_DrawScreenHeader(Title , SubTitle);
		cout<<"\n\t======================================================================================================\n";
		cout<<setw(8)<<left<<""<<"| "<<setw(12)<<left<<"Account Number";
		cout<<"| "<<left<<setw(20)<<"Client Name";
		cout<<"| "<<left<<setw(12)<<"Email";
		cout<<"| "<<left<<setw(20)<<"Phone";
		cout<<"| "<<left<<setw(10)<<"PinCode";
		cout<<"| "<<left<<setw(12)<<"Balance";
		cout<<setw(8)<<left<<" "<<"\n\t====================================================================================================\n";


		if(vClients.size() == 0)
			cout<<"\t\t\t\tNo Clients Avablie In The System!";
		else
		{
			for(clsBankClient &C : vClients)
				{
			
					_PrintClientRecord(C);
			
	
					cout<<endl;
			}
	}

	

	cout<<setw(8)<<left<<" "<<"\n\t============================================================================================\n";

	double ToatleBalance = clsBankClient::GetToatleBalance();
	cout<<"\t\t\t\t\t\tThe ToatleBalance is: "<<ToatleBalance<<endl;
	cout<<"\t\t\t\t\t\t( "<<clsUtil::NumberToText(ToatleBalance)<<")\n";
}


	
};

