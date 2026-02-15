#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCalcultorCurrencyScreen.h"

class clsCurrencyExchangeScreen : protected  clsScreen
{

	static int _ReadCurrencyExchangeMenue()
	{
		cout<<"\t\t\Choice From 1 To 5 : ";

		return clsInputValidate::ReadIntNumberBetween(1 , 5 , "\n\t\t\tinValid Number, Choice Another Number:  ");
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout<<"List Currencies Screen will be her\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout<<"Find Currency Screen will be her\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout<<"Update Rate Screen will be her\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCalcultorCurrencyScreen()
	{
		//cout<<"Update Rate Screen will be her\n";
		clsCalcultorCurrencyScreen::ShowCalcultorCurrencyScreen();
	}


	static void _GoBackToCurrencyExchangeMenue()
	{
		cout<<"\n\t\t\tprees Any key to back currency exchange menue. ";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	enum enCurrencyExchangeOption
	{
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateRate = 3, eCalcultorCurrency = 4, eMainMenue = 5 
	};


	static void _PerformCurrencyExchangeMenueOptin(enCurrencyExchangeOption CurrencyExchangeOption )
	{

		switch (CurrencyExchangeOption)
		{
		case clsCurrencyExchangeScreen::eCurrenciesList:
			{
				system("cls");
				_ShowCurrenciesListScreen();
				_GoBackToCurrencyExchangeMenue();
				break;
			}

		case clsCurrencyExchangeScreen::eFindCurrency:
			{
				system("cls");
				_ShowFindCurrencyScreen();
				_GoBackToCurrencyExchangeMenue();
				break;
			}



		case clsCurrencyExchangeScreen::eUpdateRate:
			{
				system("cls");
				_ShowUpdateRateScreen();
				_GoBackToCurrencyExchangeMenue();
				break;
			}

		case clsCurrencyExchangeScreen::eCalcultorCurrency:
			{
				system("cls");
				_ShowCalcultorCurrencyScreen();
				_GoBackToCurrencyExchangeMenue();
				break;
			}

		case clsCurrencyExchangeScreen::eMainMenue:
			{
				// there is not  code her ;
			}


		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{

		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

			system("cls");
		_DrawScreenHeader(" Currency Exchange  Menue ");

		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\tCurrency Exchange Menue Secren \n";
		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\t(1)- List Currencies.\n";
		cout<<"\t\t\t\t\t(2)- Find Currency\n";
		cout<<"\t\t\t\t\t(3)- Update Rate.\n";
		cout<<"\t\t\t\t\t(4)- Currency Calculator.\n";
		cout<<"\t\t\t\t\t(5)- Main Menue.\n";
		cout<<"\t\t\t========================================================\n";

		_PerformCurrencyExchangeMenueOptin((enCurrencyExchangeOption)_ReadCurrencyExchangeMenue());
	}


};