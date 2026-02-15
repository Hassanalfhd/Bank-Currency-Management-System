#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include"clsUser.h"

class clsCalcultorCurrencyScreen : protected clsScreen
{
	static float _ReadAmount()
	{
		cout<<"\n\nEnter Amount to Exchang: ";
			float Amount = clsInputValidate::ReadFloateNumber();
		return Amount ;
	}


	static void _PrintCurrencyRecord(clsCurrency Currency , string Messag = "\nCard: ")
	{
		cout<<Messag;
		cout<<"\n========================================================\n";
		cout<<"\nCountry		: "<<Currency.Country();
		cout<<"\nCurrencyCode	: "<<Currency.CurrencyCode();
		cout<<"\nCurrencyName	: "<<Currency.CurrencyName();
		cout<<"\nRate ($1) =     : "<<Currency.Rate();
		cout<<"\n========================================================\n";
	
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
	
	static void _PrintCalculationResult(float Amount , clsCurrency CurrencyFrom, clsCurrency CurrencyTo )
	{
		float AmountRate = CurrencyFrom.ConvertToUSD(Amount);

		_PrintCurrencyRecord(CurrencyFrom , "\n\nConvert From: ");

		cout<<Amount<<" "<<CurrencyFrom.CurrencyCode()<<" = "<<AmountRate<<" USD";

		if(CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout<<"\n\nConvering USD to: ";

		_PrintCurrencyRecord(CurrencyTo , "\n\nTo: ");
		
		float Currency2AmountRate = CurrencyFrom.ConvertFromCurrencyToCurrency(Amount , CurrencyTo);
		
		cout<<Amount<<" "<<CurrencyFrom.CurrencyCode()<<" = "<<Currency2AmountRate<<" "<<CurrencyTo.CurrencyCode();

	}


public:

	static void ShowCalcultorCurrencyScreen()
	{
			char Anser = 'Y' ;

		while (clsString::UpperCase(Anser) == 'Y')
		{
				
				system("cls");
			_DrawScreenHeader(" Currency Exchange  Menue ");

			
			clsCurrency CurrencyFrom = _GetCurrecy("\n\nPlease Enter Currency1 Code: ");
		
			clsCurrency CurrencyTo = _GetCurrecy("\n\nPlease Enter Currency2 Code: ");
			
			float Amount = _ReadAmount();
			

			
			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);


				cout<<"\n\n\nDo you want to perform another calculation [Y/N]:    ";
				cin>>Anser;

		} 
		
		
	
	}

};

