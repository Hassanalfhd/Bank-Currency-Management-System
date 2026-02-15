#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsMenueScreen.h"
#include"clsManageUserMenueScreen.h"
#include"clsLogRegisterScreen.h"
#include"clsCurrencyExchangeScreen.h"
#include"clsGlobal.h"

using namespace std; 

class clsMainMenueScreen : protected clsScreen
{

	static int _ReadMainMenueOption()
	{
		cout<<"\t\t\Choice From 1 To 10 : ";
		return clsInputValidate::ReadIntNumberBetween(1 , 10 , "\n\t\t\tinValid Number, Choice Another Number:  ");
	}

	static void _ShowListClientScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddClientScreen()
	{
		//cout<<"Her is AddClient Client Screen \n";
		clsAddNewClientScreen::ShowAddNewClientScreen();

	}

	static void _ShowDeleteClientScreen()
	{
			//cout<<"Her is DeleteClient  Screen \n";
			clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdataClientScreen()
	{
		//cout<<"Her is DeleteClient  Screen \n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout<<"Her is FindClient  Screen \n";

		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		//cout<<"Her is Transactions  Screen \n";
		clsTransactionsMenueScreen::ShowTransactionsMenueScreen();
		
	}

	static void _ShowManageUsersScreen()
	{
		//cout<<"Her is ManageUsers  Screen \n";
		clsManageUserMenueScreen::ShowMangaeUsersMenueScreen();
	}

	static void _ShowClientsList()
{
		vector<clsBankClient>vClients = clsBankClient::GetClientList();

		
	cout<<"\n\t\t\t Client List ("<<vClients.size()<<") Client(s).\n";
	cout<<"\n==============================================================================================================\n";
	cout<<"| "<<setw(12)<<left<<"Account Number";
	cout<<"| "<<setw(20)<<left<<"Client Name";
	cout<<"| "<<setw(12)<<left<<"Email";
	cout<<"| "<<setw(12)<<left<<"Phone";
	cout<<"| "<<setw(12)<<left<<"PinCode";
	cout<<"| "<<setw(12)<<left<<"Balance";
	cout<<"\n===============================================================================================================\n";


	for(clsBankClient &C : vClients)
	{
		
		
		cout<<"| "<<setw(12)<<left<<C.AccountNumber();
		cout<<"| "<<setw(20)<<left<<C.FullName();
		cout<<"| "<<setw(12)<<left<<C.Email;
		cout<<"| "<<setw(12)<<left<<C.Phone;
		cout<<"| "<<setw(12)<<left<<C.PinCode;
		cout<<"| "<<setw(12)<<left<<C.AccountBalance;


			cout<<endl;
	}

	cout<<"\n=======================================================================================================\n";
	

}

	static void _GoBackToMainMenue()
	{
		cout<<"\n\t\t\tprees Any key to back main menue. ";
		system("pause>0");
		ShowMainMenueScreen();
	}

	/*static void _EndProgrimming()
	{
		cout<<"\n\t\t\tThank You For Used My Applaction :-) I'm Happay :->)";
		system("pause>0");
		
	}*/


	static void _ShowLoginRegisterScreen()
	{
		//cout<<"Login Register Screen will be her\n";
		clsLogRegisterScreen::ShowLogRegisterList();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}


	static void  _Loguot()
	{

		CurrntUser = clsUser::Find("" , "");

	}


	enum _eMainMenueOption
	{
		eListClient = 1 ,   eAddClient = 2,
		eDeleteClient = 3, eUpdataClient = 4,
		eFindClient = 5,    eTransactions = 6,
		eManageUsers = 7,  eLogRegister = 8 , eCurrencyExchange = 9,  eLogout = 10
	};

	static void _PerformMainMenueOptin(_eMainMenueOption MainMenueOption)
	{

		switch (MainMenueOption)
		{
		case clsMainMenueScreen::eListClient:
			{
				system("cls");
				_ShowListClientScreen();
				_GoBackToMainMenue();
				break;

			}

		case clsMainMenueScreen::eAddClient:
			{

				system("cls");
				_ShowAddClientScreen();
				_GoBackToMainMenue();
				break;
			}
		case clsMainMenueScreen::eDeleteClient:
			{
				system("cls");
				_ShowDeleteClientScreen();
				_GoBackToMainMenue();
				break;
			}

		case clsMainMenueScreen::eUpdataClient:
			{

			
				system("cls");
				_ShowUpdataClientScreen();
				_GoBackToMainMenue();
				break;

			}

		case clsMainMenueScreen::eFindClient:
			{
				system("cls");
				_ShowFindClientScreen();
				_GoBackToMainMenue();
				break;

			}

		case clsMainMenueScreen::eTransactions:
			{
				system("cls");
				_ShowTransactionsScreen();
				_GoBackToMainMenue();
				break;
			}

		case clsMainMenueScreen::eManageUsers:
			{
				system("cls");
				_ShowManageUsersScreen();
				_GoBackToMainMenue();
				break;
			}

		case clsMainMenueScreen::eLogRegister:
			{
				system("cls");
				_ShowLoginRegisterScreen();
				_GoBackToMainMenue();
				break;
			}

			
		case clsMainMenueScreen::eCurrencyExchange:
			{
				system("cls");
				_ShowCurrencyExchangeScreen();
				_GoBackToMainMenue();
				break;
			}


		case clsMainMenueScreen::eLogout:
			{
				system("cls");
				_Loguot();
				break;
			}

		}
	}


public:



	static void ShowMainMenueScreen()
	{

		system("cls");

		_DrawScreenHeader(" Main Menue ");

		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\tMain Menue Secren \n";
		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\t(1)- Show Client List.\n";
		cout<<"\t\t\t\t\t(2)- Add New Client\n";
		cout<<"\t\t\t\t\t(3)- Delete Client.\n";
		cout<<"\t\t\t\t\t(4)- UpData Client Info.\n";
		cout<<"\t\t\t\t\t(5)- Find Client.\n";
		cout<<"\t\t\t\t\t(6)- Transactions.\n";
		cout<<"\t\t\t\t\t(7)- Manage Users.\n";
		cout<<"\t\t\t\t\t(8)- Login Register.\n";
		cout<<"\t\t\t\t\t(9)- Currency Exchange.\n";
		cout<<"\t\t\t\t\t(10)- Logout.\n";
		cout<<"\n\t\t\t=========================================================\n";

		_PerformMainMenueOptin((_eMainMenueOption)_ReadMainMenueOption());

	}



};

