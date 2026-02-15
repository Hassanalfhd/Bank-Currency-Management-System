#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"


class clsFindCurrencyScreen : protected clsScreen
{

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout<<"\nCurrency Card: ";
		cout<<"\n========================================================\n";
		cout<<"\nCountry		: "<<Currency.Country();
		cout<<"\nCurrencyCode	: "<<Currency.CurrencyCode();
		cout<<"\nCurrencyName	: "<<Currency.CurrencyName();
		cout<<"\nRate ($1) = : "<<Currency.Rate();
		cout<<"\n========================================================\n";
	
	}


	static void _ShowResult(clsCurrency Currency)
	{
		
		if(!Currency.IsEmpty())
		{
			cout<<"\nCurrency Found :-)";
			_PrintCurrencyRecord(Currency);

		}else
		{
			cout<<"\nCurrency Not Found :-(";

		}
	}

public:

	static void ShowFindCurrencyScreen()
	{

				system("cls");
		_DrawScreenHeader(" Find Currency   Screen ");

		cout<<"\n\n Find By: [1] Code or [2] Country ? ";
		int Anser =  clsInputValidate::ReadIntNumberBetween(1 , 2 , "vaild Number. ?");
		
		if(Anser == 1)
		{
			cout<<"Please Enter CurrencyCode ?";
			string Code = clsInputValidate::ReadStreing();
		
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(Code);

			_ShowResult(Currency);

		}else
		{
			cout<<"Please Enter Country Name ?";
			string Country = clsInputValidate::ReadStreing();

		
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);

		}

		

	}

			
};

