#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"


class clsDepositScrreen : protected clsScreen
{
	
	static void _PrintClientCard(clsBankClient Client)
	{
		cout<<"\nClient Card: ";
		cout<<"\n---------------------------------";
		cout<<"\nAccountNumber		 :"<<Client.AccountNumber();
		cout<<"\nFirstName		 :"<<Client.FirstName;
		cout<<"\nLastName		 :"<<Client.LastName;
		cout<<"\nFullName		 :"<<Client.FullName();
		cout<<"\nEnail			 :"<<Client.Email;
		cout<<"\nPhone			 :"<<Client.Phone;
		cout<<"\nPinCode			 :"<<Client.PinCode;
		cout<<"\nAccountBalacne		 :"<<Client.AccountBalance;
		cout<<"\n---------------------------------";

	}


	static string _ReadAccountNumber()
	{
		string AccountNumber = "" ;

		AccountNumber = clsInputValidate::ReadStreing();

		return AccountNumber; 
	}


public:


	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\n\t\t\t\tDeposit Amount Screen");

		string AccountNumber = "" ;
		cout<<"\nEnter AccountNumber? ";
		AccountNumber = _ReadAccountNumber();

		if(!clsBankClient::IsClientExists(AccountNumber))
		{
			cout<<"\nClient with  "<<AccountNumber<<"] does not exist. \n";
			AccountNumber = _ReadAccountNumber();
		}


		clsBankClient Client1 = clsBankClient::Find(AccountNumber); 

		_PrintClientCard(Client1);


		double Amount = 0 ;
		cout<<"\nPlase enter deposit amount? ";
		Amount = clsInputValidate::ReadDbleNumber();

		char Anser = 'Y';
		cout<<"\nAre you sure you want to perform this transaction? ";
		cin>>Anser;


		if(tolower( Anser == 'y'))
		{
			Client1.Deposit(Amount);

			cout<<"\nAmount Deposited Successfuly.\n";
			cout<<"New Balance Is : "<<Client1.AccountBalance;
			
		}
		else
		{
			cout<<"\nOperation was cancelled. \n";
		}
	}

	
};

