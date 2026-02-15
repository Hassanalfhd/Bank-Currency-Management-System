#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"


class clsWithdrawScreen : protected clsScreen
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




public:


	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\n\t\t\t\tWithdraw Amount Screen");

		string AccountNumber = "" ;

		cout<<"\nEnter AccountNumber? ";

		AccountNumber =  clsInputValidate::ReadStreing();

		if(!clsBankClient::IsClientExists(AccountNumber))
		{
			cout<<"\nClient with  "<<AccountNumber<<"] does not exist. \n";
			AccountNumber =  clsInputValidate::ReadStreing();
		}


		clsBankClient Client1 = clsBankClient::Find(AccountNumber); 

		_PrintClientCard(Client1);


		double Amount = 0 ;
		cout<<"\nPlase enter Withdraw amount? ";
		Amount = clsInputValidate::ReadDbleNumberBetween(1 , Client1.AccountBalance , "\nThe amount bigger than Balance,Plase enter Withdraw amount?  ");

		char Anser = 'Y';
		cout<<"\nAre you sure you want to perform this transaction? ";
		cin>>Anser;


		if(tolower( Anser == 'y'))
		{
			if(Client1.Withdraw(Amount))
			{

			
				cout<<"\nAmount Withdraw Successfuly.\n";
			
				cout<<"New Balance Is : "<<Client1.AccountBalance;

			}
			else
			{
			
				cout<<"\nCannot Withdraw is : "<< Amount << "\n";
		
				cout<<"\nYour Balance  is : "<< Client1.AccountBalance << "\n";

			}
		}
	
		

	}

	
};


