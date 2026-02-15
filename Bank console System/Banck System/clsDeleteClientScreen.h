#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsScreen.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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


	static void ShowDeleteClientScreen()
	{


		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}


		_DrawScreenHeader("\n\t\t\t\t\tDelete Client Screen");
		
		string AccountNumber = "" ;

		cout<<"Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadStreing();

		while (!clsBankClient::IsClientExists(AccountNumber))
		{

			cout<<"The Client Is Not Found, enter anther accountNumber: ";
			AccountNumber = clsInputValidate::ReadStreing();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		
		_PrintClientCard(Client1);


		char Anser = 'n';
		cout<<"\n\nAre sure you want to delete the Client[Y\\N]: ";
		cin>>Anser ;

		if(Anser == 'Y' || Anser == 'y')
		{

			if(Client1.Delete())
			{
				cout<<"Client Delete successfuly :-)\n";
				_PrintClientCard(Client1);
			}else
			{
				cout<<"Erorr Client was not  Deleted :-(\n";

			}

		}



	}


	
};

