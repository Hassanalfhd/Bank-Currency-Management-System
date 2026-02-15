#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

	static void _ReadClientInfo(clsBankClient &Client)
	{

		cout<<"\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadStreing();

		cout<<"\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadStreing();

		cout<<"\nEnter Email: ";
		Client.Email = clsInputValidate::ReadStreing();


		cout<<"\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadStreing();

		cout<<"\nEnter PinCode:";
		Client.PinCode = clsInputValidate::ReadStreing();
	
		cout<<"\nEnter AccountBalance:";
		Client.AccountBalance = clsInputValidate::ReadFloateNumber();

	
	}

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

	static void ShowUpdateClientScreen()
	{
		
		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}

		
		
		_DrawScreenHeader("\n\t\t\t\tUpdate Client Screen");

		string AccountNumber = "" ;
		cout<<"Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadStreing();

		while (!clsBankClient::IsClientExists(AccountNumber))
		{
			cout<<"your AccountNumber is fail Please, Enter AccountNumber agine: ";
		AccountNumber = clsInputValidate::ReadStreing();
		}

		clsBankClient Client1  = clsBankClient::Find(AccountNumber);
		//
		_PrintClientCard(Client1);
	
		char Anser = 'Y' ;

		cout<<"\nAre you sure you want Update this User:[Y/N]: ";
		cin>>Anser;

		if(Anser == 'Y' || Anser == 'y')
		{
			cout<<"\nUpdate info: ";
			cout<<"\n----------------------------\n";
	
			_ReadClientInfo(Client1);

			clsBankClient::enSaveRueslt SaveRueslt ;

			SaveRueslt = Client1.Save();

	
			switch (SaveRueslt)
			{
				case clsBankClient::svSccsuuded:
					{
						cout<<"\nAccount Updated Successfully :-)\n";

						_PrintClientCard(Client1);
							break;
					}

					case clsBankClient::svFaildEmptyObject  :
					{
						cout<<"\nError account was not saved because it's Empty\n";

						break;
					}


			}
		}
	}

};

