#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScrreen.h"
#include"clsWithdrawScreen.h"
#include"clsShowTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include"clsUser.h"


using namespace std ; 

class clsTransactionsMenueScreen : protected clsScreen
{

	static int _ReadTransctionMenueOpation()
	{
		int Option = 0 ; 
		cout<<"\t\t\t\tChoice From 1 To 6 : ";
		Option = clsInputValidate::ReadIntNumberBetween(1 , 6 , "\t\t\t\tVailed Number, Choice Another Option: ");
		return Option;
	}
	
	static void _GoBackToTransctionMenue()
	{
		cout<<"\n\nprass any key to back Transction menue....";
		system("pause>0");
		ShowTransactionsMenueScreen();
	}


	static void _ShowToataleListScreen()
	{
		//cout<<"Her is Show Toatale List Screen";
		clsShowTotalBalanceScreen::ShowTotalBalanceScreen();
	}

	static void _ShowDepositScreen()
	{
		//cout<<"Her is Show Deposit  Screen";
		clsDepositScrreen::ShowDepositScreen();

	}

	static void _ShowWithdrawScreen()
	{
		//cout<<"Her is Show Withdraw  Screen";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout<<"Her is Show Transfer  Screen";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogFileScreen()
	{

		//cout<<"Her is Show Transfer Log File Screen";
		clsTransferLogScreen::ShowTransferLogScreen();

	}



	enum _enTransctionMenueOpation
	{
		eToatalBalance= 3, eDeposit = 1, eWithdraw = 2, eTransfer = 4,eTransferLogFile = 5, eMainMenue = 6
	};

	static void _PerformTransctiosMenueOptin(_enTransctionMenueOpation TransctionMenueOpation )
	{
		switch (TransctionMenueOpation)
		{
		case clsTransactionsMenueScreen::eToatalBalance:
			{
				system("cls");
				_ShowToataleListScreen();
				_GoBackToTransctionMenue();
				break;

			}

		case clsTransactionsMenueScreen::eDeposit:
			{
		
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransctionMenue();
				break;

			}

		case clsTransactionsMenueScreen::eWithdraw:
			{

		 	system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransctionMenue();
				break;
			}

			case clsTransactionsMenueScreen::eTransfer:
			{

		 		system("cls");
				_ShowTransferScreen();
				_GoBackToTransctionMenue();
				break;
			}

			case clsTransactionsMenueScreen::eTransferLogFile:
			{

		 		system("cls");
				_ShowTransferLogFileScreen();
				_GoBackToTransctionMenue();
				break;
			}

		case clsTransactionsMenueScreen::eMainMenue:
			{
				// Nothing write her
			}

		}
	}


public:

	static void ShowTransactionsMenueScreen()
	{
		
		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		
		system("cls");
		_DrawScreenHeader("Transactions Menue");

		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\tTransctions Menue Secren \n";
		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\t(1)- Depost \n";
		cout<<"\t\t\t\t\t(2)- Withdraw.\n";
		cout<<"\t\t\t\t\t(3)- Show Toatale Balance.\n";
		cout<<"\t\t\t\t\t(4)- Transfer.\n";
		cout<<"\t\t\t\t\t(5)- Transfer Log File.\n";
		cout<<"\t\t\t\t\t(6)- Main Menue.\n";
		cout<<"\n\t\t\t=========================================================\n";
	
		_PerformTransctiosMenueOptin((_enTransctionMenueOpation)_ReadTransctionMenueOpation());

	}

};

