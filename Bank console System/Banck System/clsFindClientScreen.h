#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen()
	{
		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		
		_DrawScreenHeader("\n\t\t\t\t\tFind Client Screen");

		string AccountNumber = "" ;

		cout<<"Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadStreing();


		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client1);

		if(!Client1.IsEmpty())
		{
			cout<<"\nClient Found :-)\n";
		}else
		{
			cout<<"\nClient is Not  Found :-(\n";

		}

	}

	
};

