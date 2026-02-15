#pragma once
#include<iostream>
#include"clsScreen.h"
#include<string>
#include"clsInputValidate.h"
#include"clsBankClient.h"



class clsTransferScreen : protected clsScreen
{

	static void _PrintClientCard(clsBankClient Client)
	{
		cout<<"\nClient Card: ";
		cout<<"\n---------------------------------";
		cout<<"\nFullName		 :"<<Client.FullName();
		cout<<"\nAccountNumber		 :"<<Client.AccountNumber();
		cout<<"\nAccountBalacne		 :"<<Client.AccountBalance;
		cout<<"\n---------------------------------";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "" ;
		cout<<"\nPlease Enter AccountNumber to Transfer From: ";
		AccountNumber = clsInputValidate::ReadStreing();

		while (!clsBankClient::IsClientExists(AccountNumber))
		{
			cout<<"\nClient with  "<<AccountNumber<<"] does not exist. Enter Another AccountNumber: ";
			AccountNumber = clsInputValidate::ReadStreing();

		}

		return AccountNumber ;

	}


public:


	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\n\t\t\t\tTransfer Screen ");
		
	
		clsBankClient SourceClinet = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(SourceClinet);

		clsBankClient DestiantionClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(DestiantionClient);



		
		float Amount = 0 ;
		cout<<"\n\nPlase Enter Transfer amount? ";
		Amount = clsInputValidate::ReadDbleNumberBetween(1 , SourceClinet.AccountBalance , "\nAmount Exceeds the availbale Balancce, Plase Enter Another amount?  ");

		char Anser = 'Y';
		cout<<"\nAre you sure you want to perform this transaction? [Y/N] :  ";
		cin>>Anser;

		if(tolower( Anser == 'y'))
		{
			if(SourceClinet.Transfer(Amount ,DestiantionClient , CurrntUser.UserName ))
			{
				cout<<"\nTransfer done Successfuly.\n";

				

			}else
			{
				cout<<"\nCannot Transfer :(\n";

			}

		}

				_PrintClientCard(SourceClinet);
				_PrintClientCard(DestiantionClient);
	}

	
};

