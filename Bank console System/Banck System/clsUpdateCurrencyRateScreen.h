#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsUser.h"

class clsUpdateCurrencyRateScreen : protected clsScreen 
{
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout<<"\nCurrency Card: ";
		cout<<"\n========================================================\n";
		cout<<"\nCountry		: "<<Currency.Country();
		cout<<"\nCurrencyCode	: "<<Currency.CurrencyCode();
		cout<<"\nCurrencyName	: "<<Currency.CurrencyName();
		cout<<"\nRate ($1) =	: "<<Currency.Rate();
		cout<<"\n========================================================\n";
	
	}

	static float _ReadRate()
	{
			cout<<"\nUpdate Currency Rate : ";
			cout<<"\n---------------------------------";
			cout<<"\nEnter New Rate: ";
			float NewRate = clsInputValidate::ReadFloateNumber();
			return NewRate ;
	}

	static clsCurrency _GetCurrecy(string Messag)
	{
		cout<<Messag;
		string CurrencyCode = clsInputValidate::ReadStreing();

		while(!clsCurrency::IsExist(CurrencyCode))
		{
				cout<<"\nThe CurrencyCode "<<CurrencyCode<<"is not Exist,Please Enter Anther CurrencyCode ? ";
				 CurrencyCode = clsInputValidate::ReadStreing();
		}
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		return Currency ;
	}
public:

	static void ShowUpdateCurrencyRateScreen()
	{
		
			system("cls");
		_DrawScreenHeader(" Currency Exchange  Menue ");


		clsCurrency Currency = _GetCurrecy("\nPlease Enter CurrencyCode ? ");
		
		_PrintCurrencyRecord(Currency);

		char Anser = 'Y';
		cout<<"\nAre you sure you want to update the rate od this currency [Y/N]: ";
		cin>>Anser;

		if( Anser == 'Y' || Anser == 'y' )
		{

			Currency.UpdateRaet(_ReadRate());

			cout<<"\nCurrency Rate Update successfully :-) \n";
		
			_PrintCurrencyRecord(Currency);
		}

	}

};

