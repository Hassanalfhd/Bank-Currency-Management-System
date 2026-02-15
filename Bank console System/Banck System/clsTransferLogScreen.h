#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include<string>
#include"clsBankClient.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{

	static void _PrintRegisterTransferLogRecord(clsBankClient::stRegisterTransferLog RegisterTransferLog )
	{

		cout<<setw(8)<<left<<""<<"| "<<left<<setw(20)<<RegisterTransferLog.Date;
		cout<<"| "<<setw(10)<<left<<RegisterTransferLog.SourceAccountNumber;
		cout<<"| "<<setw(10)<<left<<RegisterTransferLog.DestiantionAccountNumber;
		cout<<"| "<<setw(10)<<left<<RegisterTransferLog.Amount;
		cout<<"| "<<setw(10)<<left<<RegisterTransferLog.SourceAccountBalance;
		cout<<"| "<<setw(10)<<left<<RegisterTransferLog.DestiantionAccountBalance;
		cout<<"| "<<setw(10)<<left<<RegisterTransferLog.UserName;

	}

public:

	static void ShowTransferLogScreen()
	{



			vector<clsBankClient::stRegisterTransferLog>vRegisterTransferLog  = clsBankClient::GetRegisterTransferLog() ;

			string Title = " Transfer Log Register  Screen" ;
			string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vRegisterTransferLog.size()) + ") Record(s)";
		
			_DrawScreenHeader(Title , SubTitle);
		cout<<"\n\t======================================================================================================\n";
		cout<<setw(8)<<left<<""<<"| "<<setw(20)<<left<<"Date Time";
		cout<<"| "<<left<<setw(10)<<"Src AccN ";
		cout<<"| "<<left<<setw(10)<<"Dst AccN ";
		cout<<"| "<<left<<setw(10)<<"Amount";
		cout<<"| "<<left<<setw(10)<<"Src AccBal";
		cout<<"| "<<left<<setw(10)<<"Dst AccBal";
		cout<<"| "<<left<<setw(15)<<"UserName";
		cout<<setw(8)<<left<<" "<<"\n\t====================================================================================================\n";


		if(vRegisterTransferLog.size() == 0)
			cout<<"\t\t\t\tNo Log Register Avablie In The System!";
		else
		{
			for(clsBankClient::stRegisterTransferLog  &TransferLogRegisterRecord :vRegisterTransferLog)
				{
		
					_PrintRegisterTransferLogRecord(TransferLogRegisterRecord);
						cout<<endl;
				}
		}


		cout<<setw(8)<<left<<" "<<"\n\t============================================================================================\n";
	}
};

