#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;


class clsAddNewClientScreen : protected clsScreen
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

	static void ShowAddNewClientScreen()
	{
		

		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}


		_DrawScreenHeader("\n\t\t\t\t\tAdd New Client Screen");
	string AccountNumber = "" ;

	cout<<"Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadStreing();

	while (clsBankClient::IsClientExists(AccountNumber))
	{

		cout<<"The Client Already Exists, enter anther accountNumber: ";
		AccountNumber = clsInputValidate::ReadStreing();

	}

	clsBankClient Client1 = clsBankClient::GetAddNewClientObject(AccountNumber);


	_ReadClientInfo(Client1);

	clsBankClient::enSaveRueslt SaveRueslt ;

	SaveRueslt = Client1.Save();

	switch (SaveRueslt)
	{
		case clsBankClient::svFaildEmptyObject  :
		{
			cout<<"\nError account was not saved because it's Empty\n";

			break;
		}

		case clsBankClient::svSccsuuded:
		{
			cout<<"\nAccount Updated Successfully :-)\n";

			_PrintClientCard(Client1);
				break;
		}
		case clsBankClient::svFaildAccountNumberExists  :
		{
			cout<<"\nthe  AccountNumber is Exists\n";

			break;
		}


	

}

	}


};

