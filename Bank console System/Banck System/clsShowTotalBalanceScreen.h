#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsUtil.h"



class clsShowTotalBalanceScreen : protected clsScreen
{

	static void _PrintClientRecord(clsBankClient Client)
	{

		cout<<setw(18)<<left<<""<<left<<setw(15)<<Client.AccountNumber();
		cout<<"| "<<setw(30)<<left<<Client.FullName();
		cout<<"| "<<setw(20)<<left<<Client.AccountBalance;

	}
public:



	static void ShowTotalBalanceScreen()
	{

			vector<clsBankClient>vClients = clsBankClient::GetClientList();

			string Title = " Total Balance Screen" ;
			string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vClients.size()) + ") Client(s)";
		
			_DrawScreenHeader(Title , SubTitle);
		cout<<"\n\t\t===========================================================================================\n";
		cout<<setw(18)<<left<<" "<<setw(12)<<left<<"Account Number";
		cout<<"| "<<left<<setw(30)<<"Client Name";
		cout<<"| "<<left<<setw(20)<<"Balance";
		cout<<setw(18)<<left<<" "<<"\n\t\t=====================================================================================\n";


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

	

		cout<<setw(18)<<left<<" "<<"\n\t\t==================================================================================\n";

		double ToatleBalance = clsBankClient::GetToatleBalance();
		cout<<"\t\t\t\t\t\tThe ToatleBalance is: "<<ToatleBalance<<endl;
		cout<<"\t\t\t\t\t\t( "<<clsUtil::NumberToText(ToatleBalance)<<")\n";
	}


};

